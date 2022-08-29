cmake_minimum_required(VERSION 3.16)
project(home_assitant_Rest_API CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})

find_package(CURL REQUIRED)

add_library(${PROJECT_NAME} STATIC Rest_API.cpp Rest_API.h)
target_link_libraries(${PROJECT_NAME} curl)


