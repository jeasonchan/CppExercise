
//
// Created by jeasconchan on 2020/6/21.
//


#include <string>
#include <iostream>

using namespace std;

string echo(string &input) {
    string result = input;
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


int main() {
    string input = "a";
    cout << echo(input) << endl;
//    cout << echo2(input) << endl;
    cout << echo3(input) << endl;


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