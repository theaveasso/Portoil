cmake_minimum_required(VERSION 3.28)

project(portoil VERSION 0.1.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(raylib CONFIG REQUIRED)

add_subdirectory(src/core)
add_subdirectory(src/game)
add_subdirectory(src/platform)

