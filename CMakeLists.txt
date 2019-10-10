cmake_minimum_required(VERSION 3.13)
project(data-and-algo)

set(CMAKE_CXX_STANDARD 14)
set(ROOT /Users/tiffanys_mac/Documents/Projects)



include_directories(${ROOT}/googletest/googletest/include/)
link_directories(${ROOT}/googletest/ ${ROOT}/googletest/build/lib/)
add_executable(data-and-algo main.cpp dlinkedlist.h recursion.h dlinkedlist.cpp)

target_link_libraries(data-and-algo gtest gtest_main)