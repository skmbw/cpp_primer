# C++ Primer 学习笔记

### CMakeList.txt 多级目录设置
* [cmakelists多级目录设置](https://blog.csdn.net/ktigerhero3/article/details/70313350)
* 每个目录下都要设置CMakeLists.txt文件，在根目录下，还要指定子目录

### CMakeLists.txt学习
* [cmakelists学习](https://blog.csdn.net/zhuiyunzhugang/article/details/88142908)

### 子项目调试
* 在各个子项目的CMakeLists.txt中配置号add_executable后，选择对应的可执行程序，进行debug即可

### centos7 配置预编译的suse的clang 10.0.0
* 首先 ./clang++ -v 看clang选择的是哪个gcc
* 如果版本低，可以在那个目录软链接高版本的，我是7.1.0，如下：
* sudo ln -s /usr/local/lib/gcc/x86_64-pc-linux-gnu/7.1.0 /opt/rh/devtoolset-3/root/usr/lib/gcc/x86_64-redhat-linux/
* 这样，clang就能选择到最新的gcc了，可是运行会出现，找不到头文件的情况，是因为包含文件没有配置
* /opt/rh/devtoolset-3/root/usr/lib/gcc/x86_64-redhat-linux/7.1.0/../../../../include/c++/7.1.0/iostream:38:10: fatal error: 'bits/c++config.h' file not found
* 到这个目录取软链接一下
* sudo ln -s /usr/local/include/c++/7.1.0 /usr/include/c++/
* 这样clang就应该配置好了
* 应该还是没有配置好，iostream:38:10: 致命错误：bits/c++config.h：没有那个文件或目录
* 是因为的确没有这个文件。这个文件夹未空，需要将文件链接进来，在downlaods/gcc-7.1.0-build/x86_64-redhat-linux 复制过来的，
但是这个文件夹,引用了很多源码文件夹里的头文件，所以重新解压gcc-7.1.0，所以gcc-7.1.0这个文件夹不能删除。