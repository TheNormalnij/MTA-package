
$LuarocksVersion = "3.11.1"

$LuarocksPath = Join-Path "$PSScriptRoot" "luarocks"
$luarocksMainConfig = Join-Path "$LuarocksPath" "config.lua"
$LuaPath = Join-Path $LuarocksPath "lua"

$DownloadRepo = 'https://github.com/TheNormalnij/MTA-package/raw/refs/heads/master/'

$PathBefore = $env:Path

$env:Path=""

function CreateDirIfNotExists {
    param (
        [string]$Path
    )

    if (-not (Test-Path $Path)) {
        New-Item -Path $Path -ItemType Directory
    }
}

function Setup-Build-System {
    $env:VCINSTALLDIR = 'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\'
    $env:Path += ';C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin'
}

function Install-LuaRocks {
    $ZipUrl = "https://luarocks.org/releases/luarocks-$LuarocksVersion-windows-64.zip"

    # Check if luarocks exists
    $luarocksExePath = Join-Path $LuarocksPath "luarocks.exe"
    if (-not (Test-Path $luarocksExePath)) {
        Write-Host "Downloading and installing LuaRocks..."
        
        CreateDirIfNotExists $LuarocksPath

        # Download zip file
        $zipFile = "$env:TEMP\luarocks.zip"
        Invoke-WebRequest -Uri $ZipUrl -OutFile $zipFile
        
        # Extract zip file
        $extractedZip = "$env:TEMP\luarocks"
        Expand-Archive -Path $zipFile -DestinationPath $extractedZip

        Copy-Item "$extractedZip\luarocks-$LuarocksVersion-windows-64\luarocks.exe" $luarocksExePath
        
        # Clean up temporary zip file
        Remove-Item $zipFile
        Remove-Item -Recurse $extractedZip
    
        Write-Host "LuaRocks installed successfully."
    }
}

function Install-Lua {
    $ZipUrl = "https://deac-riga.dl.sourceforge.net/project/luabinaries/5.1.4/Tools%20Executables/lua5_1_4_Win64_bin.zip?viasf=1"

    $LuaExePath = Join-Path $LuaPath "lua5.1.exe"

    if (-not (Test-Path $LuaExePath)) {
        Write-Host "Downloading and installing Lua..."
        
        # Download zip file
        $zipFile = "$env:TEMP\lua.zip"
        Invoke-WebRequest -Uri $ZipUrl -OutFile $zipFile
        
        # Extract zip file
        Expand-Archive -Path $zipFile -DestinationPath $LuaPath

        
        # Clean up temporary zip file
        Remove-Item $zipFile
    
        Write-Host "Lua installed successfully."
    }
}


function Setup-LuaRocks-Configs {
    if (-not (Test-Path $luarocksMainConfig)) {
        $PWD_ESPACED = $PWD.Path.Replace('\', '\\')
        $PWD_UNIX = $PWD.Path.Replace('\', '/')

$LUAROCKS_CONFIG = @"
arch = "win32"
lua_version = "5.1"
cmake_generator = "Visual Studio 17 2022\" -A \"Win32"
rocks_trees = {
   {
      name = "user",
      root = "$PWD_ESPACED\\luarocks",
      lib_dir = "$PWD_ESPACED\\server\\mods\\deathmatch\\clua\\x86",
      bin_dir = "$PWD_ESPACED\\server\\mods\\deathmatch\\bin",
      lua_dir = "$PWD_ESPACED\\server\\mods\\deathmatch\\lua\\server",
   }
}
variables = {
   LUA_LIBDIR="$PWD_UNIX/luarocks/lualib",
   LUA_INCDIR="$PWD_ESPACED\\luarocks\\luainc"
}
"@
        New-Item -Path $luarocksMainConfig -ItemType File -Value $LUAROCKS_CONFIG
    }
}

function DownloadFileIfNotExists {
    param (
        [string]$RemotePath,
        [string]$FilePath
    )

    if (-not (Test-Path $FilePath)) {
        Invoke-WebRequest -Uri $RemotePath -OutFile $FilePath
    }
}

Install-LuaRocks
Install-Lua
Setup-LuaRocks-Configs
Setup-Build-System

CreateDirIfNotExists("$LuarocksPath\lualib")
CreateDirIfNotExists("$LuarocksPath\luainc")

DownloadFileIfNotExists -FilePath "$LuarocksPath\lualib\lua5.1.lib" -RemotePath "$DownloadRepo/lib/lua5.1.lib"
DownloadFileIfNotExists -FilePath "$LuarocksPath\lualib\lua5.1_64.lib" -RemotePath "$DownloadRepo/lib/lua5.1_64.lib"
DownloadFileIfNotExists -FilePath "$LuarocksPath\luainc\lua.h" -RemotePath "$DownloadRepo/src/include/lua.h"
DownloadFileIfNotExists -FilePath "$LuarocksPath\luainc\lua.hpp" -RemotePath "$DownloadRepo/src/include/lua.hpp"
DownloadFileIfNotExists -FilePath "$LuarocksPath\luainc\lauxlib.h" -RemotePath "$DownloadRepo/src/include/lauxlib.h"
DownloadFileIfNotExists -FilePath "$LuarocksPath\luainc\luaconf.h" -RemotePath "$DownloadRepo/src/include/luaconf.h"
DownloadFileIfNotExists -FilePath "$LuarocksPath\luainc\lualib.h" -RemotePath "$DownloadRepo/src/include/lualib.h"

$env:Path += ";$LuaPath"
$env:LUA_INCDIR = "$LuarocksPath\\luainc"
$env:LUA_LIBDIR = "$LuarocksPath\\lualib"
$env:LUAROCKS_CONFIG = "$luarocksMainConfig"

.\luarocks\luarocks.exe $args

$env:Path = $PathBefore
