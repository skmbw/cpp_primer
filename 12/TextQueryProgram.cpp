//
// Created by yinlei on 2020/5/12.
//

#include <map>
#include <set>
#include <fstream>
#include <vector>
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

int main() {
    // raw string 原生字符
    ifstream ifs(R"(C:\WorkSpace\CLionProjects\cpp_primer\12\data\storyDataFile)");

    vector<string> bookLines;
    map<string, set<int>> wordLineMap;
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

            auto existItr = wordLineMap.find(word);
            if (existItr == wordLineMap.end()) { // 不存在
                set<int> wordLineSet{i};
                wordLineMap.insert({word, wordLineSet});
            } else {
                existItr->second.insert(i);
            }
//            auto s = wordLineMap[word];
//            if (s.empty()) {
//                s = wordLineSet;
//            } else {
//                s.insert(word);
//            }
        }
    }
    cout << "finished." << endl;
}

