# Enable CMake's testing framework
enable_testing()

# Create the test executable
add_executable(OOP_1uzd_Tests
        test_functions.cpp
)

# Link the test executable with your student library and Google Test
target_link_libraries(OOP_1uzd_Tests
        PRIVATE
        studentlib
        GTest::gtest_main   # We typically use `gtest_main` in tests
)

# Add a test so it can be run via `ctest`
add_test(NAME AllTests COMMAND OOP_1uzd_Tests)

# Optionally include test directory headers
target_include_directories(OOP_1uzd_Tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
