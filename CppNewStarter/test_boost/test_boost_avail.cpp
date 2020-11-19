
#include <array>

#include "boost/asio.hpp"

int main() {
    boost::asio::io_service ioService;
    ioService.run();


    return 0;
}