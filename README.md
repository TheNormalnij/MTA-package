# Building

## Linux x64
1. Run commands
```sh
cmake . -B build -D CMAKE_BUILD_TYPE=Release
cmake  --build build --config Release
```
2. Builded module will be in the `./bin` directory

## Windows
1. Run commands
```sh
cmake -A Win32 . -B build
cmake --build build --config ${{ matrix.build_type }}
```
1. Builded DLL will be in the `.\bin` directory

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