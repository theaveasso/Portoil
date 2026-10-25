add_library(pt_core STATIC loop.cpp loop.h pt_math.h)
target_include_directories(pt_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
