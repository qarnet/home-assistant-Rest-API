cmake_minimum_required(VERSION 3.16)
project(home_assitant_Rest_API CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(CURL REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})

add_library(rest STATIC Rest_API.cpp Rest_API.h)

add_executable(${PROJECT_NAME} main.cpp)

# target_sources(${PROJECT_NAME} PRIVATE Rest_API.cpp)

target_link_libraries(${PROJECT_NAME} curl rest)