#include <semaphore.h>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <tuple>

class Util
{
public:
    static void printMainArgv(const int &argc, char *argv[])
    {
        for (int i = 0; i < argc; ++i)
        {
            std::cout << argv[i] << std::endl;
        }
    }
};


//也就是用返回值来初始化const int类型的临时量
const int add(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    Util::printMainArgv(argc, argv);

    auto myTuplple = std::make_tuple(1, 2);

    return 0;
}