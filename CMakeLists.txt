cmake_minimum_required(VERSION 3.13)
project(Process_Monitor_Linux)

set(CMAKE_CXX_STANDARD 14)

add_executable(Process_Monitor_Linux main.cpp constants.h Process.h util.h ProcessParser.h ProcessContainer.h Sysinfo.h ProcessParser.cpp util.cpp)

find_package(Curses REQUIRED)
target_include_directories(Process_Monitor_Linux PRIVATE ${CURSES_INCLUDE_DIRS})

target_link_libraries(Process_Monitor_Linux PRIVATE ${CURSES_LIBRARIES})