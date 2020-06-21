cmake_minimum_required(VERSION 3.16)
project(CppNewStarter)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppNewStarter main.cpp bean/person.cpp bean/person.h bean/student.cpp bean/student.h bean/util.cpp bean/util.h bean/util2.cpp bean/util2.h 试验左值右值/main.cpp 试验左值右值/main2.cpp)