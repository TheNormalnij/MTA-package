cmake_minimum_required(VERSION 3.25)

project(MlPackage)

set(CMAKE_CXX_STANDARD 20)

message("vuild type is ${CMAKE_BUILD_TYPE} ${CMAKE_INSTALL_PREFIX}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

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
    list(APPEND COMPILE_DEFINITIONS $<$<CONFIG:Debug>:_DEBUG>)

    list(APPEND COMPILE_OPTIONS
        -Wall
        -Wextra
        -Wpedantic
        -Werror
    )
endif()


add_subdirectory(vendor)
add_subdirectory(src)

install(
    TARGETS MlPackage
    RENAME ml_package
    RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
)
