//
// Created by chenr on 2020-05-17.
//

#include "person.h"
#include "iostream"

using namespace std;

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    Person::age = age;
}

const std::string &Person::getName() const {
    return name;
}

void Person::setName(const std::string &name) {
    Person::name = name;
}

 void Person::allPersonJump() {
    cout << "all Person jump!\n";

}

Person::Person(int age, std::string name) {
    this->name = name;
    this->age = age;
}
