//The coin calculator program
//Calculates total number of cents based on coins provided

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int pennies = 1, nickels = 5, dimes = 10, quarters = 25, halfDollars = 50, oneDollars = 100;
	int penniesNo, nickelsNo, dimesNo, quartersNo, halfDollarsNo, oneDollarsNo = 0;
	double totalCents = 0.0;
	
	cout << "How many pennies do you have? ";
	cin >> penniesNo;
	pennies *= penniesNo;
	cout << "How many nickels do you have? ";
	cin >> nickelsNo;
	nickels *= nickelsNo;
	cout << "How many dimes do you have? ";
	cin >> dimesNo;
	dimes *= dimesNo;
	cout << "How many quarters do you have? ";
	cin >> quartersNo;
	quarters *= quartersNo;
	cout << "How many half dollars do you have? ";
	cin >> halfDollarsNo;
	halfDollars *= halfDollarsNo;
	cout << "How many whole dollars do you have? ";
	cin >> oneDollarsNo;
	oneDollars *= oneDollarsNo;

	if (penniesNo == 1)
		cout << "You have " << penniesNo << " pennie.\n";
	else
		cout << "You have " << penniesNo << " pennies.\n";

	return 0;
}