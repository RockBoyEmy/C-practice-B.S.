//The Quadratic Equation Calculator program
//Calculates equations and makes sure they work in all cases
#include "std_lib_facilities.h"

void quadratic_equation(double a, double b, double c);

int main()
{
	/*Quadratic Equation form:
		a*x^2 + b*x + c = 0
	
	Function resolution formula:
		x = (-b +- sqrt(b^2 - 4ac) ) / 2a
	*/

	double a, b, c, x = 0;
	cout << "Please insert the values of a, b and c, respectively:" << endl;
	cin >> a >> b >> c;
	quadratic_equation(a, b, c);

	return 0;
}

void quadratic_equation(double a, double b, double c)
{
	//pre-cond: a cannot be 0, and discriminant (b^2 + 4bc) cannot be less than 0
	//post-cond: will output the two solutions, but not return them
	if (a == 0)
	{
		cerr << "Impossible to proceed: a must be a value different than 0." << endl;
	}
	else
	{
		//calculates discriminant, won't be stored as a number if result is smaller than 0 (doesn't belong to R domain)
		double eqZero = pow(b, 2.0) - (4 * b*c);
		if (eqZero>=0)
		{
			double x1, x2 = 0;
			x1 = ((-b) + sqrt(pow(b, 2.0) - (4 * a*c))) / 2 * a;
			x2 = ((-b) - sqrt(pow(b, 2.0) - (4 * a*c))) / 2 * a;
			if (x1 == x2)
			{
				cout << "The equation roots are identical and are equal to " << x1 << endl;
			}
			else
			{
				cout << "This is x1: " << x1 << endl;
				cout << "This is x2: " << x2 << endl;
			}
		}
		else
		{
			cerr << "Impossible to proceed: the equation with the given values has no real roots." << endl;
		}
	}
}
