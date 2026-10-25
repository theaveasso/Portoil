cmake_minimum_required(VERSION 3.28)

project(portoil VERSION 0.1.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(raylib CONFIG REQUIRED)

add_subdirectory(src/core)
add_subdirectory(src/game)

add_executable(portoil src/platform/app.cpp src/platform/main.cpp)
target_include_directories(portoil PUBLIC src)
target_link_libraries(portoil PRIVATE pt_core pt_game raylib)

target_compile_features(portoil PUBLIC cxx_std_20)

if(MSVC)
  target_compile_options(portoil PRIVATE /W4 /EHs-c- /GR-)
  target_compile_definitions(portoil PRIVATE _HAS_EXCEPTIONS=0)
endif()
