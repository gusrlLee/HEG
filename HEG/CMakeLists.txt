cmake_minimum_required(VERSION 3.14)

find_package(spdlog REQUIRED)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(HEG_API SHARED 
    Application.cpp
    Log.cpp
)

target_link_libraries(HEG_API 
    spdlog::spdlog_header_only
)
