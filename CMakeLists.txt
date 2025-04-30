cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
find_package(fmt REQUIRED)
include_directories(${fmt_INCLUDE_DIRS})

# Set the source directory
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Add the executable
add_executable(Project "${SRC_DIR}/main.cpp")
target_link_libraries(Project ${CURSES_LIBRARIES})
target_link_libraries(Project ${fmt_LIBRARIES})
