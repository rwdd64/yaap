cmake_minimum_required(VERSION 3.16)
project(yaap)

add_library(${PROJECT_NAME} STATIC ${PROJECT_NAME}.c)
target_include_directories(${PROJECT_NAME}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

string(TOLOWER "${CMAKE_BUILD_TYPE}" build_type)
if (build_type STREQUAL "debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG)
endif()

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
