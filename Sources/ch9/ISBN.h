#pragma once
#include "std_lib_facilities.h"

// type for ISBN of the form n-n-n-x
struct ISBN {
	int n1;
	int n2;
	int n3;
	char x; // digit or letter

	// constructors
	ISBN(int n1, int n2, int n3, char x);
	ISBN();
};

bool is_isbn(int n1, int n2, int n3, char x);
const ISBN& default_isbn();
bool operator==(const ISBN& i1, const ISBN& i2);
ostream& operator<<(ostream& os, const ISBN& i);