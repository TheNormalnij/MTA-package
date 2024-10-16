/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        publicsdk/include/ILuaModuleManager.h
*  PURPOSE:     Lua dynamic module interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

// INTERFACE for Lua dynamic modules

#pragma once

#include "lua.hpp"
#include <string>

constexpr auto MAX_INFO_LENGTH = 128;

struct SChecksum {
    unsigned long ulCRC;
    unsigned char mD5[16];
};

/* Interface for modules until DP2.3 */
class ILuaModuleManager {
public:
    virtual void ErrorPrintf(const char* szFormat, ...) = 0;
    virtual void DebugPrintf(lua_State* luaVM, const char* szFormat, ...) = 0;
    virtual void Printf(const char* szFormat, ...) = 0;

    virtual bool RegisterFunction(lua_State* luaVM, const char* szFunctionName, lua_CFunction Func) = 0;
    virtual bool GetResourceName(lua_State* luaVM, std::string& strName) = 0;
    virtual SChecksum GetResourceMetaChecksum(lua_State* luaVM) = 0;
    virtual SChecksum GetResourceFileChecksum(lua_State* luaVM, const char* szFile) = 0;
};

/* Interface for modules until 1.0 */
class ILuaModuleManager10 : public ILuaModuleManager {
public:
    virtual unsigned long GetVersion() = 0;
    virtual const char* GetVersionString() = 0;
    virtual const char* GetVersionName() = 0;
    virtual unsigned long GetNetcodeVersion() = 0;
    virtual const char* GetOperatingSystemName() = 0;

    virtual lua_State* GetResourceFromName(const char* szResourceName) = 0;
};
