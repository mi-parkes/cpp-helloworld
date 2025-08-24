cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(ExternalProject)

option(BUILD_SHARED_LIBS "Build the external library as a static library" OFF)

set(EXTERNAL_PROJ_NAME "hello_library")
set(EXTERNAL_PROJ_URL "https://github.com/mi-parkes/cpp-helloworld")
set(EXTERNAL_PROJ_TAG "main")

FetchContent_Declare(${EXTERNAL_PROJ_NAME}
    GIT_REPOSITORY ${EXTERNAL_PROJ_URL}
    GIT_TAG ${EXTERNAL_PROJ_TAG}
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}
)

FetchContent_MakeAvailable(${EXTERNAL_PROJ_NAME})

add_executable(my_app main.cpp)

add_dependencies(my_app ${EXTERNAL_PROJ_NAME})

target_link_libraries(my_app PRIVATE ${EXTERNAL_PROJ_NAME})
