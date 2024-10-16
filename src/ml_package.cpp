/*********************************************************
*
*  Multi Theft Auto: San Andreas - Deathmatch
*
*  ml_package, Native lua package system
*
*  Copyright © 2003-2008 MTA.  All Rights Reserved.
*
*  Grand Theft Auto is © 2002-2003 Rockstar North
*
*  THE FOLLOWING SOURCES ARE PART OF THE MULTI THEFT
*  AUTO SOFTWARE DEVELOPMENT KIT AND ARE RELEASED AS
*  OPEN SOURCE FILES. THESE FILES MAY BE USED AS LONG
*  AS THE DEVELOPER AGREES TO THE LICENSE THAT IS
*  PROVIDED WITH THIS PACKAGE.
*
*********************************************************/

#include "ml_package.hpp"
#include "CFunctions.h"
#include "luaimports.h"
#include <string.h>

ILuaModuleManager10* pModuleManager = NULL;
bool ms_bInitWorked = false;

MTAEXPORT bool InitModule(ILuaModuleManager10* pManager, char* szModuleName, char* szAuthor, float* fVersion) {
	pModuleManager = pManager;

	strncpy(szModuleName, MODULE_NAME, MAX_INFO_LENGTH);
	strncpy(szAuthor, MODULE_AUTHOR, MAX_INFO_LENGTH);

	*fVersion = MODULE_VERSION;

	ms_bInitWorked = true;

	return ImportLua();
}

MTAEXPORT void RegisterFunctions(lua_State* luaVM) {
	if (!ms_bInitWorked) return;

	if (pModuleManager && luaVM) {
		pModuleManager->RegisterFunction(luaVM, "initLuaPackage", CFunctions::initLuaPackage);
	}
}

MTAEXPORT bool DoPulse() {
	return true;
}

MTAEXPORT bool ResourceStopped(lua_State* luaVM) {
	return true;
}

MTAEXPORT bool ShutdownModule() {
	return true;
}
