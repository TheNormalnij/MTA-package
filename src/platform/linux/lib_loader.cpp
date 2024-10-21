// ml_package, Native lua package system
// See LICENSE in the top level directory

#include "../lib_loader.h"
#include <dlfcn.h>

void ll_unloadlib(void* lib) {
    dlclose(lib);
}

void* ll_load(lua_State* L, const char* path) {
    void* lib = dlopen(path, RTLD_NOW);
    if (lib == nullptr) {
        lua_pushstring(L, dlerror());
        return nullptr;
    }

    return lib;
}

lua_CFunction ll_sym(lua_State* L, void* lib, const char* sym) {
    lua_CFunction f = (lua_CFunction)dlsym(lib, sym);
    if (f == NULL)
        lua_pushstring(L, dlerror());
    return f;
}

void ll_prepare() {
    void* currentHandle = dlopen(nullptr, RTLD_NOW);

    if (currentHandle == nullptr) {
        return;
    }

    // TODO change with current *.so name
    dlopen("ml_package.so", RTLD_NOW | RTLD_GLOBAL);
}
