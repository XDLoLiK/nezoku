include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

list(
    APPEND SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/translation_unit.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/function_definition.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/declaration.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/compound_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/return_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/expression_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/break_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/continue_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selection_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/iteration_statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/assignment_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logical_or_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logical_and_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inclusive_or_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exclusive_or_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/and_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/eq_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/neq_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/less_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/greater_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/leq_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/geq_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/shl_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/shr_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/add_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sub_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mul_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/div_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mod_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/function_call_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/identifier_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/constant_expression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/string_expression.cpp
)

set(SOURCES ${SOURCES} PARENT_SCOPE)
