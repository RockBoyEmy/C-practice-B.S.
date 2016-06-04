//Exercise to test the usage of strings(?)
#include <iostream>
using namespace std;

int main()
{
	int n1, n2, n3 = 0;
	cout << "Enter the first number: ";
	cin >> n1;
	cout << "Enter the second number: ";
	cin >> n2;
	cout << "Enter the third number: ";
	cin >> n3;

	if (n2 >= n1)
	{
		if (n3 >= n2)
		{
			cout << n1 << ',' << n2 << ',' << n3;
		}
		else if (n3 >= n1)
		{
			cout << n1 << ',' << n3 << ',' << n2;
		}
		else
		{
			cout << n3 << ',' << n1 << ',' << n2;
		}
	}
	else
	{
		if (n3 >= n1)
		{
			cout << n2 << ',' << n1 << ',' << n3;
		}
		else if (n3>=n2)
		{
			cout << n2 << ',' << n3 << ',' << n1;
		}
		else
		{
			cout << n3 << ',' << n2 << ',' << n1;
		}
	}

	return 0;
}