add_library(hello_library src/HelloWorld.cpp)

target_include_directories(hello_library PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if (BUILD_SHARED_LIBS)
target_compile_definitions(hello_library PUBLIC "BUILD_HELLO_SHARED_LIBRARY")
endif()

install(TARGETS hello_library EXPORT hello_library_targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

install(FILES include/HelloWorld.hpp DESTINATION include)

install(EXPORT hello_library_targets
        FILE hello_library_targets.cmake
        NAMESPACE hello_library::
        DESTINATION share/hello_library)
