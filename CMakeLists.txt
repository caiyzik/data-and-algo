cmake_minimum_required(VERSION 3.13)
project(data-and-algo)

set(CMAKE_CXX_STANDARD 14)
set(ROOT /Users/tiffanys_mac/Documents/Projects)



include_directories(${ROOT}/googletest/googletest/include/)
link_directories(${ROOT}/googletest/ ${ROOT}/googletest/build/lib/)
#add_executable(data-and-algo leetcode/leet-tests.cpp leetcode/twosums.cpp)
#add_executable(data-and-algo dlinkedlist_tests.cpp dlinkedlist.h dlinkedlist.cpp test.cpp)

add_executable(data-and-algo tree_tests.cpp tree.h tree.cpp)

target_link_libraries(data-and-algo gtest gtest_main)