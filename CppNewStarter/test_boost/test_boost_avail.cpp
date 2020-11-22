
#include <array>
#include <iostream>

#include "boost/asio.hpp"

class Person_00 {
public:
    int *begin() {
        return &(this->age);
    }

    int *end() {
        return &(this->age);
    }

private:
    int age;
    std::string name;


};

/*
 * 自动类型推断，将ptr_type推断为指针类型
 */
template<typename ptr_type1, typename ptr_type2>
bool compare(ptr_type1 input1, ptr_type2 input2) {

    //对于范型，clion并不在编码期进行检查，其实不应该，应该面向面向接口编程，入参时就声明类型
    //但是，编译器会在编译期根据所有代码里用到该据函数模板的地方进行校验，最终发缺少的成员函数或者为未实现的操作符
    input1->begin();

    auto value1 = *input1;
    auto value2 = *input2;

    return value1 < value2;
}


int main() {
    boost::asio::io_service ioService;
    ioService.run();


    int a = 1;
    int b = 2;


    std::cout << compare(&a, &b) << std::endl;

    Person_00 person00;

    std::cout << compare(&person00, &person00) << std::endl;

    std::sort<decltype(person00.begin())>(person00.begin(), person00.end(),
                                          [](const int *input1, const int *input2) -> bool {
                                              return *input1 < *input2;
                                          });

//    std::sort<decltype(person00.begin())>(person00.begin(), person00.end());




    return 0;
}