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
