cmake_minimum_required(VERSION 3.23)
project(home_assitant_Rest_API)

set(CMAKE_CXX_STANDARD 14)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/secrets.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

find_package(CURL)

add_executable(home_assitant_Rest_API Rest_API.cpp Rest_API.h)
target_link_libraries(home_assitant_Rest_API curl)

