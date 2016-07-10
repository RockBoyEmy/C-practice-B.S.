#include "std_lib_facilities.h"

void print(string s, vector<int>& v);
void fibonacci(int x, int y, vector<int>& v, int n);
void fibonacciMax(int x, int y, vector<int>& v);
int main()
try {
	vector<int> fib(2, 0); //vector has start with at least 2 elements
	int first, second, elementsNo = 0;
	cout << "Insert the first and the second values to populate the vector.\n";
	cout << "Then insert how many numbers of the Fibonacci string you want to add." << endl;
	cin >> first >> second >> elementsNo;
	//fibonacci(first, second, fib, elementsNo);
	fibonacciMax(first, second, fib);
	//print("this is the situation of the vector so far: ", fib);

	return 0;
}
catch (exception& e)
{
	cout << e.what() << endl;
}

void print(string s, vector<int>& v)
{
	if (v.size() < 1)
	{
		error("vector has no elements in it");
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << s << " " << v[i] << endl;
	}
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
	if (n < 1)
	{
		error("inserted invalid number of elements to add to vector");
	}
	int temp = 0;
	v[0] = x;
	v[1] = y;
	for (int i = 2; i < 2 + n; ++i)
	{
		temp = v[i - 1] + v[i - 2];	//sum of previous 2 positions
		v.push_back(temp);			//add another elements - the sum
	}
}

void fibonacciMax(int x, int y, vector<int>& v)
{
	if (v.size() < 1)
	{
		error("vector has no elements in it");
	}
	int temp = 0;
	v[0] = x;
	v[1] = y;
	for (int i = 2; ; ++i)
	{
		if (temp < 0)
		{
			break;
		}
		temp = v[i - 1] + v[i - 2];	//sum of previous 2 positions
		v.push_back(temp);			//add another elements - the sum
		cout << temp << endl;
	}
}
