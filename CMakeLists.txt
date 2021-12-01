cmake_minimum_required(VERSION 3.10)
 
project(easymath)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(easymath hello.cpp)
target_link_libraries(easymath ${GTEST_LIBRARIES} pthread)