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
	totalCents = pennies + nickels + dimes + quarters + halfDollars + oneDollars;

	if (penniesNo == 1)
		cout << "You have " << penniesNo << " pennie.\n";
	else
		cout << "You have " << penniesNo << " pennies.\n";
	
	if (nickelsNo == 1)
		cout << "You have " << nickelsNo << " nickel.\n";
	else
		cout << "You have " << nickelsNo << " nickels.\n";
	
	if (dimesNo == 1)
		cout << "You have " << dimesNo << " dime.\n";
	else
		cout << "You have " << dimesNo << " dimes.\n";
	
	if (quartersNo == 1)
		cout << "You have " << quartersNo << " quarter.\n";
	else
		cout << "You have " << quartersNo << " quarters.\n";
	
	if (halfDollarsNo == 1)
		cout << "You have " << halfDollarsNo << " half dollar.\n";
	else
		cout << "You have " << halfDollarsNo << " half dollars.\n";
	
	if (oneDollarsNo == 1)
		cout << "You have " << oneDollarsNo << " whole dollar.\n";
	else
		cout << "You have " << oneDollarsNo << " whole dollars.\n";
	
	cout << "\nThe value of all your coins is " << totalCents << " cents." << endl;
	cout << "Basically you've got " << totalCents / 100 << " dollars.";
	return 0;
}
