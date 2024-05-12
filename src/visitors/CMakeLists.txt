include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

list(
    APPEND SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/printing_visitor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/codegen_visitor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/scope.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/common.cpp
)

set(SOURCES ${SOURCES} PARENT_SCOPE)
