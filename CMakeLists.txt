cmake_minimum_required(VERSION 3.10)

# Set the project name
project(4DTokenization)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(tensor_visualization main.cpp Tensor4D.h)

# Find Matplot++ package
find_package(Matplot++ REQUIRED)

# Include Matplot++ directories
include_directories(${Matplot++_INCLUDE_DIRS})

# Link Matplot++ library
target_link_libraries(tensor_visualization Matplot++)
