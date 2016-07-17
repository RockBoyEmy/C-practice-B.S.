#pragma once
#include "std_lib_facilities.h"

class Patron
{
public:
	//getters
	string get_name() const { return name; }
	int get_card() const { return card_number; }
	double get_fees() const { return fees; }

	void set_fees(double);

	Patron();
	Patron(string n, int card_no, double f);

private:
	string name;
	int card_number;
	double fees;
};

const Patron& default_patron();
bool has_fees(const Patron& p);
bool operator==(const Patron& p1, const Patron& p2);