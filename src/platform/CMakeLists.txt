file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.h)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} PRIVATE pt_core pt_game raylib)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /EHs-c- /GR-)
  target_compile_definitions(${PROJECT_NAME} PRIVATE _HAS_EXCEPTIONS=0)
endif()

if("${PT_PLATFORM}" STREQUAL "Web")
  set(PT_WEB_SHELL ${CMAKE_CURRENT_SOURCE_DIR}/web/shell.html)
  set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME index SUFFIX ".html")
  target_link_options(${PROJECT_NAME} PUBLIC -sUSE_GLFW=3 --shell-file ${PT_WEB_SHELL})
  target_compile_definitions(${PROJECT_NAME} PRIVATE PT_PLATFORM_WEB)
  set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY LINK_DEPENDS ${PT_WEB_SHELL})
endif()
