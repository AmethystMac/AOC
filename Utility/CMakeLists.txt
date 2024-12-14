# Define the Utility library
add_library(UtilityLibrary STATIC StringOperations.cpp IntOperations.cpp)

# Include the current directory for header files
target_include_directories(UtilityLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
