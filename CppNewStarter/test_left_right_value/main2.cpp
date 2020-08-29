
//
// Created by jeasconchan on 2020/6/21.
//


#include <string>
#include <iostream>

using namespace std;

string echo(string &input) {
    string result = input;//这一句应该是调用sting 的 左值引用 赋值操作符
    return result;

};

//编译不过，直接报错，将一个局部变量作为左引用返回
//string &echo2(string &input) {
//    string result = input;
//    return result;
//
//};

string &&echo3(string &input) {
    const string &result = input;
    return const_cast<string &&>(result);
};

char &get_val(string &str, string::size_type ix) {
    return str[ix];
}

int main() {
    string input = "a";
    cout << echo(input) << endl;
//    cout << echo2(input) << endl;
    cout << echo3(input) << endl;

    string s("123456");
    get_val(s, 0) = 'a';//赋值符号也只不过是一个函数而以
    cout << s << endl;//输出 a23456

    char &&a = '1';
    a = '2';
    cout << a << endl;

    string b = "123";
    string &c = b;
    c="111";//再一次证明，cpp里面的赋值符号不过是一个函数，这里相当于的调用了一个函数，入参是"111"，和java不太一样
    cout<<b<<endl;//输出 111


    string d=b;
    d="456";
    cout<<b<<endl;

    return 0;
}

/*
//输出：

 jeasconchan@jeasconchan-ThinkPad-E485:~/projects/CppExercise/CppNewStarter/试验左值右值$ g++ -std=c++11 main2.cpp
main2.cpp: In function ‘std::string& echo2(std::string&)’:
main2.cpp:20:12: warning: reference to local variable ‘result’ returned [-Wreturn-local-addr]
   20 |     return result;
      |            ^~~~~~
main2.cpp:19:12: note: declared here
   19 |     string result = input;
      |            ^~~~~~
jeasconchan@jeasconchan-ThinkPad-E485:~/projects/CppExercise/CppNewStarter/试验左值右值$ g++ -std=c++11 main2.cpp
jeasconchan@jeasconchan-ThinkPad-E485:~/projects/CppExercise/CppNewStarter/试验左值右值$ ls
a.out  main2.cpp  main.cpp
jeasconchan@jeasconchan-ThinkPad-E485:~/projects/CppExercise/CppNewStarter/试验左值右值$ ./a.out
a
a

 */