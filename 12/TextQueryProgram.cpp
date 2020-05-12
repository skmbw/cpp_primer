//
// Created by yinlei on 2020/5/12.
//

#include <map>
#include <set>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include "TextParser.h"
#include "TextQueryResult.h"

using std::string;
using std::vector;
using std::ifstream;
using std::map;
using std::set;
using std::cout;
using std::endl;
using std::istringstream;

int main() {
    // raw string 原生字符
    ifstream ifs(R"(C:\WorkSpace\CLionProjects\cpp_primer\12\data\storyDataFile)");

    TextParser parser(ifs);
//    parser.parse(); // 执行解析，以备查询
    string queryWord("her");
    TextQueryResult queryResult = parser.query(queryWord);
    queryResult.print();

    vector<string> bookLines; // 保存书中的所有行的内容
    map<string, set<int>> wordLineMap; // 保存单词和其所在行的映射
    string line;
    for (int i = 1; getline(ifs, line); ++i) {
        cout << line << endl;
        bookLines.push_back(line);

        istringstream wordStream(line);

        string rawWord;
        while (wordStream >> rawWord) {
//            wordLineSet.insert(word);

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
    cout << "finished." << endl;
}

