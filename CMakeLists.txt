cmake_minimum_required(VERSION 3.30)
project(OOP_1uzd)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


include_directories(.)

# Add subdirectories
add_subdirectory(modules)
add_subdirectory(tests)

# Main executable
add_executable(OOP_1uzd
        main.cpp)

# Link main executable to your module library (defined in modules/CMakeLists.txt)
target_link_libraries(OOP_1uzd PRIVATE studentlib)
