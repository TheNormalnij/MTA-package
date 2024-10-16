cmake_minimum_required(VERSION 3.20)

project(MlPackage VERSION 3.0 LANGUAGES CXX)

add_library(MlPackage SHARED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

if ( MSVC )
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif ( MSVC )

if(MSVC)
    set(COMPILE_OPTIONS
        $<$<CONFIG:Release>:/Zi /W3 /O2 /MP>
        $<$<CONFIG:Debug>:/Zi /W3 /Od /GF /Gm- /RTCc /RTC1 /MP>
    )
    set(LINK_OPTIONS
        /SUBSYSTEM:WINDOWS /DYNAMICBASE:NO
        $<$<CONFIG:Release>:/INCREMENTAL:NO /OPT:REF /OPT:ICF>
        $<$<CONFIG:Debug>:/INCREMENTAL /DEBUG>
    )
else()
    set(COMPILE_OPTIONS
        $<$<CONFIG:Release>:-O3>
        $<$<CONFIG:Debug>:-g>
    )

    list(APPEND COMPILE_DEFINITIONS $<$<CONFIG:Debug>:_DEBUG>)

    list(APPEND COMPILE_OPTIONS
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -fPIC
    )
endif()

file(GLOB_RECURSE INCLUDE_FILES ./include/*)
file(GLOB_RECURSE SOURCE_FILES ./src/*)

target_sources(
    MlPackage
    PUBLIC
        ${INCLUDE_FILES}
        ${SOURCE_FILES}
)

target_include_directories(
    MlPackage
    PUBLIC
        src
        include
)

target_compile_definitions(
    MlPackage
    PUBLIC
        LUA_USE_DLOPEN)

target_compile_options(MlPackage PRIVATE ${COMPILE_OPTIONS})
target_compile_definitions(MlPackage PRIVATE ${COMPILE_DEFINITIONS} _ALLOW_RTCc_IN_STL)

set_target_properties(MlPackage PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(MlPackage PROPERTIES OUTPUT_NAME "ml_package")
set_target_properties(MlPackage PROPERTIES PREFIX "")
