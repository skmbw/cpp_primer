# C++ Primer 学习笔记
* 这个是书中的例子的代码实现，不是课后习题的答案。

### CMakeList.txt 多级目录设置
* [cmakelists多级目录设置](https://blog.csdn.net/ktigerhero3/article/details/70313350)
* 每个目录下都要设置CMakeLists.txt文件，在根目录下，还要指定子目录

### CMakeLists.txt学习
* [cmakelists学习](https://blog.csdn.net/zhuiyunzhugang/article/details/88142908)

### 子项目调试
* 在各个子项目的CMakeLists.txt中配置好add_executable后，选择对应的可执行程序，进行debug即可

### centos7 配置预编译的suse的clang 10.0.0
* 首先 ./clang++ -v 看clang选择的是哪个gcc
* 如果版本低，可以在那个对应的目录下，软链接一个高版本的，我是7.1.0，如下：
* sudo ln -s /usr/local/lib/gcc/x86_64-pc-linux-gnu/7.1.0 /opt/rh/devtoolset-3/root/usr/lib/gcc/x86_64-redhat-linux/
* 这样，clang就能选择到最新的gcc了，可是运行会出现，找不到头文件的情况，是因为包含文件没有配置
* /opt/rh/devtoolset-3/root/usr/lib/gcc/x86_64-redhat-linux/7.1.0/../../../../include/c++/7.1.0/iostream:38:10: fatal error: 'bits/c++config.h' file not found
* 这个目录下的确是没有这个文件，到这个目录去软链接一下
* sudo ln -s /usr/local/include/c++/7.1.0 /usr/include/c++/
* 这样clang就应该配置好了（还是没有好）
* 应该还是没有配置好，iostream:38:10: 致命错误：bits/c++config.h：没有那个文件或目录
* 是因为的确没有这个文件。x86_64-pc-linux-gnu这个文件夹为空，需要将文件链接进来，在downlaods/gcc-7.1.0-build/x86_64-redhat-linux 复制过来的，
但是这个文件夹,引用了很多源码文件夹里的头文件，所以重新解压gcc-7.1.0，所以gcc-7.1.0这个文件夹不能删除。
* 根据规范，c++/7.1.0 下需要含有文件夹名字是x86_64-redhat-linux的文件夹，所以软链接
sudo ln -s /usr/include/c++/7.1.0/x86_64-pc-linux-gnu x86_64-redhat-linux

### gnome登录的时候会有声音
* 是因为更新打开了屏幕阅读器，点击右上角的小人-屏幕阅读器，关掉就好了

### clang的别名
* clang clang++ clang-cl clang-cpp都是clang-10的别名，也就是clang和clang++是一样的

### sh.exe was found in your PATH，sh.exe must not be in your path
* cmake中添加 -DCMAKE_SH="CMAKE_SH-NOTFOUND" 这个参数
* 或者在CMakeLists.txt中 set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

### clion无法使用vs toolchains的问题
* String.h影响了vs的头文件导入，导致不能导入正确的string.h，导致cstring中很多函数，不在全局命名空间中。将其改成Strings.h，就OK了
* linux下没有问题，因为linux是区分大小写的，但是windows其实不区分大小写的。
### CMakeLists.txt 配置生成.o文件的问题
* CMakeLists.txt 不需要配置生成 .o 对象文件，回自动生成
* add_executable(FolderMain.exe Folder.cc FolderMain.cc) # (.h头文件貌似不需要)，只需要列出对应的源文件就OK

### SSL certificate problem: self signed certificate in certificate chain
* clion没有网络，需要从网络获取数据签名，连上网络，从新pull就OK了

### 如果要在clion配置给main函数传参
* 在程序参数中，选择+，选择内置的宏变量，然后再写具体的参数。运行目录一般不需要写
* 如果要给main函数传一个string值，直接在program arguments中填入一个string值就好了；如："yinlei"
* 如果要添加文件的路径，可以选择使用宏变量，更简洁

### clion指定include的目录
* 在CMakeLists.txt文件中 include_directories(SYSTEM "/foo/bar")，这样就可以将/foo/bar目录下的头文件引入了

### class与struct
* class成员默认是private的，struct成员默认是public的
* class继承，默认是private继承，struct继承，默认是public继承

### CMakeLists.txt手动编译，生成可执行文件
* 进入项目的cmake-build-debug，然后进入对应的项目目录，然后make，就开始编译了
* ~~源码文件，只要在一个可执行文件中引入了原文件，就会被编译成.o对象文件，在其他可执行文件中需要，也不需要再次引入原文件~~
* 上面说的不对，还是需要引入的，对于CMakeLists.txt需要引入，如果是直接写makefile文件，就不需要重新编译了，编译后，可以在多个可执行文件引入

### linker command failed with exit code 1 (use -v to see invocation)
* 这个没有main方法，所以不能生成可执行程序
* 方法未定义，是因为真的没有定义，只写了.h头文件，没有在cpp中实现

### 安装boost库
* 解压文件，进入，执行 ./bootstrap.sh 可以指定--prefix参数，可以使用--help查询
* 然后使用 sudo ./b2 headers ~~install~~ 安装,不加sudo可能没有权限写文件到对应目录，不需要加install
* ubuntu 18.04安装后，so共享库在 /usr/local/lib下面,头文件在 /usr/local/include/boost/下面

### 全家桶更新
* 如果已经激活了，是可以更新的，更新就会下载patches文件
* 在linux上面，可能没有对应目录的权限，记得将 ex. idea-2020.1, chown yinlei idea-2020-1 -R

### ubuntu更新使用国内的阿里云/网易的源
* 先备份原来的 
`sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak` 
* 然后 `sudo vi /etc/apt/sources.list` 修改成如下
```text
deb http://mirrors.aliyun.com/ubuntu/ trusty main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ trusty-security main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ trusty-updates main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ trusty-proposed main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ trusty-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ trusty main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ trusty-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ trusty-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ trusty-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ trusty-backports main restricted universe multiverse
```
* 最后记得 `sudo apt update` 更新
* 如果是ros的arm架构安装的ubuntu，那么url中的/ubuntu/-->/ubuntu-ports/，记得哦
```text
deb http://mirrors.aliyun.com/ubuntu-ports/ trusty main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu-ports/ trusty-security main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu-ports/ trusty-updates main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu-ports/ trusty-proposed main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu-ports/ trusty-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu-ports/ trusty main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu-ports/ trusty-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu-ports/ trusty-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu-ports/ trusty-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu-ports/ trusty-backports main restricted universe multiverse
```
* ros中国科大的ubuntu镜像，同时含有amd64和arm的源