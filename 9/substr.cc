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

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <stdexcept>
using std::out_of_range;

int main()
{
	try {
		string s("hello world");
		cout << s.substr(0, 5) << endl;  // prints hello，从0到5，包含头，不包含尾[index1, index2)，index2 <= str.size()
		cout << s.substr(6) << endl;     // prints world，从6到结尾
		cout << s.substr(6, 11) << endl; // prints world，从6-11，不包含11，[index, size）前面闭区间，后面开区间
		cout << s.substr(12) << endl;    // throws out_of_range
		// 编译警告，要使用引用，同时打印异常信息 ex.what()
	} catch(out_of_range &ex) {cout << "caught out_of_range:" << ex.what() << endl; }

	return 0;
}
