cmake_minimum_required(VERSION 3.27)

project(Nezoku LANGUAGES C CXX)

find_package(FLEX 2.6 REQUIRED)
find_package(BISON 3.0 REQUIRED)
find_package(LLVM REQUIRED CONFIG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(SOURCES)

add_subdirectory(src)
