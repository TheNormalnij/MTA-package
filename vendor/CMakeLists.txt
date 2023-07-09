add_library(LuaLib STATIC)

file(GLOB LUA_SOURCES ./lua-5.1.5/*.c)
file(GLOB LUA_HEADERS ./lua-5.1.5/*.h)

target_sources(
    LuaLib
    PRIVATE
        ${LUA_SOURCES} ${LUA_HEADERS}
)

target_include_directories(
    LuaLib
    PUBLIC
        lua-5.1.5
)

if(MSVC)
    source_group("Lua\\Source Files" FILES ${LUA_SOURCES})
    source_group("Lua\\Header Files" FILES ${LUA_HEADERS})
else()
    list(APPEND COMPILE_DEFINITIONS $<$<CONFIG:Debug>:_DEBUG>)
endif()

target_compile_options(LuaLib PRIVATE ${COMPILE_OPTIONS} -Wno-misleading-indentation -Wno-implicit-fallthrough)
target_compile_definitions(LuaLib PRIVATE ${COMPILE_DEFINITIONS} _ALLOW_RTCc_IN_STL _CRT_SECURE_NO_WARNINGS)
