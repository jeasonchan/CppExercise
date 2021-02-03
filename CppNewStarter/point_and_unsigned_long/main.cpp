#include<iostream>



/**
 * @brief main
 *
 * 研究一下进程中指针的值
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc,char* argv[]){
    using namespace std;

    int a=123;
    int* p=&a;

    cout<<p<<endl;
    cout<<(unsigned long long)(p)<<endl;
    cout<<reinterpret_cast<unsigned long long>(p)<<endl;
    //cout<<static_cast<unsigned long long>(p)<<endl;  编译器不允许
    cout<<*p<<endl;
    /*
     输出：
     0x61fe14
     6422036
     6422036
     123
    */

    return 0;

}

