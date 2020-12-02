
#include <array>
#include <iostream>
#include <functional>

//#include "boost/asio.hpp"
//#include <boost/asio/io_service.hpp>
//#include <boost/asio/spawn.hpp>
//#include <boost/asio/write.hpp>
//#include <boost/asio/buffer.hpp>
//#include <boost/asio/ip/tcp.hpp>
#include "boost/context/all.hpp"
#include <list>
#include <string>
#include <ctime>


class Person_00 {
public:
    int *begin() {
        return &(this->age);
    }

    int *end() {
        return &(this->age);
    }

private:
    int age;
    std::string name;


};

/*
 * 自动类型推断，将ptr_type推断为指针类型
 */
template<typename ptr_type1, typename ptr_type2>
bool compare(ptr_type1 input1, ptr_type2 input2) {

    //对于范型，clion并不在编码期进行检查，其实不应该，应该面向面向接口编程，入参时就声明类型
    //但是，编译器会在编译期根据所有代码里用到该据函数模板的地方进行校验，最终发缺少的成员函数或者为未实现的操作符
    input1->begin();

    auto value1 = *input1;
    auto value2 = *input2;

    return value1 < value2;
}
/*
using namespace boost::asio;
using namespace boost::asio::ip;

io_service ioservice;
tcp::endpoint tcp_endpoint{tcp::v4(), 2014};
tcp::acceptor tcp_acceptor{ioservice, tcp_endpoint};
std::list<tcp::socket> tcp_sockets;

void do_write(tcp::socket &tcp_socket, yield_context yield) {
    std::time_t now = std::time(nullptr);
    std::string data = std::ctime(&now);

    //向该socket连接的对象的写入数据，如果写入缓冲区中的字节很大，会反复写几次，并发生等待，产生阻塞现象
    //此处使用协程，运行到此处被"挂起"，相当于sleep了，并交出CPU时间片
    //同时，包装该类的"协程"对象（就像线程也有线程对象一样）会保存该协程执行时的上下文
    //至此，在用户态保存了协程的上下文，且记住了挂起时执行到的语句
    async_write(tcp_socket, buffer(data), yield);

    //关心的事件发生后，此处便是 IO操作写入完成  这个事件，"挂起"的协程被唤醒
    //开始使用保存的上下文，并根据挂起前的状态，继续执行
    tcp_socket.shutdown(tcp::socket::shutdown_send);
}

void do_accept(yield_context yield) {
    for (int i = 0; i < 2; ++i) {
        tcp_sockets.emplace_back(ioservice);

        //和上面注释的同理，在此处挂起，等待异步事件发生后再继续执行
        tcp_acceptor.async_accept(tcp_sockets.back(), yield);

        //异步事件发生，在此处被唤醒
        //在这个ioservice中注册一个"协程"类型的事件，等待之后在时间循环中触发，毕竟spawn就是专门给协程用的方法
        //epoll本身支持的事件类型比较有限
        //ioservice是io_context的别名，也就是IO上下文
        spawn(ioservice, [](yield_context yield) { do_write(tcp_sockets.back(), yield); });
    }
}
*/

void feobonaco() {
    namespace ctx = boost::context;

    int current = 1;
    int previous = 0;

    auto add_and_jump = [&current, &previous](ctx::continuation callerContext) {
        while (callerContext) {
            int new_current = previous + current;
            previous = current;
            current = new_current;
            callerContext = callerContext.resume();
        }

        return std::move(callerContext);
    };

    ctx::continuation fun_context = ctx::callcc(add_and_jump);

    for (int i = 0; i < 100; i++) {
        std::cout << "int main coroutine,i=" << i << " and current=" << current << std::endl;
        fun_context = fun_context.resume();
    }

}

int main() {

    feobonaco();

    /*



    //这个listen是个同步方法，表示开始监听端口
    tcp_acceptor.listen();

    //在ioservice这个上下文实例中注册协程事件
    //需要互相协作的协程才建议注册在一个上下文实例中，要不然会有无意义的让出CPU分片
    spawn(ioservice, do_accept);

    //遍历事件列表
    ioservice.run();



    //======================================
    boost::asio::io_service ioService;
    ioService.run();


    int a = 1;
    int b = 2;


    std::cout << compare(&a, &b) << std::endl;

    Person_00 person00;

    std::cout << compare(&person00, &person00) << std::endl;

    std::sort<decltype(person00.begin())>(person00.begin(), person00.end(),
                                          [](const int *input1, const int *input2) -> bool {
                                              return *input1 < *input2;
                                          });

//    std::sort<decltype(person00.begin())>(person00.begin(), person00.end());

    std::mem_fun(&std::string::empty);
    */



    return 0;
}