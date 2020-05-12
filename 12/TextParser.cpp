//
// Created by yinlei on 2020/5/12.
//

#include "TextParser.h"
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <memory>
#include "TextQueryResult.h"
#include <iostream>
#include <sstream>

using std::string;
using std::vector;
using std::ifstream;
using std::map;
using std::set;
using std::cout;
using std::endl;
using std::istringstream;

TextParser::TextParser(ifstream & ifs) {
    bookLines = std::make_shared<vector<string>>();

    string line;
    for (int i = 1; getline(ifs, line); ++i) {
        cout << line << endl;
        bookLines->push_back(line);

        istringstream wordStream(line);

        string rawWord;
        while (wordStream >> rawWord) {
            string word;
            for (auto s : rawWord) {
                if (!ispunct(s)) {
                    word += s;
                }
            }
            cout << word << endl;

            auto existIterator = wordLinesMap.find(word);
            if (existIterator == wordLinesMap.end()) { // 不存在
                auto wordLineSet = std::make_shared<set<int>>(set<int>{i});
                wordLinesMap.insert({word, wordLineSet});
            } else {
                existIterator->second->insert(i);
            }
        }
    }
}

TextQueryResult TextParser::query(std::string & word) {
    auto iterator = wordLinesMap.find(word);
    TextQueryResult result(word, bookLines, iterator->second);
    return result;
}
