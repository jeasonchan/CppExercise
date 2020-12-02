cmake_minimum_required(VERSION 3.16)
project(CppNewStarter)

set(CMAKE_CXX_STANDARD 14)

set(WINDOWS true)
if (${WINDOWS})
    set(BOOST_INCLUDEDIR D:\\softwares\\boost_1_73_0\\stage\\lib)
    set(BOOST_LIBRARYDIR D:\\softwares\\boost_1_73_0\\stage\\lib)
endif ()


add_executable(CppNewStarter bean/person.cpp bean/person.h bean/student.cpp bean/student.h bean/util.cpp bean/util.h bean/util2.cpp bean/util2.h test_left_right_value/main.cpp bean/Base.cpp bean/Base.h)
add_executable(CppNewStarter2 bean/person.cpp bean/person.h bean/student.cpp bean/student.h bean/util.cpp bean/util.h bean/util2.cpp bean/util2.h test_left_right_value/main2.cpp)

add_executable(test_smart_pointer test_smart_pointer/Main.cpp test_smart_pointer/sharePtr.hpp)

add_executable(test_stl test_stl/Main.cpp)

add_executable(test_new test_new/Main.cpp)
add_executable(chapter3 follow_cpp_primer_5th/chapter3/Main.cpp)
add_executable(test_2D_array test_2D_array/Main.cpp)
add_executable(test_vector test_vector/Main.cpp)

add_executable(test_boost test_boost/test_boost_avail.cpp)
find_package(Boost REQUIRED)
if (Boost_FOUND)
    message(${Boost_INCLUDE_DIRS})
    #    message(${Boost_LIBRARY_DIRS})

    target_include_directories(test_boost PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_directories(test_boost PRIVATE ${Boost_LIBRARY_DIRS})
    target_link_libraries(test_boost PRIVATE libboost_context.a)
endif ()

add_executable(leetcode2 leetcode2/Main.cpp leetcode2/Solution.hpp)

message(123)