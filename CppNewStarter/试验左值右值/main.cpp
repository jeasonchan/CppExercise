//
// Created by jeasconchan on 2020/6/21.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class MyString {

private:
    char *_data;
    size_t _len;

    void _init_data(const char *s) {
        _data = new char[_len + 1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }

public:
    MyString() {
        _data = nullptr;
        _len = 0;
    }

    MyString(const char *p) {
        _len = strlen(p);
        _init_data(p);
    }

//左值引用  拷贝构造函数
    MyString(const MyString &str) {

        //和java一样，同一个域/类 内部，可以访问类实例的私有变量
        //之前一直认为私有变量只能通过this和getter才能访问……
        _len = str._len;
        _init_data(str._data);
        std::cout << "Copy Constructor is called! source: " << str._data << std::endl;
    }

    MyString(MyString &&str) {
        std::cout << "Move Constructor is called! source: " << str._data << std::endl;
        _len = str._len;
        _data = str._data; //注意此处，没用左值引用的 memcpy ，而是直接用的指针指向原来的地址

        str._len = 0;

        str._data = nullptr;
        //将原先的指针赋值为空很关键，观察析构函数：
        //virtual ~MyString() {
        //if (_data) delete(_data);
        //}
        //指针不为空释放堆内存，如果不赋值为nullptr，内存会被释放，
        //转移拷贝的里面指向的内存区域就没有意义了，或者很快重新写入其他数据


    }

//左值引用  的 赋值  符号
    MyString &operator=(const MyString &str) {
        if (this != &str) {
            _len = str._len; //为了让两个对象脱离关系，这里的值拷贝是必不可少的，即不能共用内存块
            _init_data(str._data); //因为MyString和当前的类类型相同，所以可以直接访问入参的私有变量
        }
        std::cout << "Copy Assignment is called! source: " << str._data << std::endl;
        return *this;
    }

    MyString &operator=(MyString &&str) {
        std::cout << "Move Assignment is called! source: " << str._data << std::endl;
        if (this != &str) { //引用就像一个对象，用了取地址符
            _len = str._len;
            _data = str._data;
            str._len = 0;
            str._data = nullptr;
        }
        return *this; //返回的是一个对象，用了取内容符号
    }

    virtual ~MyString() {
        if (_data) delete (_data);
    }

}; //类定义结束

int main() {
    MyString a; //在栈中声明变量a，并直接调用无参构造函数进行初始化

    a = MyString("Hello");
    //这是一种通过有参构造函数进行拷贝的行为
    //然后再通过重载过的赋值符号进行赋值

    std::vector<MyString> vec; //声明并调用无参构造

    vec.push_back(MyString("World"));
    //最后这一句复杂了，
    //先使用有参构造进行了值的拷贝，返回了一个对象，毫无疑问，


    vec.push_back(a);
}