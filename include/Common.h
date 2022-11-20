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

extern "C" {
#	include <lua.h>
#	include <lualib.h>
#	include <lauxlib.h>
}

#ifdef _WIN32
#define MTAEXPORT extern "C" __declspec(dllexport)
#else
#define MTAEXPORT extern "C"
#endif

#if defined( _M_X64 ) || defined( __x86_64__ ) || defined( _M_AMD64 )
#define ANY_x64
#ifdef _WIN64
#define WIN_x64
#else
#define LINUX_x64
#endif
#else
#define ANY_x86
#ifdef _WIN32
#define WIN_x86
#else
#define LINUX_x86
#endif
#endif

#include <list>
#include <vector>

#ifndef __COMMON_H
#define __COMMON_H

#define MAX_ARGUMENTS 10 // used in the function argument vector

struct FunctionArguments {
	lua_State* luaVM;
	unsigned char nArguments;
	unsigned char Type[10];
	void* Arguments[10];
};

enum class FunctionArgumentType {
	TYPE_NUMBER = 1,
	TYPE_STRING = 2,
	TYPE_LIGHTUSERDATA = 3,
	TYPE_BOOLEAN = 4,
	TYPE_NIL = 5,
	TYPE_TABLE = 6
};

#endif
