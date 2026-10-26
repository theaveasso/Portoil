file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.h)

add_library(pt_game STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(pt_game PRIVATE pt_core)
target_include_directories(pt_game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
