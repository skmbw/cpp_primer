cmake_minimum_required(VERSION 3.7)
project(cpp_primer_1)

SET(CMAKE_CXX_STANDARD 14)

# set(SOURCE_FILES add.cc add_item.cc)
add_executable(add.exe add.cc)
add_executable(add_item.exe add_item.cc)
add_executable(add_item2.exe add_item2.cc)
add_executable(avg_price.exe avg_price.cc)
# 可执行文件的名字，可以自己指定
add_executable(for_ex for_ex.cc)

