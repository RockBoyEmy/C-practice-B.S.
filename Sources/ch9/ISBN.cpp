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