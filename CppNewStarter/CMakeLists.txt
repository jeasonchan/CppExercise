cmake_minimum_required(VERSION 3.16)
project(CppNewStarter)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppNewStarter bean/person.cpp bean/person.h bean/student.cpp bean/student.h bean/util.cpp bean/util.h bean/util2.cpp bean/util2.h test_left_right_value/main.cpp )
add_executable(CppNewStarter2  bean/person.cpp bean/person.h bean/student.cpp bean/student.h bean/util.cpp bean/util.h bean/util2.cpp bean/util2.h test_left_right_value/main2.cpp )

add_executable(test_smart_pointer test_smart_pointer/Main.cpp test_smart_pointer/sharePtr.hpp)

add_executable(test_stl test_stl/Main.cpp)

add_executable(test_new test_new/Main.cpp)
add_executable(chapter3 follow_cpp_primer_5th/chapter3/Main.cpp)
add_executable(test_2D_array test_2D_array/Main.cpp)