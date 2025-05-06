cmake_minimum_required(VERSION 3.30)
project(OOP_1uzd)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include module and test subdirectories
add_subdirectory(modules)
find_package(GTest REQUIRED)



# Main executable
add_executable(OOP_1uzd
        main.cpp
)

# Link main executable to your student library
target_link_libraries(OOP_1uzd PRIVATE studentlib)

# Optionally include headers globally
target_include_directories(OOP_1uzd PRIVATE ${CMAKE_SOURCE_DIR}/modules)
