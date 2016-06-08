//vector of names and correspondent ages
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string>names;
	vector<int>ages;
	string name = "";
	int age = 0;
	cout << "Input the name and the correspondent age, or NoName 0 to end." << endl;

	while (name != "NoName" || age != 0)
	{
		//populating the two vectors
		cin >> name >> age;
		for (int i = 0; i < names.size(); i++)
		{
			if (name == names[i])
			{
				cout << "Error, the name inserted is already present in the list. Loop ended." << endl;
				name = "NoName";
				age = 0;
			}
		}
		names.push_back(name);
		ages.push_back(age);
	}

	//displaying the results
	cout << "\nHere is the list of names and ages:\n";
	for (int i = 0; i < names.size() - 1; i++)
	{
		cout << names[i] << " " << ages[i] << endl;
	}
	
	cout << "\nInsert a name that you want to check: ";
	cin >> name;
	for (int i = 0; i < names.size(); i++)
	{
		if (name == names[i])
		{
			cout << "Found the name you were looking for. It's in position " << i << endl;
		}
		else
		{
			cout << "Name not found" << endl;
		}
	}

	return 0;
}
