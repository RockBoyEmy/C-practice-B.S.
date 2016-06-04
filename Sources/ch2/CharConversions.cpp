#include "std_lib_facilities.h"

int main()
{
	int a = 20000;
	char c = a;
	int b = c;
	if (a != b)
	{
		cout << "ooops!: " << a << "!=" << b << '\n';
	}
	else
	{
		cout << "Wow, we have large characters\n";
	}

	return 0;
}