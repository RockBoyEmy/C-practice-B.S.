#pragma once
#include "std_lib_facilities.h"
#include "Book.h"
#include "ISBN.h"
#include "Patron.h"
#include "Chrono.h"

class Library {

public:
	struct Transaction {
		Book aBook;
		Patron aPatron;
		Chrono::Date aDate;

		Transaction(Book bb, Patron pp, Chrono::Date dd);
		Transaction();
	};

	// constructors
	Library(vector<Book> books, vector<Patron> patrons, vector<Transaction> transactions);
	Library();

	// modifying operations:
	void add_book(const Book& b);
	void add_patron(const Patron& p);
	void check_out(Book& b, const Patron& p, const Chrono::Date& d);
	void set_fee(const Patron& p, double f);

	// nonmodifying operations:
	vector<Book> get_books() const { return books; }
	vector<Patron> get_patrons() const { return patrons; }
	vector<Transaction> get_transactions() const { return transactions; }
	vector<Patron> get_debtors() const; // list of patrons who owe fees

private:
	vector<Book> books;
	vector<Patron>patrons;
	vector<Transaction>transactions;
};