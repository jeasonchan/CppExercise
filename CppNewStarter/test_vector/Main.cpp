//
// Created by jeason on 2020/10/21.
//
#include <iostream>
#include <utility>
#include <vector>


namespace test_vector {

#ifndef test_vector_A
#define test_vector_A

    class A {
    private:
        int i;
        std::string str;

    public:
        A() {

        }

        A(int a) : i(a) {
            std::cout << "consttuct int a" << std::endl;
        }

        A(int a, std::string b) : i(a), str(std::move(b)) {
            std::cout << "consttuct int a string b" << std::endl;
        }

    };

#endif
}


int main() {
    std::vector<test_vector::A> vec;
    vec.emplace_back(test_vector::A());
    vec.emplace_back(1, "2");
    vec.push_back(2);
    vec.push_back(1);


    return 0;
}