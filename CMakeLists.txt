cmake_minimum_required(VERSION 2.6)
project (Test)

set (Test_VERSION_MAJOR 0)
set (Test_VERSION_MINOR 1)

set (CMAKE_CXX_FLAGS "-ggdb3 -g3 -Wall")

include_directories(${Test_SOURCE_DIR}/src)
include_directories(${Test_SOURCE_DIR}/include)
#include_directories(/usr/include/c++/4.8.3/)
#include_directories(/usr/include/)


file(GLOB src_files
    "src/*.cpp"
    )
add_executable(Test ${src_files})
