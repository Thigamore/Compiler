add_library(lexer lexer.cpp lexer.h token.cpp token.h)

target_include_directories(lexer PUBLIC "${CMAKE_SOURCE_DIR}")