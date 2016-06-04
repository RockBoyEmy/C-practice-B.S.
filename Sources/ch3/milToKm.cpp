#include <iostream>
using namespace std;

int main1()
{
	double mil = 0.0;
	cout << "Insert the number of miles you want to convert: ";
	cin >> mil;
	double km = mil*1.609;
	cout << "There's the equivalent in km: " << km << endl;

	return 0;
}