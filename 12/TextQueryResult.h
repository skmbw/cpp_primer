//
// Created by yinlei on 2020/5/12.
//

#ifndef CPP_PRIMER_TEXTQUERYRESULT_H
#define CPP_PRIMER_TEXTQUERYRESULT_H

#include <set>

class TextQueryResult {
public:
    std::set<int> lines() {

    }

    void print() {

    }

private:
    std::shared_ptr<std::vector<std::string>> bookLines;
    std::shared_ptr<std::map<std::string, std::set<int>>> wordLinesMap;
};

#endif //CPP_PRIMER_TEXTQUERYRESULT_H
