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

#pragma once

#include <cstdio>
#include <map>
#include <variant>

#include "include/ILuaModuleManager.h"
#include "include/Common.h"

extern ILuaModuleManager10* pModuleManager;

class CFunctions {
public:
    static int initLuaPackage(lua_State* luaVM);
};
