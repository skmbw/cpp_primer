//
// Created by yinlei on 2020/5/14.
//

#ifndef CPP_PRIMER_PARENTCLASS_H
#define CPP_PRIMER_PARENTCLASS_H

#include <string>

class ParentClass {
public:
    std::string publicParentString;
    void publicParentMethod();

protected:
    std::string protectedParentString;
    void protectedParentMethod();

private:
    std::string privateParentString;
    void pirvateParentMethod();
};


#endif //CPP_PRIMER_PARENTCLASS_H
