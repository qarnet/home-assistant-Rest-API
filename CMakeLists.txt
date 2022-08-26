cmake_minimum_required(VERSION 3.23)
project(home_assitant_Rest_API)

set(CMAKE_CXX_STANDARD 14)

find_package(CURL)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/secrets.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(home_assitant_Rest_API Rest_API.cpp Rest_API.h)
target_link_libraries(home_assitant_Rest_API /usr/lib64/libcurl.so)

