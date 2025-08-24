#include "HelloWorld.hpp"

std::string HelloWorld::sayHello() {
#if defined(BUILD_HELLO_SHARED_LIBRARY)
    return "Hello from hello_library (shared)!";
#else    
    return "Hello from hello_library (static)!";
#endif
}
