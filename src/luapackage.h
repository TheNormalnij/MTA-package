
#pragma once

#include "./include/lua.hpp"

void setpath(lua_State* L, const char* fieldname, const char* path);
void ll_prepare();
