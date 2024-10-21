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
#include <unordered_map>
#include "include/Common.h"
#include "include/ILuaModuleManager.h"
#include "platform/luaimports.h"

#include <string.h>
#include "luapackage.h"
#include "resource_path_store.h"

ILuaModuleManager10* pModuleManager = nullptr;
std::unordered_map<lua_State*, std::string> resourcesByVm{};

MTAEXPORT bool InitModule(ILuaModuleManager10* pManager, char* szModuleName, char* szAuthor, float* fVersion) {
    pModuleManager = pManager;

    strncpy(szModuleName, MODULE_NAME, MAX_INFO_LENGTH);
    strncpy(szAuthor, MODULE_AUTHOR, MAX_INFO_LENGTH);
    *fVersion = MODULE_VERSION;

    ll_prepare();
    return ImportLua();
}

MTAEXPORT void RegisterFunctions(lua_State* luaVM) {
    // Get resource path
    lua_getglobal(luaVM, "getResourceName");
    lua_getglobal(luaVM, "resource");
    lua_call(luaVM, 1, 1);

    auto resourceName = std::string{lua_tostring(luaVM, -1)};
    lua_pop(luaVM, -1);

    lua_getglobal(luaVM, "isResourceArchived");
    lua_getglobal(luaVM, "resource");
    lua_call(luaVM, 1, 1);

    bool isArchived = lua_toboolean(luaVM, -1);
    lua_pop(luaVM, -1);

    if (isArchived) {
        ResourcePathStore::addResource(resourceName, ResourcePathStore::RESOURCE_PATH_ARCHIVED);
    } else {
        lua_getglobal(luaVM, "getResourceOrganizationalPath");
        lua_getglobal(luaVM, "resource");
        lua_call(luaVM, 1, 1);

        const char* resourcePath = lua_tostring(luaVM, -1);
        lua_pop(luaVM, -1);

        ResourcePathStore::addResource(resourceName, resourcePath);
    }

    resourcesByVm[luaVM] = resourceName;

    // Add require
    lua_pushcfunction(luaVM, luaopen_package);
    lua_pushstring(luaVM, LUA_LOADLIBNAME);
    lua_call(luaVM, 1, 0);
}

MTAEXPORT bool DoPulse() {
    return true;
}

MTAEXPORT bool ResourceStopped([[maybe_unused]] lua_State* luaVM) {
    ResourcePathStore::removeResource(resourcesByVm[luaVM]);
    resourcesByVm.erase(luaVM);
    return true;
}

MTAEXPORT bool ShutdownModule() {
    return true;
}
