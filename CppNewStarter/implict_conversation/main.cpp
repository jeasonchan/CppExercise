#include<iostream>
#include<string>

/*
   看深入理解CPP对象模型时，看到隐式转换的用法，比如，某个类实例可隐式转为数字、布尔值、其他任意类型等

   跟之前了解过的自定义字面量很像，自定义字面量是将字符串转换为某种类型，CPP官方文档如下：
   CPP官方手册   https://zh.cppreference.com/w/cpp/language/user_literal
 */


namespace implict_conversation {
using namespace std;

class Person{
public:
    Person(std::string&& _name="",int && _age=-1)
        :name(_name),age(_age){}

    inline operator bool(){
        if(age<0||name.empty()){
            return false;
        }
        return true;
    }

private:
    std::string name;
    int age;
};


inline void checkIfTrue(Person & person){
    if(person){
        cout<<"person is true"<<endl;
    }else {
        cout<<"person is false"<<endl;
    }
}


inline void checkIfTrue_with_value(Person&& person){
    checkIfTrue(person);
}



inline Person operator "" _Person(const char* s, std::size_t n){
    cout<<"s = "<<s<<endl
       <<"n = "<<n<<endl;

    //直接返回一个右值，相应的，Person应该有右值拷贝构造
    return Person(s,-1);
}

}


int main(int argc, char *argv[])
{
    using namespace std;
    using namespace implict_conversation;

    for(int i=0;i<argc;++i){
        cout<<"argc["<<i<<"] = "<<argv[i]<<endl;
    }

    Person person;
    checkIfTrue(person);  //输出false

    Person person2("jeason",666);
    checkIfTrue(person2);    //输出true


    //注意，自定义字面量其实就是一个函数调用，有返回值的话，必然是一个右值
    checkIfTrue_with_value("jeason"_Person);


    return 0;
}
