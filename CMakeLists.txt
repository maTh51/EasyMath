cmake_minimum_required(VERSION 3.10)
 

#############################
# Easy Math
#############################
project(easymath)

add_library(easymath INTERFACE)

target_include_directories(easymath INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib)


#############################
# Tests
#############################

enable_testing()

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
include(CTest)

project(easymathtest)
add_executable(easymathtest ${CMAKE_CURRENT_SOURCE_DIR}/tests/EasyMath.cpp)
target_link_libraries(easymathtest easymath ${GTEST_LIBRARIES} pthread)
add_test(NAME easymathtest COMMAND easymathtest)
