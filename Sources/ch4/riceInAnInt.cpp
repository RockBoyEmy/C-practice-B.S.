//the inventor who wanted the double of the previous ammount of rice for chess squares
#include <iostream>
#include <vector>
using namespace std;

void displayStats(int currentSquare, double currentSquareGrains, double totalGrains);

int main()
{
	vector<int>theSquares(64);
	theSquares[0] = 1;
	double totalGrains = theSquares[0];
	double currentSquareGrains = theSquares[0];
	int currentSquare = 0;

	for (currentSquare = 0; currentSquare < theSquares.size(); currentSquare++)
	{
		displayStats(currentSquare, currentSquareGrains, totalGrains);
		currentSquareGrains *= 2;
		totalGrains += currentSquareGrains;
	}

	return 0;
}

void displayStats(int currentSquare, double currentSquareGrains, double totalGrains)
{
	cout << "\nWe're currently on square number " << currentSquare << endl;
	cout << "This square can contain a total of " << currentSquareGrains << " grains." << endl;
	cout << "The total number of grains got so far is " << totalGrains << endl;
}
