//the inventor who wanted the double of the previous ammount of rice for chess squares
#include <iostream>
#include <vector>
using namespace std;

void displayStats(int currentSquare, int currentSquareGrains, int totalGrains);

int main()
{
	vector<int>theSquares(64);
	theSquares[0] = 1;
	int totalGrains = theSquares[0];
	int currentSquareGrains = theSquares[0];
	int targetGrains = 1000000000;
	int currentSquare = 0;

	for (currentSquare = 0; currentSquare < theSquares.size(); currentSquare++)
	{
		displayStats(currentSquare, currentSquareGrains, totalGrains);
		if (totalGrains < targetGrains)
		{
			theSquares[currentSquare + 1] = theSquares[currentSquare] * 2;
			currentSquareGrains = theSquares[currentSquare + 1];
			totalGrains += currentSquareGrains;
		}
		else
		{
			cout << "You have reached the target number of grains." << endl;
			break;
		}
	}

	return 0;
}

void displayStats(int currentSquare, int currentSquareGrains, int totalGrains)
{
	cout << "\nWe're currently on square number " << currentSquare << endl;
	cout << "This square can contain a total of " << currentSquareGrains << " grains." << endl;
	cout << "The total number of grains got so far is " << totalGrains << endl;
}
