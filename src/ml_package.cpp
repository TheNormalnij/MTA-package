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

#include "ml_package.h"
#include "include/Common.h"
#include "include/ILuaModuleManager.h"

#include <string.h>
#include "luapackage.h"

#ifdef __linux__
#include "platform/linux/luaimports.h"
#else
#define ImportLua() true
#endif

ILuaModuleManager10* pModuleManager = nullptr;

MTAEXPORT bool InitModule(ILuaModuleManager10* pManager, char* szModuleName, char* szAuthor, float* fVersion) {
    pModuleManager = pManager;

    strncpy(szModuleName, MODULE_NAME, MAX_INFO_LENGTH);
    strncpy(szAuthor, MODULE_AUTHOR, MAX_INFO_LENGTH);

    *fVersion = MODULE_VERSION;

    ll_prepare();
    return ImportLua();
}

MTAEXPORT void RegisterFunctions(lua_State* luaVM) {
    if (pModuleManager && luaVM) {
        lua_pushcfunction(luaVM, luaopen_package);
        lua_pushstring(luaVM, LUA_LOADLIBNAME);
        lua_call(luaVM, 1, 0);
    }
}

MTAEXPORT bool DoPulse() {
    return true;
}

MTAEXPORT bool ResourceStopped([[maybe_unused]] lua_State* luaVM) {
    return true;
}

MTAEXPORT bool ShutdownModule() {
    return true;
}
