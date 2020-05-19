//
// Created by yinlei on 2020/5/19.
//

#ifndef CPP_PRIMER_LEARN_BOOST_H
#define CPP_PRIMER_LEARN_BOOST_H

#include "boost/make_unique.hpp"
#include <memory>

class learn_boost {
private:
    std::unique_ptr<std::string> uniquePtr = boost::make_unique<std::string>()
};


#endif //CPP_PRIMER_LEARN_BOOST_H
