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

#include "ml_package.hpp"
#include "include/Common.h"
#include "include/ILuaModuleManager.h"

#include "CFunctions.h"
#include "luapackage.h"
#include <string.h>

#ifdef __linux__
#include "platform/linux/luaimports.h"
#endif

ILuaModuleManager10* pModuleManager = nullptr;

MTAEXPORT bool InitModule(ILuaModuleManager10* pManager, char* szModuleName, char* szAuthor, float* fVersion) {
	pModuleManager = pManager;

	strncpy(szModuleName, MODULE_NAME, MAX_INFO_LENGTH);
	strncpy(szAuthor, MODULE_AUTHOR, MAX_INFO_LENGTH);

	*fVersion = MODULE_VERSION;

    ll_prepare();
#ifdef __linux__
	return ImportLua();
#elif
    return true;
#endif
}

MTAEXPORT void RegisterFunctions(lua_State* luaVM) {
	if (pModuleManager && luaVM) {
		pModuleManager->RegisterFunction(luaVM, "initLuaPackage", CFunctions::initLuaPackage);
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
