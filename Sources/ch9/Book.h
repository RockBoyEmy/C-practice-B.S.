#pragma once
#include "std_lib_facilities.h"
#include "ISBN.h"

class Book {
public:
	enum Genre { 
		fiction, nonfiction, periodical, biography, children 
	};
	
	//getters
	ISBN get_isbn() const { return isbn_no; }
	string get_title() const { return title; }
	string get_author() const { return auth_name; }
	int get_c_date() const { return copyright_date; }
	Genre get_genre() const { return genre; }
	bool checked_out() const { return is_checked_out; }

	void check_in();
	void check_out();

	//constructors
	Book();
	Book(ISBN i, string title, string author, Genre gen, int c_date, bool checked_out);

private:
	ISBN isbn_no;
	string title;
	string auth_name;
	Genre genre;
	int copyright_date;
	bool is_checked_out;
};

const Book& default_book();
bool operator==(const Book& b1, const Book& b2);
bool operator!=(const Book& b1, const Book& b2);
ostream& operator<<(ostream& os, const Book& b);