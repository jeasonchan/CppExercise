#include<iostream>
#include<string>

/*
验证 指向成员对象和成员函数的指针

直接根据

*/

namespace  jeasonchan{
using namespace std;

class Person
{
public:
    Person():age(666),name("default") {}

    int age;
    string name;

    void saySth_copy2(){
        cout<<"name2:"<<name<<endl
           <<"age2:"<<age<<endl;
    }

    void saySth_copy(){
        cout<<"name1:"<<name<<endl
           <<"age1:"<<age<<endl;
    }

    void saySth(){
        cout<<"name:"<<name<<endl
           <<"age:"<<age<<endl;
    }

};

}


int main(int argc,char* argv[]){
    using namespace jeasonchan;
    Person p;

    std::cout<<&(p.age)<<std::endl;  //输出age这个int 在进程虚拟地址空间中的地址

    int Person::*offset_of_Person_int=&Person::age;//age从类实例起点开始计算的偏移量，单位是字节数
    std::cout<<offset_of_Person_int<<std::endl;//打印this开始的偏移量
    std::cout<<p.*offset_of_Person_int<<std::endl;//根据偏移量，从类的起始点开始取值


    void (Person::*offset_of_Person_saySth)()=&Person::saySth;
    std::cout<<offset_of_Person_saySth<<std::endl;//成员函数不占用任何对象实例的内存，输出1
    (p.*offset_of_Person_saySth)();

    void (Person::*offset_of_Person_saySth_copy)()=&Person::saySth_copy;
    std::cout<<offset_of_Person_saySth_copy<<std::endl;//成员函数不占用任何对象实例的内存，输出1????


    void (Person::*offset_of_Person_saySth_copy2)()=&Person::saySth_copy2;
    std::cout<<offset_of_Person_saySth_copy2<<std::endl;//成员函数不占用任何对象实例的内存，输出1????


    return 0;
}
