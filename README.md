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
