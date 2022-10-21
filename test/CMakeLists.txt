cmake_minimum_required(VERSION 3.0.0)
project(jceSearchEngine VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(runTest test.cpp)
set_property(TARGET runTest PROPERTY CXX_STANDARD 20)
target_link_libraries(runTest PUBLIC jceSearchEngine)
