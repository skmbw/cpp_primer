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
    std::shared_ptr<std::vector<std::string>> bookLines;
    std::map<std::string, std::shared_ptr<std::set<int>>> wordLinesMap;
};


#endif //CPP_PRIMER_TEXTPARSER_H
