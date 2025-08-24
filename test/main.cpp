#include <print>
#include "HelloWorld.hpp"

int main() {
    std::println("Calling HelloWorld::sayHello() -> {}",HelloWorld().sayHello());
    return 0;
}
