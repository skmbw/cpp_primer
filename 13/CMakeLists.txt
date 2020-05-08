cmake_minimum_required(VERSION 3.7)
project(cpp_primer_13)
set(CMAKE_CXX_STANDARD 14)

#add_library(Folder.o Folder.cc Folder.h)
#add_library(FolderMain.o FolderMain.cc Folder.h)
#add_library(StrFolder.o StrFolder.cc StrFolder.h Strings.h)
#add_library(StrFolderMain.o StrFolderMain.cc StrFolder.h Strings.h)
add_executable(useStrVec.exe StrVec.cc useStrVec.cc)
add_executable(FolderMain.exe Folder.cc FolderMain.cc) # (.h头文件貌似不需要)
# 后面把所有需要的源文件，不管时cpp还是头文件(.h头文件貌似不需要)，都列在后面就OK了，不需要配置生成.o文件。回自动生成。
add_executable(StrFolderMain.exe StrFolder.cc Strings.cc StrFolderMain.cc StrFolder.h Strings.h)
