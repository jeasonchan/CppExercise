#include <iostream>
#include "bean/person.h"
#include "netfw.h"
#include "string.h"
#include "strings.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Person person = Person();
    Person *person1 = &person;
    person1->getName();

    Person::allPersonJump();

    std::cout << person.getAge() << person.getName();




    return 0;
}
