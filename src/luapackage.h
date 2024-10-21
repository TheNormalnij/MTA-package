// ml_package, Native lua package system
// See LICENSE in the top level directory

#pragma once

#include "./include/lua.hpp"

void setpath(lua_State* L, const char* fieldname, const char* path);
void ll_prepare();
