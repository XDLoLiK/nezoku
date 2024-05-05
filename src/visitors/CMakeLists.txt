include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

list(
    APPEND SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/printing_visitor.cpp
)

set(SOURCES ${SOURCES} PARENT_SCOPE)
