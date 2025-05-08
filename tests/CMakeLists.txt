# Create test executable
add_executable(student_tests student_test.cpp)

# Link with your library and GoogleTest
target_link_libraries(student_tests PRIVATE studentlib gtest gtest_main)

# Register with CTest
add_test(NAME StudentTests COMMAND student_tests)
