cmake_minimum_required(VERSION 3.10)

# Set project name and language
project(StudentProject LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectory containing the studentlib
add_subdirectory(modules)
add_subdirectory(thirdparty/googletest)

enable_testing()

# Add your test directory
add_subdirectory(tests)

# Add the main executable
add_executable(main
        main.cpp  # replace with your actual main source file
)

# Link the executable with the static library
target_link_libraries(main PRIVATE studentlib)
