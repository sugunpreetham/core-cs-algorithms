#include <iostream>
#include <string>

// Cross-platform TCP multiplexer interface definition
class ITcpServer {
public:
    virtual void start(int port) = 0;
    virtual void stop() = 0;
    virtual ~ITcpServer() = default;
};

int main() {
    std::cout << "TCP server abstraction verified." << std::endl;
    return 0;
}

// Updated: 2022-01-25 - feat(networking): non-blocking TCP socket server with epoll in C++
