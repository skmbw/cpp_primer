//
// Created by yinlei on 2020/5/6.
//
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool isShorter(const std::string & a, const std::string & b) {
    return a.size() >= b.size();
}

void elimDups(std::vector<std::string> & words) {
//    std::sort(words.begin(), words.end(), isShorter); // 这里不能使用谓词，否则就不是默认的字典序了，会有重复的the
    std::sort(words.begin(), words.end());

    // 返回指向最后一个不重复元素后的迭代器
    auto ret_iterator = std::unique(words.begin(), words.end());
    words.erase(ret_iterator, words.end());
    // 使用迭代器的普通for循环
    for(auto b = words.begin(); b != words.end(); ++b) {
        std::cout << *b << " ";
    }
    std::cout << std::endl; // 刷新缓存
}

int main() {
    vector<string> wordList;
    wordList.emplace_back("bigger");
    wordList.emplace_back("the");
    wordList.emplace_back("red");
    wordList.emplace_back("red");
    wordList.emplace_back("orange");
    wordList.emplace_back("the");
    wordList.emplace_back("small");
    wordList.emplace_back("ok");
    wordList.emplace_back("ok");
    wordList.emplace_back("yin");
    wordList.emplace_back("exercise");

    // 按字典排序，并删除重复的
    elimDups(wordList);
    // 按长度大小排序，不按字典序
    std::stable_sort(wordList.begin(), wordList.end(), isShorter);
    // 这个迭代根使用迭代器一样，这个更简介。foreach 循环
    for(auto & b : wordList) {
        std::cout << b << " ";
    }

    std::cout << std::endl;

    auto before_iterator = std::partition(wordList.begin(), wordList.end(), [](std::string & s)-> bool {return (s.length() > 4);});
    for (auto b = wordList.begin(); b != before_iterator; ++b) {
        std::cout << *b << " ";
    }
    std::cout << std::endl;

    return 0;
}




