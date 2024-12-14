# CMake configuration
cmake_minimum_required(VERSION 3.10)
project(CPP)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the Utility directory as a source
add_subdirectory(Utility)

# Add the executable
add_executable(test1 test1.cpp)

# Link the Utility library
target_link_libraries(test1 PRIVATE UtilityLibrary)