/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

#include <cstddef>

using std::size_t;

#include <deque>

using std::deque;

#include <queue>

#include <stack>

using std::stack;

#include <iostream>

using std::cout; using std::cerr; using std::endl;

bool process(int);

int main() {
    // c++标准库中有三个适配器，泛型中传入第二个参数，可以更改底层的默认容器类型
    // stack和queue默认时基于deque实现的
    // priority_queue默认是基于vector实现的
    stack<int> intStack;  // empty stack，stack在c++中是适配器

    // fill up the stack
    for (size_t ix = 0; ix != 10; ++ix) // 前缀++性能比较好，不需要保存临时值
        intStack.push(ix);   // intStack holds 0 . . . 9 inclusive

    // while there are still values in intStack
    while (!intStack.empty()) {
        int value = intStack.top(); // 获取栈顶元素，但是不弹出
        // code that uses value
        cout << value << endl;
        intStack.pop(); // pop the top element, and repeat
    }
//	std::queue<int> smallQueue;
//	smallQueue.push(2); // 放入队尾
//	smallQueue.emplace(2); // 使用提供的参数构造一个int，放入队尾
//	smallQueue.pop(); // 弹出元素，删除元素
//	smallQueue.front(); // 获取头元素
//	smallQueue.back(); // 获取尾元素
//    std::priority_queue<int> priorityQueue;
//	priorityQueue.push(2);
//	priorityQueue.emplace(3);
//	priorityQueue.pop(); // 弹出元素（删除元素）
//	priorityQueue.top(); // 弹出优先级最高的元素，不删除元素
    return 0;
}
