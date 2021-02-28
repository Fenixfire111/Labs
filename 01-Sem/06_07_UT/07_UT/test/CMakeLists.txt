cmake_minimum_required(VERSION 3.17)
project(07_UT1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_subdirectory(src)
include_directories(src)

file(GLOB tests "test/*.cpp")

add_executable(07_UT1 ${tests})
#add_executable(07_UT1 main.cpp)
target_link_libraries(07_UT1 src gtest gtest_main)