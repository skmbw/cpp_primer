cmake_minimum_required(VERSION 3.7)
project(cpp_primer_13)
set(CMAKE_CXX_STANDARD 14)

#add_library(Folder.o Folder.cc)
#add_library(StrFolder.o StrFolder.cc)
#add_executable(Strings.exe Strings.cc)
add_executable(StrFolderMain.exe Strings.cc StrFolderMain.cc Folder.cc StrFolder.cc)
