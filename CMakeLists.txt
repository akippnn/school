cmake_minimum_required(VERSION 3.21)
project(cpe211)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
set(ENV{CMAKE_TERM_PROGRAM} "wt.exe")

set(PDCURSES_PATH "${CMAKE_SOURCE_DIR}/external/PDCurses")

include_directories(${PDCURSES_PATH})

# Collect all source files in the 'src' directory
file(
    GLOB SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(EXEC_NAME ${SRC_FILE} NAME_WE)
    add_executable(${EXEC_NAME} ${SRC_FILE})
    target_link_directories(${EXEC_NAME} PRIVATE ${PDCURSES_PATH})
    target_link_libraries(${EXEC_NAME} PRIVATE pdcurses)
endforeach()