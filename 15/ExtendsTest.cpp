//
// Created by yinlei on 2020/5/14.
//

#include "ParentClass.h"
#include "ChildClassPublicExtend.h"
#include "ChildClassProtectedExtend.h"
#include "ChildClassPrivateExtend.h"

#include <iostream>

void testExtends() {
    ParentClass parentClass;
    // 类对象只能访问自己的公有成员，不能访问受保护的protected的成员
    parentClass.publicParentMethod();
    std::cout << parentClass.publicParentString;

    ChildClassPublicExtend childClassPublicExtend;
    // 受保护的成员，自己类的对象也是不能访问的，只能是自己的子类，在子类内部访问。
//    childClassPublicExtend.childProtectedMethod();
    // 子类对象也只能访问父类的公有成员，以及自己的公有成员，不能访问受保护的protected的成员
    childClassPublicExtend.publicParentMethod();
    std::cout << childClassPublicExtend.publicParentString;

    ChildClassProtectedExtend childClassProtectedExtend;
    // protected继承，会将父类的公有成员变成protected的，那么子类是不能访问的
    childClassProtectedExtend.childPublicMethod();

    // private继承，会将父类的public和protected成员变成private的，就子类对象是不能访问父类的方法的。
    // 只有在子类内部，可以访问父类的public和protected成员。
    ChildClassPrivateExtend childClassPrivateExtend;
}

// linker command failed with exit code 1 (use -v to see invocation)
// 这个没有main方法，所以不能生成可执行程序
// testExtends 要在main上面定义
int main() {
//    float aa[2];
//    std::cout << sizeof(aa) / sizeof(aa[0]) << std::endl;
    testExtends();
}

