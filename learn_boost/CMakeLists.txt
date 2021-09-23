project(learn_boost)
cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 14)
# 添加编译参数 -l curl
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcurl")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcurl")
# 查找curl库，添加到项目中，不然编译会出现undefined reference to curl_global_init
find_package(CURL)
# 以下两条命令都需要，找到本地的libmyhtml.so共享库
find_library(myhtml libmyhtml.so /usr/local/lib)
link_directories(/usr/local/lib/)
# 包含boost库
#include_directories(/usr/local/include/boost)
#include_directories("/usr/include/boost")
#add_compile_options(-l curl)

add_executable(learn_boost learn_boost.cpp)

# 参数是：项目名，lib库名
target_link_libraries(learn_boost curl myhtml)