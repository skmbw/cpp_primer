//
// Created by yinlei on 2020/5/12.
//

#ifndef CPP_PRIMER_TEXTPARSER_H
#define CPP_PRIMER_TEXTPARSER_H

#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include "TextQueryResult.h"

class TextParser {
public:
    TextParser(std::ifstream & fileStream);

//    void parse();
    TextQueryResult query(std::string & word);
private:
//    std::ifstream & ifs;
    std::shared_ptr<std::vector<std::string>> bookLines; // 保存书中的所有行的内容
    std::map<std::string, std::shared_ptr<std::set<int>>> wordLinesMap; // 保存单词和其所在行的映射
};


#endif //CPP_PRIMER_TEXTPARSER_H
