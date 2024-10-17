#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

if [ ! -f $SCRIPT_DIR/mta-server64 ]; then
    ARCH=x86_64
fi

if [ ! -f $SCRIPT_DIR/mta-server ]; then
    ARCH=x86
fi

if [ ! $ARCH ]; then
    echo "Can not found MTA server";
    exit 1;
fi

if [ ! -d $SCRIPT_DIR/luarocks ]; then
	mkdir $SCRIPT_DIR/luarocks
fi

if [ ! -f $SCRIPT_DIR/luarocks/conf.lua ]; then
echo "arch = '$ARCH'
lua_version = '5.1'
rocks_trees = {
   {
      name = 'user',
      root = '$SCRIPT_DIR/luarocks/tree',
      lib_dir = '$SCRIPT_DIR/mods/deathmatch/clua/x64',
      bin_dir = '$SCRIPT_DIR/mods/deathmatch/lua/bin',
      lua_dir = '$SCRIPT_DIR/mods/deathmatch/lua/server',
   }
}" > $SCRIPT_DIR/luarocks/conf.lua
fi

LUAROCKS_CONFIG=$SCRIPT_DIR/luarocks/conf.lua luarocks $@
