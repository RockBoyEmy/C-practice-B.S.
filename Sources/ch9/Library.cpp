#include "Library.h"

Library::Library(vector<Book> books, vector<Patron> patrons, vector<Transaction> transactions)
	:books(books), patrons(patrons), 
	transactions(transactions)
{
}

const Library& default_library()
{
	vector<Book> b;
	vector<Patron> p;
	vector<Library::Transaction> t;
	static const Library l(b, p, t);
	return l;
}

Library::Library()
	:books(default_library().get_books()),
	patrons(default_library().get_patrons()),
	transactions(default_library().get_transactions())
{
}

void Library::add_book(const Book & b)
{
	for (int i = 0; i < books.size(); ++i)
	{
		if (b == books[i])	error("add_book(): book already in the library");
	}
	Book new_book = b;
	books.push_back(b);
}

void Library::add_patron(const Patron & p)
{
	for (int i = 0; i < patrons.size(); ++i)
	{
		if (p == patrons[i]) error("add_patron(): patron already exists");
	}
	patrons.push_back(p);
}

void Library::check_out(Book & b, const Patron & p, const Chrono::Date & d)
{
	int b_index = 0;
	bool book_exists = false;
	int p_index = 0;
	bool patron_exists = false; 

	//check if book exists
	for (int i = 0; i < books.size(); ++i)
	{
		if (b == books[i])
		{
			b_index = i;
			book_exists = true;
			break;
		}
	}
	if (!book_exists) error("check_out(): book isn't in the library");

	//check if patron exists
	for (int i = 0; i < patrons.size(); ++i)
	{
		if (p == patrons[i])
		{
			p_index = i;
			patron_exists = true;
			break;
		}
	}
	if (!patron_exists) error("check_out(): patron isn't in the library");

	// check if patron owes fees
	if (patrons[p_index].get_fees() > 0) error("check_out(): patron owes library fees");

	// create Transaction and check out the book
	transactions.push_back(Transaction(books[b_index], patrons[p_index], d));
	books[b_index].check_out();
}

void Library::set_fee(const Patron & p, double f)
{
	for (int i = 0; i < patrons.size(); ++i)
	{
		if (p == patrons[i])
		{
			patrons[i].set_fees(f);
			return;
		}
	}
	//if the patron exists, this point should never be reached, because using 'return'
	error("Library::set_fee(): patron doesn't exist");
}

vector<Patron> Library::get_debtors() const
{
	vector<Patron> debtors;
	for (int i = 0; i < patrons.size(); ++i)
	{
		if (patrons[i].get_fees() > 0)
			debtors.push_back(patrons[i]);
	}
	if (debtors.size() < 1)
	{
		cout << "There are no debtors here at the moment" << endl;
		return debtors;
	}
	else
		return debtors;
}

Library::Transaction::Transaction(Book bb, Patron pp, Chrono::Date dd)
	:aBook(bb), aPatron(pp), aDate(dd)
{
}

const Library::Transaction& default_transaction()
{
	static const Library::Transaction tt = Library::Transaction(Book(), Patron(), Chrono::Date());
	return tt;
}

Library::Transaction::Transaction()
	:aBook(default_transaction().aBook),
	aPatron(default_transaction().aPatron),
	aDate(default_transaction().aDate)
{
}