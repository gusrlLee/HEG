cmake_minimum_required(VERSION 3.14)
include_directories(${CMAKE_SOURCE_DIR})
add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} HEG_API)
