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

#ifndef STRINGS_H
#define STRINGS_H

#include <cstring>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iostream>
#include <memory>
// 这个文件导致，ms vs 找错string.h这个头文件，改名后OK了
class Strings {
friend Strings operator+(const Strings&, const Strings&);
friend Strings add(const Strings&, const Strings&);
friend std::ostream &operator<<(std::ostream&, const Strings&);
friend std::ostream &print(std::ostream&, const Strings&);

public:
	Strings(): sz(0), p(0) { }

	// cp points to a null terminated array,
	// allocate new memory & copy the array
	Strings(const char *cp) :
	          sz(std::strlen(cp)), p(a.allocate(sz))
	          { std::uninitialized_copy(cp, cp + sz, p); }

	// copy constructor: allocate a new copy of the characters in s
	Strings(const Strings &s): sz(s.sz), p(a.allocate(s.sz))
	          { std::uninitialized_copy(s.p, s.p + sz , p); }

	Strings(size_t n, char c) : sz(n), p(a.allocate(n))
	          { std::uninitialized_fill_n(p, sz, c); }

	// allocates a new copy of the data in the right-hand operand;
	// deletes the memory used by the left-hand operand
	Strings &operator=(const Strings &);

	// unconditionally delete the memory because each String has its own memory
	~Strings() { if (p) a.deallocate(p, sz); }
public:
	// additional assignment operators
	Strings &operator=(const char*);         // car = "Studebaker"
	Strings &operator=(char);                // model = 'T'

	const char *begin()                         { return p; }
	const char *begin() const                   { return p; }
	const char *end()                      { return p + sz; }
	const char *end() const                { return p + sz; }

	size_t size() const                        { return sz; }
	void swap(Strings &s)
	                { char *tmp = p; p = s.p; s.p = tmp;
	                  std::size_t cnt = sz; sz = s.sz; s.sz = cnt; }
private:
	std::size_t sz;
	char *p ;
	static std::allocator<char> a;
};
Strings make_plural(size_t ctr, const Strings &, const Strings &);
inline
void swap(Strings &s1, Strings &s2)
{
	s1.swap(s2);
}

#endif
