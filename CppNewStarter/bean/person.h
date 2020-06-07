//
// Created by chenr on 2020-05-17.
//

#ifndef CPPNEWSTARTER_PERSON_H
#define CPPNEWSTARTER_PERSON_H


#include <string>

class Person {
private:
    int age;
    //为了方防止命名空间污染，最好不要在的头文件里使用using namespace std
    //因为引用了该头文件的项目，std里的类名可能会和别人工程里的有冲突
    //java是通过全路径类名+类加载器的双亲委派机制来避免冲突
    std::string name;

public:
    Person(int age, std::string name);

    Person();

    int getAge() const;

    void setAge(int age);

    const std::string &getName() const;

    void setName(const std::string &name);

    static void allPersonJump();

};


#endif //CPPNEWSTARTER_PERSON_H
