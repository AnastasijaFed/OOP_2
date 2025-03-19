cmake_minimum_required(VERSION 3.30)
project(OOP_1uzd)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include_directories(.)

add_executable(OOP_1uzd
    functions.cpp
    functions.h
    Student.cpp
    Student.h
    StudentDeque.cpp
    StudentDeque.h
    StudentList.cpp
    StudentList.h)
