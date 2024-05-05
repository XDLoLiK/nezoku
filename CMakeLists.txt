cmake_minimum_required(VERSION 3.27)

project(Nezoku LANGUAGES CXX)

find_package(FLEX 2.6 REQUIRED)
find_package(BISON 3.0 REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_LINKER_TYPE MOLD)
set(EXECUTABLE_OUTPUT_PATH /usr/local/bin)
set(SOURCES)

add_subdirectory(src)
