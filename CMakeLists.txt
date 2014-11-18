cmake_minimum_required(VERSION 2.6)
project (Test)

set (Test_VERSION_MAJOR 0)
set (Test_VERSION_MINOR 1)

set (CMAKE_CXX_FLAGS "-ggdb3 -g3 -Wall")

include_directories(${Test_SOURCE_DIR}/src)
include_directories(${Test_SOURCE_DIR}/include)
#include_directories(/usr/include/c++/4.8.3/)
include_directories(/usr/include/UnitTest++/)


file(GLOB src_files
    "src/*.cpp"
    )

file(GLOB test_files
    "tests/*.cpp"
    )

add_executable(main ${src_files} main.cpp)

add_executable(test ${src_files} ${test_files})
target_link_libraries(test UnitTest++)
