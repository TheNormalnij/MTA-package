

#if defined(__x86_64__) || defined(_M_X64)
    #define MODULE_DIR_PREFIX "x64"
#else
    #define MODULE_DIR_PREFIX "x86"
#endif

#undef LUA_LDIR
#undef LUA_CDIR
#undef LUA_PATH_DEFAULT
#undef LUA_CPATH_DEFAULT

#if defined(_WIN32)
    /*
    ** In Windows, any exclamation mark ('!') in the path is replaced by the
    ** path of the directory of the executable file of the current process.
    */
    #define LUA_LDIR "!\\mods\\deathmatch\\lua\\"
    #define LUA_CDIR "!\\mods\\deathmatch\\clua\\" MODULE_DIR_PREFIX "\\"
    #define LUA_PATH_DEFAULT \
        LUA_LDIR "server\\?.lua;" LUA_LDIR "server\\?\\init.lua;" LUA_LDIR "shared\\?.lua;" LUA_LDIR "shared\\?\\init.lua;" LUA_CDIR "?.lua;" LUA_CDIR "?\\init.lua"
    #define LUA_CPATH_DEFAULT \
        ".\\?.dll;" LUA_CDIR "?.dll;" LUA_CDIR "loadall.dll"

#else
#define LUA_LDIR "./mods/deathmatch/lua/"
#define LUA_CDIR "./mods/deathmatch/clua/" MODULE_DIR_PREFIX "/"
#define LUA_PATH_DEFAULT \
    LUA_LDIR "server/?.lua;" LUA_LDIR "server/?/init.lua;" LUA_LDIR "shared/?.lua;" LUA_LDIR "shared/?/init.lua;" LUA_CDIR "?.lua;" LUA_CDIR "?/init.lua"
#define LUA_CPATH_DEFAULT \
    "./?.so;" LUA_CDIR "?.so;" LUA_CDIR "loadall.so"
#endif
