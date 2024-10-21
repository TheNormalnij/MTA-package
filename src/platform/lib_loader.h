// ml_package, Native lua package system
// See LICENSE in the top level directory

#pragma once

#include "include/lua.hpp"

#if defined(__x86_64__) || defined(_M_X64)
#define DIR_PREFIX "x64"
#else
#define DIR_PREFIX "x86"
#endif

#if defined(_WIN32)
/*
** In Windows, any exclamation mark ('!') in the path is replaced by the
** path of the directory of the executable file of the current process.
*/
#define MTA_RESOURCES_PATH "!\\mods\\deathmatch\\resources\\"
#define MTA_UNPACKED_RESOURCES_PATH "!\\mods\\deathmatch\\resource-cache\\unzipped\\"
#define MTA_LUA_LDIR "!\\mods\\deathmatch\\lua\\"
#define MTA_LUA_CDIR "!\\mods\\deathmatch\\clua\\" DIR_PREFIX "\\"
#define MTA_LUA_PATH_DEFAULT                                                                                     \
    MTA_LUA_LDIR "server\\?.lua;" MTA_LUA_LDIR "server\\?\\init.lua;" MTA_LUA_LDIR "shared\\?.lua;" MTA_LUA_LDIR \
                 "shared\\?\\init.lua;" MTA_LUA_CDIR "?.lua;" MTA_LUA_CDIR "?\\init.lua;" MTA_RESOURCES_PATH "?.lua"
#define MTA_LUA_CPATH_DEFAULT ".\\?.dll;" MTA_LUA_CDIR "?.dll;" MTA_LUA_CDIR "loadall.dll"

#else
#define MTA_RESOURCES_PATH "./mods/deathmatch/resources/"
#define MTA_UNPACKED_RESOURCES_PATH "./mods/deathmatch/resource-cache/unzipped/"
#define MTA_LUA_LDIR "./mods/deathmatch/lua/"
#define MTA_LUA_CDIR "./mods/deathmatch/clua/" DIR_PREFIX "/"
#define MTA_LUA_PATH_DEFAULT                                                                                 \
    MTA_LUA_LDIR "server/?.lua;" MTA_LUA_LDIR "server/?/init.lua;" MTA_LUA_LDIR "shared/?.lua;" MTA_LUA_LDIR \
                 "shared/?/init.lua;" MTA_LUA_CDIR "?.lua;" MTA_LUA_CDIR "?/init.lua;" MTA_RESOURCES_PATH "?.lua"
#define MTA_LUA_CPATH_DEFAULT "./?.so;" MTA_LUA_CDIR "?.so;" MTA_LUA_CDIR "loadall.so"
#endif

void ll_unloadlib(void* lib);

void* ll_load(lua_State* L, const char* path);

lua_CFunction ll_sym(lua_State* L, void* lib, const char* sym);

void ll_prepare();
