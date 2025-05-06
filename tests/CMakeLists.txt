# Enable Catch2
find_package(Catch2 2.13.7 REQUIRED)

# Create the test executable
add_executable(MyProjectTests test_main.cpp test_functions.cpp)

# Link your test executable with Catch2 and your module
target_link_libraries(MyProjectTests PRIVATE Catch2::Catch2 studentlib)

# Register tests with CTest (for use with ctest)
include(CTest)
include(Catch)
catch_discover_tests(MyProjectTests)
