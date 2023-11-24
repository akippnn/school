cmake_minimum_required(VERSION 3.21)

project(cpe211)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fcoroutines")

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

add_subdirectory(vendor/fmt)
find_package(fmt)
find_package(Curses REQUIRED)

add_library(generator_lib "${INCLUDE_DIR}/generator.h" "${SRC_DIR}/generator.cpp")

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${SRC_DIR}/app/*.cpp")

foreach(SRC_FILE ${SRC_FILES})
  get_filename_component(EXEC_NAME ${SRC_FILE} NAME_WE)
  add_executable(${EXEC_NAME} ${SRC_FILE})
  target_link_libraries(${EXEC_NAME} ${CURSES_LIBRARIES} fmt::fmt)
  target_link_libraries(${EXEC_NAME} generator_lib)
endforeach()