#include <iostream> //使用标准库的做法是，用尖括号从标准类库引用头文件，再通过std命名空间使用

#include "bean/person.h"
#include "bean/student.h"
//使用自定义的头文件，使用双引号从项目的根目录下以相对路径引用；
// cpp风格的标准做法还是自定义一个命名空间，再通过命名空间导出变量名再使用
//include其实就是宏定义，在预编译阶段会将所有的include的头文件以文本的形式直接复制粘贴过来，替换include声明
//正是因为宏具有这样的无脑性，所以，不建议在大型项目中使用宏定义

#include "bean/util.h"
#include "bean/util2.h"

using namespace std;

class Foo {
public:

    //编译器自动生成的无参构造函数只会管类中类类型的成员变量
    int val;
    Foo *next;
};

//非函数体中（不包括类成员变量的基础数据类型）的基础数据类型，会默认执行0值初始化
int myAge;

int main() {
    Foo bar;


    int aaa=myAge;

/*
    std::cout << "Hello, World!" << std::endl;
    Person person = Person();
    Person *person1 = &person;
    person1->getName();

    Person::allPersonJump();

    std::cout << person.getAge() << person.getName();

    Student::allPersonJump();

    Student *studenP = new Student();
    studenP->setAge(12);
    studenP->setName("jeasonchan");

    cout << (*studenP).getName() << endl;
    cout << studenP->getName() << endl;


    long result = 123L;
    jc::Util::generateCountRandomNumber(123, result);
    cout << "result1:" << result << endl;

    jc::Util2::generateCountRandomNumber(123, result);
    cout << "result2:" << result << endl;


 */
    return 0;
}
