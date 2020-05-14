//
// Created by yinlei on 2020/5/14.
//

#ifndef CPP_PRIMER_CHILDCLASSPRIVATEEXTEND_H
#define CPP_PRIMER_CHILDCLASSPRIVATEEXTEND_H

#include "ParentClass.h"
#include <iostream>

// 继承访问限制，不影响子类方法，访问父类成员，原来是什么访问限制，现在还是什么
class ChildClassPrivateExtend : private ParentClass {
public:
    ChildClassPrivateExtend() = default;
    void childPublicMethod() {
        // private继承，可以访问父类的public成员
        publicParentMethod();
        std::cout << publicParentString << std::endl;

        // private继承，可以访问父类的protected成员
        protectedParentMethod();
        std::cout << protectedParentString << std::endl;

        // 私有成员不能访问
    }
};


#endif //CPP_PRIMER_CHILDCLASSPRIVATEEXTEND_H
