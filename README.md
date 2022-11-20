# Building

## Linux
1. Run `make` to build module.
2. Builded module will be in the `./bin` directory

## Windows
1. Open project in Visual Studio (2022 preferred)
2. Compile module
3. Builded DLL will be in the `.\bin\x64` or `.\bin\Win32` directory

# Installation

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