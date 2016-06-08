//The Vector number-literal converter
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int input = 0;
	vector<string>litNos = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	cout << "Insert a number from 0 to 9: ";
	cin >> input;
	for (int i = 0; i < litNos.size(); ++i)
	{
		if (input == i)
		{
			cout << "here's your literal number: " << litNos[input] << endl;
			i = litNos.size(); //to break the loop immediately
		}
	}
	cout << "\nLet's keep going and try the program the other way round, shall we?" << endl;
	string input2 = "";
	cin >> input2;
	for (int i = 0; i < litNos.size(); ++i)
	{
		if (input2 == litNos[i])
		{
			cout << "here's your correspondent number: " << i << endl;
			i = litNos.size(); //to break the loop immediately
		}
	}

	return 0;
}
