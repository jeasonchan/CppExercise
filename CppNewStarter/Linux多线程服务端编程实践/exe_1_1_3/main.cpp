#include <mutex>
#include <memory>
#include <thread>
#include <iostream>
#include <chrono>

// 匿名方法区，方法区内的符号天然对本编译单元内可见，且由于匿名性，可以等效认为对其他编译单元不可见
namespace
{
    class unsafe_counter
    {
    private:
        int times;

    public:
        unsafe_counter(/* args */) : times(0)
        {
        }

        void increase()
        {
            ++(this->times);
        }

        int getTimes()
        {
            return this->times;
        }
    };

    class safe_counter
    {

    private:
        long times; //2147483647
        std::mutex lock;

    public:
        safe_counter() : times(0) {}

        void increase()
        {
            std::lock_guard<std::mutex> guard(this->lock);
            ++(this->times);
        }

        int getTimes()
        {
            return this->times;
        }
    };

}

int main()
{
    using namespace std;

    {   
        thread threadHello([]() { cout << "Hello" << endl; });
        // 离开这个作用域时，编译器产生的代码会自动析构thread 对象实例，然而这个线程还在跑，发生core dump
    }

    unsafe_counter counter01;
    thread counter01_thread01([&counter01]() {
        for (int i = 0; i < 10000000; ++i)
        {
            counter01.increase();
        }
    });

    thread counter01_thread02([&counter01]() {
        for (int i = 0; i < 10000000; ++i)
        {
            counter01.increase();
        }
    });

    thread counter01_thread03([&counter01]() {
        for (int i = 0; i < 10000000; ++i)
        {
            counter01.increase();
        }
    });

    // 必须用detach，否则主线程会尝试析构线程，导致异常，这是CPP强制程序员有效进行资源管理
    counter01_thread01.detach();
    counter01_thread02.detach();
    counter01_thread03.detach();

    safe_counter counter02;
    thread counter02_thread01([&counter02]() {
        for (int i = 0; i < 10000000; ++i)
        {
            counter02.increase();
        }
    });

    thread counter02_thread02([&counter02]() {
        for (int i = 0; i < 10000000; ++i)
        {
            counter02.increase();
        }
    });

    thread counter02_thread03([&counter02]() {
        for (int i = 0; i < 10000000; ++i)
        {
            counter02.increase();
        }
    });
    counter02_thread01.detach();
    counter02_thread02.detach();
    counter02_thread03.detach();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    cout << counter01.getTimes() << endl;
    cout << counter02.getTimes() << endl;

    void (safe_counter::*fun)() = &safe_counter::increase;
    thread thread222(&safe_counter::increase, &counter02);
    (counter02.*fun)();

    return 0;
}