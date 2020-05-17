//
// Created by chenr on 2020-05-17.
//

#ifndef CPPNEWSTARTER_PERSON_H
#define CPPNEWSTARTER_PERSON_H


#include <string>

class Person {
private:
    int age;
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
