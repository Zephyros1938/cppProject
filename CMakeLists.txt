cmake_minimum_required(VERSION 3.10)

project(Program VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# Store found system libraries here
set(SYSTEM_LIBS)

# Read dependencies.txt
file(READ "${CMAKE_SOURCE_DIR}/dependencies.txt" DEP_CONTENTS)
string(REPLACE "\n" ";" DEP_LIST "${DEP_CONTENTS}")

foreach(DEP IN LISTS DEP_LIST)
    string(STRIP "${DEP}" DEP)  # Trim whitespace
    if(DEP STREQUAL "" OR DEP MATCHES "^#")  # Skip empty lines or comments
        continue()
    elseif(DEP MATCHES "^@")
        # Handle system library
        string(SUBSTRING "${DEP}" 1 -1 LIB_NAME)
        find_path(LIB_INCLUDE_DIR "${LIB_NAME}.h")
        find_library(LIB_BINARY "${LIB_NAME}")
        if(LIB_INCLUDE_DIR)
            include_directories(${LIB_INCLUDE_DIR})
        else()
            message(WARNING "Could not find headers for system library '${LIB_NAME}'")
        endif()
        if(LIB_BINARY)
            list(APPEND SYSTEM_LIBS ${LIB_BINARY})
        else()
            message(WARNING "Could not find binary for system library '${LIB_NAME}'")
        endif()
    else()
        # Handle local include path
        if(EXISTS "${CMAKE_SOURCE_DIR}/${DEP}")
            include_directories("${CMAKE_SOURCE_DIR}/${DEP}")
        else()
            message(WARNING "Dependency path '${DEP}' does not exist.")
        endif()
    endif()
endforeach()

# Add executable
add_executable(Program src/main.cpp)

# Link libraries
target_link_libraries(Program ${SYSTEM_LIBS})
