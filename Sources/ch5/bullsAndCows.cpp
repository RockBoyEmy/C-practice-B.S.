#include "std_lib_facilities.h"
#include "Windows.h"

bool check_identicality(vector<int> guessing, vector<int> guessed);
int check_bulls(vector<int> guessing, vector<int> guessed);
int check_cows(vector<int> guessing, vector<int> guessed);

int main()
try {
	int bulls, cows = 0;
	vector<int> guessingNo(4); 
	vector<int> guessedNo(4, 0); //vector of 4 zeroes
	int rand = 0;
	for (int r = 0; r < guessingNo.size(); r++)
	{
		//populating the vector with random numbers instead of hardcoding them
		rand = randint(9);
		guessingNo[r] = rand;
	}
	bool identical = check_identicality(guessingNo, guessedNo);
	while (!identical)
	{
		bulls = check_bulls(guessingNo, guessedNo);
		cows = check_cows(guessingNo, guessedNo);
		cout << "You have " << bulls << " bulls and " << cows << " cows." << endl;
		cout << "Guess the 4 numbers and insert them in the order you think they are:" << endl;
		for (int i = 0; i < guessedNo.size(); i++)
		{
			cin >> guessedNo[i];
		}
		identical = check_identicality(guessingNo, guessedNo);
	}
	cout << "You managed to guess all numbers correctly and in the correct order! Cograts!" << endl;
	
	return 0;
}
catch (exception& e) {
	cerr << "Problem: " << e.what() << endl;
}
catch (...) {
	cerr << "Unknown exception found" << endl;
}

bool check_identicality(vector<int> guessing, vector<int> guessed)
{
	//checks if the values inside the two vectors are identical and in identical order
	//post-cond: will return true if identical, false if not
	for (int i = 0; i < guessing.size(); i++)
	{
		if (guessing[i] != guessed[i])
		{
			return false;
		}
	}
	//if none are non-identical, then the loop will end, so..
	return true;
}

int check_bulls(vector<int> guessing, vector<int> guessed)
{
	//returns the number of guessed elements
	//identical and in identical position
	int bulls = 0;
	for (int i = 0; i < guessing.size(); i++)
	{
		if (guessing[i] == guessed[i])
		{
			bulls++;
		}
	}
	return bulls;
}

int check_cows(vector<int> guessing, vector<int> guessed)
{
	//returns the number of elements guessed
	//identical but that are in different positions
	int cows = 0;
	for (int i = 0; i < guessing.size(); i++)
	{
		for (int j = 0; j < guessed.size(); j++)
		{
			if (i == j)
			{
				//to avoid incrementing cows with bulls
				continue;
			}
			else if (guessing[i] == guessed[j])
			{
				cows++;
			}
		}
	}
	return cows;
}
