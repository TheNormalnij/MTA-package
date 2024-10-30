# Building

## Linux
```bash
cmake -B ./build ./
cmake --build ./build
```

## Windows
For x86 MTA server:
```bat
cmake -A Win32 . -B build
cmake --build build --config Release
```

for x64 MTA server:
```bat
cmake -A x64 . -B build
cmake --build build --config Release
```

# Installation

You can get prebuilded packages on [GitHub releases page](https://github.com/TheNormalnij/MTA-package/releases)

## Windows

* 32 bit: Copy 32 bit `ml_package.dll` into the `MTA San Andreas\server\mods\deathmatch\modules\` directory.
* 64 bit: Copy 64 bit `ml_package.dll` into the `MTA San Andreas\server\x64\modules\` directory.

Then, add the following line in `mtaserver.conf`:

```xml
  <module src="ml_package.dll" />
```
## GNU/Linux

* 32 bit: Copy 32 bit ml_package.so into the `mods/deathmatch/modules/` directory.
* 64 bit: Copy 64 bit ml_package.so into the `x64/modules/` directory.

Then, add the following line in `mtaserver.conf`:

```xml
  <module src="ml_package.so" />
```

# Usage

```lua
-- You can use absolute path for require function
-- The module start searching from 'mods/deathmatch/resources' folder
local module = require "folder1.folder2.resourceName.resourceFile"

-- Relative path is supported too. It starts with ":"
local module = require ":resourceName.resourceFile"

-- You can use "mods/deathmatch/lua/server" folder for shared code
local fooModule = require "mysmalllib"
local barModule = require "mylib.libfile"
```

# LuaRocks integration

[LuaRocks](https://luarocks.org/) has some usefull native modules for Lua. `require` supports native modules.

## Linux

1. Install Lua and luarocks
```sh
sudo apt install luarocks lua5.1
```

2. Copy `scripts/luarocks.sh` from this repository to your MTA server forlder.

3. Now you can use `luarocks.sh` to build native modules
```sh
./luarocks.sh install rapidjson
```

```lua
local rapidjson = require "rapidjson"
```

## Windows x86 only

1. Install Visual Studio and CMake via Visual Studio Installer
2. Copy `scripts/luarocks.ps1` from this repository to your MTA server forlder.

3. Now you can use `luarocks.ps1` to build native modules with using powerschell console
```powershell
.\luarocks.ps1 install rapidjson
```
