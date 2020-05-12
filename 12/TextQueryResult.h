//
// Created by yinlei on 2020/5/12.
//

#ifndef CPP_PRIMER_TEXTQUERYRESULT_H
#define CPP_PRIMER_TEXTQUERYRESULT_H

#include <set>
#include <vector>
#include <iostream>
#include <memory>

class TextQueryResult {
public:
    TextQueryResult() = default;
    TextQueryResult(std::string & words,
            std::shared_ptr<std::vector<std::string>> bookLines,
            std::shared_ptr<std::set<int>> wordLineSet):
            queryWords(words),
            bookLines(std::move(bookLines)),
            wordLineSet(std::move(wordLineSet)) {}; // 使用move避免不必要的拷贝
    std::set<int> lines() {

    }

    void print() {
        auto b = wordLineSet->cbegin();
        auto e = wordLineSet->cend();
        for (; b != e; ++b) {
//            int index = *b - 1; // vector的索引从0开始的
//            std::cout << bookLines->at(index) << std::endl;
            std::cout << bookLines->at(*b) << std::endl;
        }
    }

private:
    std::string queryWords;
    std::shared_ptr<std::vector<std::string>> bookLines;
    std::shared_ptr<std::set<int>> wordLineSet;
};

#endif //CPP_PRIMER_TEXTQUERYRESULT_H
