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

#include <cstring>
using std::strlen;

#include <algorithm>
using std::copy;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::ostream;

#include <utility>
using std::swap;

#include <memory>
using std::uninitialized_copy;

#include "Strings.h"

// define the static allocator member
std::allocator<char> Strings::a;

// copy-assignment operator
Strings & Strings::operator=(const Strings &rhs)
{
	// copying the right-hand operand before deleting the left handles self-assignment
    char *newp = a.allocate(rhs.sz); // copy the underlying Strings from rhs
	uninitialized_copy(rhs.p, rhs.p + rhs.sz, newp);

	if (p)
		a.deallocate(p, sz); // free the memory used by the left-hand operand
	p = newp;    // p now points to the newly allocated Strings
	sz = rhs.sz; // update the size

    return *this;
}

Strings& Strings::operator=(const char *cp)
{
	if (p) a.deallocate(p, sz);
	p = a.allocate(sz = strlen(cp));
	uninitialized_copy(cp, cp + sz, p);
	return *this;
}

Strings& Strings::operator=(char c)
{
	if(p) a.deallocate(p, sz);
	p = a.allocate(sz = 1);
	*p = c;
	return *this;
}

// named functions for operators
ostream &print(ostream &os, const Strings &s)
{
	const char *p = s.begin();
	while (p != s.end())
		os << *p++ ;
	return os;
}

Strings add(const Strings &lhs, const Strings &rhs)
{
	Strings ret;
	ret.sz = rhs.size() + lhs.size();   // size of the combined Strings
	ret.p = Strings::a.allocate(ret.sz); // allocate new space
	uninitialized_copy(lhs.begin(), lhs.end(), ret.p); // copy the operands
	uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
	return ret;  // return a copy of the newly created Strings
}

// return plural version of word if ctr isn't 1
Strings make_plural(size_t ctr, const Strings &word,
                               const Strings &ending)
{
        return (ctr != 1) ?  add(word, ending) : word;
}

// chapter 14 will explain overloaded operators
ostream &operator<<(ostream &os, const Strings &s)
{
	return print(os, s);
}

Strings operator+(const Strings &lhs, const Strings &rhs)
{
	return add(lhs, rhs);
}

