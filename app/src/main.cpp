#include "HelloWorld.hpp"
#include <iostream>

#if defined(__cpp_lib_print) && __has_include(<print>)
#include <print>
#endif

// Helper function to get a human-readable C++ version string
const char* get_cpp_version_string() {
    long version = __cplusplus;
    if (version >= 202302L) return "C++23";
    if (version >= 202002L) return "C++20";
    if (version >= 201703L) return "C++17";
    if (version >= 201402L) return "C++14";
    if (version >= 201103L) return "C++11";
    if (version >= 199711L) return "C++98";
    return "pre-C++98 or unknown";
}

int main() {
#if defined(__cpp_lib_print) && __has_include(<print>)
    std::println("Calling HelloWorld::sayHello() -> {} {}", HelloWorld().sayHello(), get_cpp_version_string());
#else
    std::cout << "Calling HelloWorld::sayHello() -> " << HelloWorld().sayHello() << " " << get_cpp_version_string() << std::endl;
#endif
    return 0;
}
