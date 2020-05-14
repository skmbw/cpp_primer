//
// Created by yinlei on 2020/5/14.
//

#ifndef CPP_PRIMER_CHILDCLASSPUBLICEXTEND_H
#define CPP_PRIMER_CHILDCLASSPUBLICEXTEND_H

#include "ParentClass.h"
#include <iostream>

// 继承访问限制，不影响子类方法，访问父类成员（方法或者属性），原来是什么访问限制，现在还是什么
// 就是在子类内部可以访问父类的public和protected受保护成员，但是子类对象，仍然不能访问父类的受保护成员
class ChildClassPublicExtend : public ParentClass {
public:
    void childPublicMethod() {
        // public继承，可以访问父类的public成员
        publicParentMethod();
        std::cout << publicParentString << std::endl;

        // public继承，可以访问父类的protected成员
        protectedParentMethod();
        std::cout << protectedParentString << std::endl;

        // 私有成员不能访问
    }

protected:
    // 受保护的成员，自己类的对象也是不能访问的，只能是自己的子类，在子类内部访问。
    void childProtectedMethod();
    std::string childProtectedString;
};


#endif //CPP_PRIMER_CHILDCLASSPUBLICEXTEND_H
