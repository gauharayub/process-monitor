cmake_minimum_required(VERSION 3.10)

project(PROCESS_MONITOR VERSION 1.0)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp ProcessParser.cpp util.cpp)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
