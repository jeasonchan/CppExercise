cmake_minimum_required(VERSION 3.16)

project(CppNewStarter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(WINDOWS false)
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

add_executable(leetcode4 leetcode4/Main.cpp leetcode4/Solution.hpp)

message(123)


add_executable(leetcode347 leetcode347/Main.cpp)

add_executable(revert_list_in_place revert_list_in_place/Main.cpp revert_list_in_place/Solution.hpp)
add_executable(binary_tree_print binary_tree_print/Main.cpp binary_tree_print/Solution.hpp)
add_executable(leetcode842 leetcode842/Main.cpp leetcode842/Solution.hpp)
add_executable(leetcode290 leetcode290/Main.cpp)

add_executable(leetcode714 leetcode714/Main.cpp)

add_executable(leetcode389 leetcode389/Main.cpp)

add_executable(leetcode738 leetcode738/Main.cpp)

add_executable(leetcode746 leetcode746/Main.cpp)

add_executable(leetcode103 leetcode103/Main.cpp)

add_executable(leetcode387 leetcode387/Main.cpp)

add_executable(leetcode135 leetcode135/Main.cpp)

add_executable(leetcode455 leetcode455/Main.cpp)

add_executable(leetcode1046 leetcode1046/Main.cpp)

add_executable(leetcode435 leetcode435/leetcode435.cpp)


add_executable(leetcode605 leetcode605/leetcode605.cpp)

add_executable(leetcode239 leetcode239/leetcode239.cpp)

add_executable(leetcode509 leetcode509/leetcode509.cpp)

add_executable(leetcode830 leetcode830/leetcode830.cpp)

add_executable(test_member_init main.cpp)

add_executable(leetcode189 leetcode189/leetcode189.cpp)

add_executable(leetcode1202 leetcode1202/leetcode1202.cpp)

add_executable(leetcode1018 leetcode1018/leetcode1018.cpp)

add_executable(leetcode724 leetcode724/leetcode724.cpp)

add_executable(leetcode674 leetcode674/leetcode674.cpp)
