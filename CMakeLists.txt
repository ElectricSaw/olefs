cmake_minimum_required(VERSION 3.21)
project(olefs)

set(CMAKE_CXX_STANDARD 14)

add_executable(olefs src/main.cpp src/types.h src/rbtree.h src/dumper.h src/dumper.cpp)
