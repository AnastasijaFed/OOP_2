cmake_minimum_required(VERSION 3.20)
project(OOP_1uzd)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# Add subdirectories
add_subdirectory(modules)


# Add main executable
add_executable(OOP_1uzd main.cpp)

# Link to the studentlib (module library)
target_link_libraries(OOP_1uzd PRIVATE studentlib)

add_subdirectory(tests)

