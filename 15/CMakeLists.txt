project(cpp_primer_15)
cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 14)

add_executable(ExtendsTest ExtendsTest.cpp ParentClass.cpp ChildClassPublicExtend.cpp ChildClassProtectedExtend.cpp ChildClassPrivateExtend.cpp)

add_executable(andQueryTest andQueryTest.cc Query.cc)
add_executable(and_orQueryTest and_orQueryTest.cc)
add_executable(wordQueryTest wordQueryTest.cc)