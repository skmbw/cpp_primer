cmake_minimum_required(VERSION 3.7)
project(cpp_primer_1)

set(CMAKE_CXX_STANDARD 14)

# set(SOURCE_FILES add.cc add_item.cc)
add_executable(add.exe add.cc)
add_executable(add_item add_item.cc)
add_executable(add_item2 add_item2.cc)
add_executable(avg_price avg_price.cc)
# 可执行文件的名字，可以自己指定
add_executable(for_ex for_ex.cc)
add_executable(forcount.exe forcount.cc)
add_executable(item_io.exe item_io.cc)
add_executable(main_only.exe main_only.cc)
add_executable(mysum.exe mysum.cc)
add_executable(occurs.exe occurs.cc)
add_executable(whilecount.exe whilecount.cc)
add_executable(shape Shape.cpp)

