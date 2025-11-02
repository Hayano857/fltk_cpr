cmake_minimum_required(VERSION 3.11)
project(cpr CXX)

# Enable modern C++ and compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect source files
file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Add include directories
include_directories(
    "${CMAKE_SOURCE_DIR}/include"
)

# Find required packages
find_package(CPR REQUIRED)
find_package(FLTK REQUIRED)

# Create executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link libraries using modern CMake targets where possible
target_link_libraries(${PROJECT_NAME} 
    PRIVATE
        cpr::cpr            # Modern target for CPR
        ${FLTK_LIBRARIES}   # FLTK libraries
)

# Optional: Add build instructions as comments
# To build this project:
# 1. Create a build directory:
#    mkdir build && cd build
#
# 2. Configure the project:
#    cmake ..
#
# 3. Build the project:
#    cmake --build .