/*********************************************************
*
*  Multi Theft Auto: San Andreas - Deathmatch
*
*  ml_package, Native lua package system
*
*  Copyright (c) 2003-2008 MTA.  All Rights Reserved.
*
*  Grand Theft Auto is (c) 2002-2003 Rockstar North
*
*  THE FOLLOWING SOURCES ARE PART OF THE MULTI THEFT
*  AUTO SOFTWARE DEVELOPMENT KIT AND ARE RELEASED AS
*  OPEN SOURCE FILES. THESE FILES MAY BE USED AS LONG
*  AS THE DEVELOPER AGREES TO THE LICENSE THAT IS
*  PROVIDED WITH THIS PACKAGE.
*
*********************************************************/

#include "CFunctions.h"
#include "luapackage.h"

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
#define MTA_LUA_LDIR	"!\\mods\\deathmatch\\lua\\"
#define MTA_LUA_CDIR	"!\\mods\\deathmatch\\clua\\" DIR_PREFIX "\\"
#define MTA_LUA_PATH_DEFAULT  \
		    MTA_LUA_LDIR"server\\?.lua;"  MTA_LUA_LDIR"server\\?\\init.lua;" \
            MTA_LUA_LDIR"shared\\?.lua;"  MTA_LUA_LDIR"shared\\?\\init.lua;" \
		    MTA_LUA_CDIR"?.lua;"  MTA_LUA_CDIR"?\\init.lua"
#define MTA_LUA_CPATH_DEFAULT \
	".\\?.dll;"  MTA_LUA_CDIR"?.dll;" MTA_LUA_CDIR"loadall.dll"

#else
#define MTA_LUA_LDIR	"./mods/deathmatch/lua/"
#define MTA_LUA_CDIR	"./mods/deathmatch/clua/" DIR_PREFIX "/"
#define MTA_LUA_PATH_DEFAULT  \
		    MTA_LUA_LDIR"server/?.lua;"  MTA_LUA_LDIR"server/?/init.lua;" \
            MTA_LUA_LDIR"shared/?.lua;"  MTA_LUA_LDIR"shared/?/init.lua;" \
		    MTA_LUA_CDIR"?.lua;"  MTA_LUA_CDIR"?/init.lua"
#define MTA_LUA_CPATH_DEFAULT \
	"./?.so;"  MTA_LUA_CDIR"?.so;" MTA_LUA_CDIR"loadall.so"
#endif

int CFunctions::initLuaPackage(lua_State* luaVM) {
    if (luaVM) {
        luaopen_package(luaVM);
        setpath(luaVM, "path", MTA_LUA_PATH_DEFAULT);
        setpath(luaVM, "cpath", MTA_LUA_CPATH_DEFAULT);
        lua_pushboolean(luaVM, true);
        return 1;
    }
    lua_pushboolean(luaVM, false);
    return 1;
}
