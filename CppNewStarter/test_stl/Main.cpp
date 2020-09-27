//
// Created by jeasconchan on 2020/9/13.
//

#include <array>
#include <iostream>
#include <vector>

int main() {
    {
        std::array<int, 10> intArray{};

        std::array<int, 10>::iterator iterator = intArray.begin();
        //auto iterator = intArray.begin();

        std::cout << iterator << std::endl;
    }

    {
        //遍历vector容器

        std::vector<int> intVector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        std::cout << "第一种遍历方法：通过index" << std::endl;
        int size = intVector.size();

        for (int i = 0; i < size; ++i) {
            //像普通数组一样，通过重载的元算符[]进行访问
            std::cout << intVector[i] << " ";
        }
        std::cout << std::endl;


        std::cout << "第二种遍历方法：通过迭代器和迭代器不等于的比较" << std::endl;
        std::vector<int>::iterator normalIterator;

        //其实，不应该在上面定义，因为下面的=会发生新值覆盖旧值的赋值过程
        //不过iterator本质上就是指针，这种性能损耗忽略不计，而且是不可避免的
        //此处使用!=来进行迭代器比较
        //和java一样，end()是指向最后元素的下一个位置，一个为止类型的地址
        for (normalIterator = intVector.begin(); normalIterator != intVector.end(); ++normalIterator) {
            std::cout << *normalIterator << " ";
        }
        std::cout << std::endl;

        std::cout << "第三种遍历方法：通过迭代器和迭代器小于号的比较" << std::endl;
        for (normalIterator = intVector.begin(); normalIterator < intVector.end(); ++normalIterator) {
            std::cout << *normalIterator << " ";
        }
        std::cout << std::endl;

        std::cout << "第四种遍历方法：通过while循环间隔输出" << std::endl;
        normalIterator = intVector.begin();
        while (normalIterator < intVector.end()) {
            std::cout << *normalIterator << " ";
            normalIterator += 5;

            //跃界后，指向了不属于vector的地址，虽然可以读出int的值，但是其实是无意义的值
            std::cout << "地址是：" << &(*normalIterator) << " 值是：" << *normalIterator << std::endl;
        }


    }
    return 0;
}