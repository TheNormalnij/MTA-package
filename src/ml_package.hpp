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

#pragma once

// Disable Visual Studio warnings
#ifdef _WIN32
#   pragma warning(disable: 4267) // DISABLE: conversion from 'size_t' to 'int', possible loss of data
#   pragma warning(disable: 4996) // DISABLE: 'strcpy': This function or variable may be unsafe.
#endif

/** MODULE SPECIFIC INFORMATION **/

#define MODULE_NAME "Lua package module"
#define	MODULE_AUTHOR "TheNormalnij"
#define MODULE_VERSION 1.0f

// Include default MTA module SDK includes
#include "Common.h"
#include "ILuaModuleManager.h"
