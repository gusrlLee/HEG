cmake_minimum_required(VERSION 3.14)
set (CMAKE_CXX_STANDARD 14)
project(HREG)

find_package( SDL2 REQUIRED )
find_package( spdlog REQUIRED )

include_directories(${SDL2_INCLUDE_DIRS})

add_executable( ${PROJECT_NAME} main.cpp )

target_link_libraries( ${PROJECT_NAME} 
    ${SDL2_LIBRARIES}
    spdlog::spdlog_header_only
)

