project(cpp_primer_15)
cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 14)

add_executable(ExtendsTest ExtendsTest.cpp ParentClass.cpp ChildClassPublicExtend.cpp ChildClassProtectedExtend.cpp ChildClassPrivateExtend.cpp)