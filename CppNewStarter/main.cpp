#include <iostream> //使用标准库的做法是，用尖括号从标准类库引用头文件，再通过std命名空间使用

#include "bean/person.h"
#include "bean/student.h"
//使用自定义的头文件，使用双引号从项目的根目录下以相对路径引用；
// cpp风格的标准做法还是自定义一个命名空间，再通过命名空间导出变量名再使用

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Person person = Person();
    Person *person1 = &person;
    person1->getName();

    Person::allPersonJump();

    std::cout << person.getAge() << person.getName();

    Student::allPersonJump();



    return 0;
}
