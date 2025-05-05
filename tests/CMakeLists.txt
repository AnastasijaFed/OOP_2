cmake_minimum_required(VERSION 3.10)
project(OOP_1uzd_Tests)

# Create the test executable from your test source file(s)
add_executable(OOP_1uzd_Tests
        test_functions.cpp
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Link the test executable to your main project library and Google Test
target_link_libraries(OOP_1uzd_Tests
        PRIVATE
        studentlib     # Replace with your actual library name from modules
        gtest
        gtest_main
)
