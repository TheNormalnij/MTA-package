// ml_package, Native lua package system
// See LICENSE in the top level directory

#include "../lib_loader.h"
#include <windows.h>

#undef setprogdir

static void setprogdir(lua_State* L) {
    char buff[MAX_PATH + 1];
    char* lb;
    DWORD nsize = sizeof(buff) / sizeof(char);
    DWORD n = GetModuleFileNameA(NULL, buff, nsize);
    if (n == 0 || n == nsize || (lb = strrchr(buff, '\\')) == NULL)
        luaL_error(L, "unable to get ModuleFileName");
    else {
        *lb = '\0';
        luaL_gsub(L, lua_tostring(L, -1), LUA_EXECDIR, buff);
        lua_remove(L, -2); /* remove original string */
    }
}

static void pusherror(lua_State* L) {
    int error = GetLastError();
    char buffer[128];
    if (FormatMessageA(FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM, NULL, error, 0, buffer,
                       sizeof(buffer), NULL))
        lua_pushstring(L, buffer);
    else
        lua_pushfstring(L, "system error %d\n", error);
}

static void ll_unloadlib(void* lib) {
    FreeLibrary((HINSTANCE)lib);
}

static void* ll_load(lua_State* L, const char* path) {
    HINSTANCE lib = LoadLibraryA(path);
    if (lib == NULL)
        pusherror(L);
    return lib;
}

static lua_CFunction ll_sym(lua_State* L, void* lib, const char* sym) {
    lua_CFunction f = (lua_CFunction)GetProcAddress((HINSTANCE)lib, sym);
    if (f == NULL)
        pusherror(L);
    return f;
}

void ll_prepare() {
    // empty
}
