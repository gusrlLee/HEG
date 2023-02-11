cmake_minimum_required(VERSION 3.14)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(HEG_API SHARED Application.cpp)
