cmake_minimum_required(VERSION 3.16)
project(example)

add_executable(${PROJECT_NAME} main.c)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/../build/lib/libyaap.a")
