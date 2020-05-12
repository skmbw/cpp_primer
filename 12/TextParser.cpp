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
    vector<string> bookLines; // 保存书中的所有行的内容
    map<string, set<int>> wordLineMap; // 保存单词和其所在行的映射
    string line;
    for (int i = 1; getline(ifs, line); ++i) {
        cout << line << endl;
        bookLines.push_back(line);

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

            auto existIterator = wordLineMap.find(word);
            if (existIterator == wordLineMap.end()) { // 不存在
                set<int> wordLineSet{i}; // 列表初始化
                wordLineMap.insert({word, wordLineSet});
            } else {
                existIterator->second.insert(i);
            }
        }
    }
}

TextQueryResult TextParser::query(std::string &word) {

}
