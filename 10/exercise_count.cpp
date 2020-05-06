//
// Created by yinlei on 2020/5/6.
//

#include <algorithm>
#include <vector>
#include <iostream>

int main() {
//    std::vector<int> ints(17); // 初始化17个默认值,那后面添加的都是在17个元素的后面呀!
    std::vector<int> ints; // 初始化17个默认值,那后面添加的都是在17个元素的后面呀!
    ints.reserve(17); // 在循环之前,预分配容量大小,可以提高性能吧,不然clion给出警告
    for (int i = 0; i < 10; ++i) {
        ints.push_back(i);
    }

    ints.push_back(3);
    ints.push_back(2);
    ints.push_back(4);
    ints.push_back(6);
    ints.push_back(9);
    ints.push_back(4);
    ints.push_back(6);

    auto ret = std::count(ints.begin(), ints.end(), 6);

    std::cout << "the 6 occurs = " << ret << " count." << std::endl;

    return 0;
}

