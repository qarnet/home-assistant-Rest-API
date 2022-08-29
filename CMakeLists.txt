cmake_minimum_required(VERSION 3.16)
project(home_assitant_Rest_API)

set(CMAKE_CXX_STANDARD 14)

find_package(CURL)

add_library(home_assitant_Rest_API Rest_API.cpp Rest_API.h)
target_link_libraries(home_assitant_Rest_API curl)


