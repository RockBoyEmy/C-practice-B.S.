//two functions that swap the elements in their respective vectors
//one creates another vector for it, the other makes modifications on same vector
#include "std_lib_facilities.h"

void populateVector(string vName, vector<int>& theVector);
void printVector(string s, const vector<int>& v);
vector<int> swapByValue(const vector<int>& v);
void swapByReference(vector<int>& v);

int main()
try {
	vector<int> vec1;
	populateVector("vec1", vec1);
	printVector("vec1: ", vec1);
	cout << endl;
	vector<int> vec3 = swapByValue(vec1);
	printVector("vec1 inverted: ", vec3);
	cout << endl;
	vector<int> vec2;
	populateVector("vec2", vec2);
	printVector("vec2: ", vec2);
	cout << endl;
	swapByReference(vec2);
	printVector("vec2 inverted: ", vec2);
	cout << endl;

	return 0;
}
catch (exception& e)
{
	cout << e.what() << endl;
}

void populateVector(string vName, vector<int>& theVector)
{
	cout << "Populate " << vName << ", insert only integers or press q to stop:" << endl;;
	for (int i = 0; ; i++)
	{
		char ch;
		cin >> ch;
		if (isdigit(ch))
		{
			cin.putback(ch);
			int number = 0;
			cin >> number;
			theVector.push_back(number);
		}
		else if (ch == 'q')
			break;
		else
			error("invalid input");
	}
}

void printVector(string s, const vector<int>& v)
{
	cout << s;
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
}

vector<int> swapByValue(const vector<int>& v)
	//creates new copy vector, does invertion of values in it then returns it
	//leaving the initia passed one unaltered
{
	if (v.size() < 2)
		error("vector has invalid number of elements");
	if (v.size() % 2 != 0)
		error("vector has an odd number of elements in it - can't perform complete swap");

	vector<int> copyV = v;			 //copy vector elements into new vector - same order
	int leftPos = 0;				 //first position in vector
	int rightPos = copyV.size() - 1; //last position in vector

	//stop swapping after the center positions of vector are reached
	while (leftPos < rightPos)
	{
		swap(copyV[leftPos], copyV[rightPos]);
		++leftPos;
		--rightPos;
	}

	return copyV;
}

void swapByReference(vector<int>& v)
	//inverts elements of the passed vector by reference, without need of any copy
{
	if (v.size() < 2)
		error("vector has invalid number of elements");
	if (v.size() % 2 != 0)
		error("vector has an odd number of elements in it - can't perform complete swap");

	int leftPos = 0;
	int rightPos = v.size() - 1;

	//stop swapping after the center positions of vector are reached
	while (leftPos < rightPos)
	{
		swap(v[leftPos], v[rightPos]);
		++leftPos;
		--rightPos;
	}
}
