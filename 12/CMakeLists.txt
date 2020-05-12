project(cpp_primer_12)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

add_executable(querymain querymain.cc TextQuery.cc TextQuery.h QueryResult.h)
add_executable(TextQueryProgram TextQueryProgram.cpp TextParser.cpp TextParser.h TextQueryResult.h)