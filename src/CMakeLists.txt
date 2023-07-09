add_library(MlPackage SHARED)

file(GLOB ML_SOURCES ./*.cpp)
file(GLOB ML_HEADERS ./*.hpp ./*.h)
file(GLOB MTA_HEADERS ../include/*.h)

target_sources(
    MlPackage
    PRIVATE
        ${MTA_HEADERS}
        ${ML_SOURCES} ${ML_HEADERS}
)

target_link_libraries(
    MlPackage
    PUBLIC
        LuaLib
)

if(MSVC)
    source_group("MlPackage\\Source Files" FILES ${ML_SOURCES})
    source_group("MlPackage\\Header Files" FILES ${ML_HEADERS})
else()
    list(APPEND COMPILE_DEFINITIONS $<$<CONFIG:Debug>:_DEBUG>)
endif()

target_compile_options(MlPackage PRIVATE ${COMPILE_OPTIONS})
target_compile_definitions(MlPackage PRIVATE ${COMPILE_DEFINITIONS} _ALLOW_RTCc_IN_STL)
set_target_properties(MlPackage PROPERTIES OUTPUT_NAME "ml_package")
