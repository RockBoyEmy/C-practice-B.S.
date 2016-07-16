#pragma once
#include "std_lib_facilities.h"
#include "ISBN.h"

class Book {
public:
	//getters
	ISBN get_isbn() const { return isbn_no; }
	string get_title() const { return title; }
	string get_author() const { return auth_name; }
	int get_c_date() const { return copyright_date; }
	//Genre genre() const { return g; }
	bool checked_out() const { return is_checked_out; }

	void check_in();
	void check_out();

	//constructors
	Book();
	Book(ISBN i, string title, string author, int c_date, bool checked_out);

private:
	ISBN isbn_no;
	string title;
	string auth_name;
	int copyright_date;
	bool is_checked_out;
};

const Book& default_book();
