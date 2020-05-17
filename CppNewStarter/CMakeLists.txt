cmake_minimum_required(VERSION 3.16)
project(CppNewStarter)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppNewStarter main.cpp bean/person.cpp bean/person.h bean/student.cpp bean/student.h)