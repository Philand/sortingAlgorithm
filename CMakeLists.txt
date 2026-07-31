cmake_minimum_required(VERSION 3.14)
project(sortingAlgorithm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(sortingAlgorithm INTERFACE)
target_include_directories(sortingAlgorithm INTERFACE ${CMAKE_SOURCE_DIR}/src)
target_compile_options(sortingAlgorithm INTERFACE -Wall -Wextra -Werror)

enable_testing()
add_subdirectory(test)