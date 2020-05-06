//
// Created by yinlei on 2020/5/6.
//
#include <algorithm>
#include <vector>
#include <iostream>

bool isShorter(const std::string & a, const std::string & b) {
    return a.size() > b.size();
}

void elimDups(std::vector<std::string> &words) {
    std::stable_sort(words.begin(), words.end(), isShorter);

    // 返回指向最后一个不重复元素后的迭代器
    auto ret = std::unique(words.begin(), words.end());
    words.erase(ret, words.end());
}

int main() {

    return 0;
}




