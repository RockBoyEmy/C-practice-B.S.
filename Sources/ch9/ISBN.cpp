#include "ISBN.h"

bool is_isbn(int, int, int, char x)
{
	return isalpha(x) || isdigit(x);
}

const ISBN & default_isbn()
{
	static const ISBN i(0, 0, 0, '0');
	return i;
}

bool operator==(const ISBN & i1, const ISBN & i2)
{
	//checks every portion of the ISBN of the two numbers, simultaneously
	return (i1.n1 == i2.n1 && i1.n2 == i2.n2 && i1.n3 == i2.n3 && i1.x == i2.x);
}

ostream & operator<<(ostream & os, const ISBN & i)
{
	os << i.n1 << '-' << i.n2 << '-' << i.n3 << '-' << i.x;
	return os;
}

ISBN::ISBN()
	:n1(default_isbn().n1),
	n2(default_isbn().n2),
	n3(default_isbn().n3),
	x(default_isbn().x)
{
}

ISBN::ISBN(int n1, int n2, int n3, char x)
	:n1(n1), n2(n2), n3(n3), x(x)
{
	if (!is_isbn(n1, n2, n3, x)) error("is_isbn(): invalid number");
}