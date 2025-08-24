# Minimal cmake c++ helloworld library, application

This project demonstrates a basic setup for a C++ project using CMake. It includes a library that can be built as either static or shared, and a simple application (`hello_app`) that links against and uses the library.

## Project Structure

```
.
├── CMakeLists.txt              # Main CMake file
├── README.md                   # This file
├── lib                         # Shared library
│   ├── CMakeLists.txt
│   ├── include
│   │   └── hello_library.hpp   # Public header file
│   └── src
│       └── hello_library.cpp   # Source file
└── app                         # Executable
    ├── CMakeLists.txt
    └── main.cpp                # Application entry point
```

## How to Build

1. Create a build directory and navigate into it:
   ```sh
   mkdir build
   cd build
   ```
2. Configure the project with CMake.

   To build a **static library** (the default):
   ```sh
   cmake ..
   ```

   To build a **shared library**:
   ```sh
   cmake .. -DBUILD_SHARED_LIBS=ON
   ```
3. Compile the project:
   ```sh
   cmake --build .
   ```

## How to Run

After building, the executable will be in the build directory. From the `build` directory, run:

```sh
./app/hello_app
