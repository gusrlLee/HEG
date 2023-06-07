cmake_minimum_required(VERSION 3.14)
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(HREG)

find_package( SDL2 REQUIRED )
find_package( spdlog REQUIRED )

include_directories(${SDL2_INCLUDE_DIRS})

add_executable( ${PROJECT_NAME} 
    main.cpp 
    Application.cpp
)

target_link_libraries( ${PROJECT_NAME} 
    ${SDL2_LIBRARIES}
    spdlog::spdlog_header_only
)

