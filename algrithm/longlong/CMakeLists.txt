cmake_minimum_required(VERSION 2.7)

project(algrithm)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCE sort.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

add_executable(${PROJECT_NAME}_sort main.cpp)
target_link_libraries(${PROJECT_NAME}_sort ${PROJECT_NAME})