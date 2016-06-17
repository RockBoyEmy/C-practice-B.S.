//Celsius to Kelvin converter program
//has many errors in it - supposed to correct them
#include "std_lib_facilities.h"

double cToK(double c);
double kToC(double k);

int main()
{
	double c = 0.0; //declare input variable
	cout << "Insert your temperature in Celsius: ";
	cin >> c; //retrieve temperature to input variable
	double k = cToK(c); //convert temperature
	cout << k << endl; //print out temperature
	cout << "\nInsert your temperature in Kelvin: ";
	cin >> k;
	c = kToC(k);
	cout << c << endl;

	return 0;
}

double cToK(double c)
{
	//pre-condition: argument is a valid temperature
	//post-condition: returns a positive or at least null K temperature
	const double MIN_CELSIUS = -273.15;
	if (c >= MIN_CELSIUS)
	{
		double kel = c + 273.15;
		return kel;
	}
	else
	{
		cerr << "Invalid celsius temperature inserted.\nMininum possible reachable temperature is -273.15\n";
	}

}

double kToC(double k)
{
	//pre-cond: kelvin temp can't be less than 0
	//post-cond: return a double that will be greater or equal to -273.15
	const double MIN_KELVIN = 0;
	if (k >= MIN_KELVIN)
	{
		double cel = k - 273.15;
		return cel;
	}
	else
	{
		cerr << "Invalid kelvin temperature inserted.\nMininum possible reachable temperature is 0\n";
	}
}
