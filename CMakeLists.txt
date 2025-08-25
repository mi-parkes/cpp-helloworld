cmake_minimum_required(VERSION 3.23)

project(HelloWorld_Library_Project VERSION 1.0.0 LANGUAGES CXX)

if(NOT CMAKE_CXX_STANDARD)
    # Set the C++ standard to C++23.
    set(CMAKE_CXX_STANDARD 23)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_SHARED_LIBS "Build a shared library instead of a static one." OFF)

add_subdirectory(lib)
add_subdirectory(app)

