cmake_minimum_required(VERSION 3.0.0)
project(Learning VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Learning main.cpp)

add_subdirectory(fileIO)
add_subdirectory(lexer)
add_subdirectory(parser)
target_link_libraries(Learning PUBLIC fileIO lexer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
