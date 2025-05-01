cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source directory
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Source files
set(SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/window.cpp
)

# Find required packages
find_package(Curses REQUIRED)
find_package(fmt REQUIRED)

# Create executable
add_executable(Project ${SOURCES})

# Include directories for ncurses and fmt
target_include_directories(Project PRIVATE ${CURSES_INCLUDE_DIR})

# Link libraries
target_link_libraries(Project PRIVATE ${CURSES_LIBRARIES} fmt::fmt)
