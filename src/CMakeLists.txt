include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(ast)
add_subdirectory(visitors)

FLEX_TARGET(
    SCANNER
    ${CMAKE_CURRENT_SOURCE_DIR}/scanner.l
    ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp
)

BISON_TARGET(
    PARSER
    ${CMAKE_CURRENT_SOURCE_DIR}/parser.y
    ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp
    COMPILE_FLAGS --graph
    DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/parser.hpp
)

ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)

add_executable(
    NEZOKU
    main.cpp
    ${SOURCES}
    driver.cpp
    scanner.cpp
    ${FLEX_SCANNER_OUTPUTS}
    ${BISON_PARSER_OUTPUTS}
)

target_compile_options(
    NEZOKU
    PRIVATE
    -ggdb3
   -Wall
   -Wextra
   -Wpedantic
)

set_target_properties(
    NEZOKU
    PROPERTIES
    OUTPUT_NAME nezoku
)

llvm_map_components_to_libnames(LLVM core)
target_link_libraries(NEZOKU ${LLVM})

