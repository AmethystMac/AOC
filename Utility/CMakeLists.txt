# Define the Utility library
add_library(StringOperations STATIC StringOperations.cpp)

# Include the current directory for header files
target_include_directories(StringOperations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
