//
// Created by jeasconchan on 2020/9/19.
//
#include <iostream>
#include <limits>

namespace test_new {
    /**
     * 申请size长度的char数组，并返回首指针
     * @param size
     * @return
     */
    char *getMemory(unsigned long size) {
        return new char[size];
    }

    enum class Colour {
        GREEN(1)

        private:
        int value;

        public:
        Colour(int input):value(input){

        }
    };


}


int main() {
    {
        char *a = test_new::getMemory(666);
        std::cout << "index=666-1  " << a[666 - 1] << std::endl;
        std::cout << "index=666-2  " << a[666 - 2] << std::endl;
        //设置可以超过的数组的范围进行取值，只不过取出来的值可能因为类型对不上而报错
        //不过char占用1字节，基本是最小单位，按字节取时总能找到对应的asici值
        std::cout << "index=666+1 " << a[666 + 1] << std::endl;

        delete[] a;
    }

    {
        try {
            //申请分配无符号long类型的最大值个字节，显然我的内存没那么大，故意引发报错
            //注意！这里通过模板的方式取到每个类型的最大值
            char *a = test_new::getMemory(
                    std::numeric_limits<unsigned long>::max()
            );

            //上面new操作符抛异常就根本执行不到这一行判空
            if (nullptr == a) {
                std::cout << "char *a init failed!" << std::endl;
            }

        } catch (std::exception &exception) {
            std::cout << exception.what() << std::endl;
        }

    }


    return 0;
}