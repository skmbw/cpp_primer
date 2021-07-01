cmake_minimum_required(VERSION 3.7)
project(cpp_primer)
set(CMAKE_CXX_STANDARD 14)
# include_directories() 用于添加 Headers 搜索路径（ -I 标志）， add_subdirectory() 在这种情况下没有区别
# 添加这个后，子目录中的CMakeLists.txt也会被编译，这样就是一整个项目了，子目录是项目中的一个模块
include_directories(. ./1 ./2 ./3 ./4 ./5 ./6 ./7 ./8 ./9 ./10 ./11 ./12 ./13 ./14 ./15 ./16 ./17 ./18 ./19 ./learn_boost)
add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)
add_subdirectory(10)
add_subdirectory(11)
add_subdirectory(12)
add_subdirectory(13)
add_subdirectory(14)
add_subdirectory(15)
add_subdirectory(16)
add_subdirectory(17)
add_subdirectory(18)
# 添加子目录
#ADD_SUBDIRECTORY(src_dir [binary_dir] [EXCLUDE_FROM_ALL])
#向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制的存放位置
#EXCLUDE_FROM_ALL含义：将这个目录从编译过程中排除
add_subdirectory(19)

# 生成可执行文件
#ADD_EXECUTABLE(可执行文件名  生成该可执行文件的源文件)

# 查找当前目录下的所有的源文件，并保存到SOURCE_DIRS宏变量中，后面就可以使用了
#aux_source_directory(. SOURCE_DIRS)
#add_executable(aa ${SOURCE_DIRS})

# 添加链接库，aa程序需要一个名为aa_lib的链接库
#target_link_libraries(aa aa_lib)

# add_library 将 src 目录中的源文件编译为静态链接库
#add_library(aa_lib ${SOURCE_DIRS})
#add_library(aa shared ${source_dirs})
#ADD_LIBRARY(libname [SHARED|STATIC|MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN)
#生成动态静态库，例：
#ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})

add_subdirectory(learn_boost)
