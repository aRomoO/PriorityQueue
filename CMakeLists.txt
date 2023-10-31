cmake_minimum_required(VERSION 3.26)
project(PriorityQueue)

set(CMAKE_CXX_STANDARD 17)

add_executable(PriorityQueue main.cpp
        MyHeap.cpp
        MyHeap.h)
