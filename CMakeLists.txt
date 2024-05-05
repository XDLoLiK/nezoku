cmake_minimum_required(VERSION 3.27)

project(Nezoku LANGUAGES CXX)

find_package(FLEX 2.6 REQUIRED)
find_package(BISON 3.0 REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES)

add_subdirectory(src)
