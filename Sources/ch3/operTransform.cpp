#include <iostream>
#include <string>
using namespace std;

int main()
{
	double var1, var2, result = 0;
	string operation = "";

	cout << "Insert the operator or operation name that you want to perform: ";
	cin >> operation;
	cout << "\nNow insert the two numbers you want to perform the operation on:\n";
	cin >> var1;
	cin >> var2;

	cout << operation << " " << var1 << " " << var2 << endl;

	if (operation == "+" || operation == "plus")
	{
		result = var1 + var2;
	}
	else if (operation == "-" || operation == "minus")
	{
		result = var1 - var2;
	}
	else if (operation == "*" || operation == "mul")
	{
		result = var1 * var2;
	}
	else if (operation == "/" || operation == "div")
	{
		result = var1 / var2;
	}

	cout << "And the result is: " << result << endl;

	return 0;
}