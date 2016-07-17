/*Exercise 5, 6, 7, 8, 9, 10 from chapter 9 in B. Stroupstroup's book
Credits and a huge 'Thank you!' to bewuethr - part of these exercises are
inspired from code on his git repo, which I used while learning and understanding*/

#include "std_lib_facilities.h"
#include "Book.h"
#include "ISBN.h"
#include "Patron.h"
#include "Library.h"
using namespace Chrono;

void test_liber()
{
	// create library
	Library my_lib;

	// create and add books
	Book my_book(ISBN(9780, 4390, 2348, '1'),
		"The Hunger Games",
		"Collins, Suzanne",
		Book::fiction,
		2008,
		false);

	Book fake_book(ISBN(1111, 1111, 1111, 'x'),
		"Fake Book",
		"Nobody",
		Book::fiction,
		2000,
		false);

	my_lib.add_book(my_book);

	Book my_book2(ISBN(9780, 4393, 5807, '1'),
		"Harry Potter and the Order of the Phoenix",
		"Rowling, J.K.",
		Book::children,
		2003,
		false);
	my_lib.add_book(my_book2);

	my_lib.add_book(Book(ISBN(9781, 4165, 3932, '2'),
		"Einstein: His Life and Universe",
		"Isaacson, Walter",
		Book::biography,
		2007,
		false));

	my_lib.add_book(Book(ISBN(9780, 3160, 6760, '7'),
		"Lone Survivor",
		"Luttrell, Marcus",
		Book::nonfiction,
		2008,
		false));

	my_lib.add_book(Book(ISBN(1234, 5678, 1234, 'x'),
		"Triathlete Issue 2/14",
		"Competitor Group",
		Book::periodical,
		2014,
		false));

	// try to add book that already exists
	//my_lib.add_book(my_book);

	// print list of books
	cout << "All my books:\n\n";
	vector<Book> books = my_lib.get_books();
	for (int i = 0; i<books.size(); ++i) {
		cout << books[i] << endl;
	}

	// create and add patrons
	Patron my_patron1 = Patron("Forrest, Kara", 100, 0);
	my_lib.add_patron(my_patron1);
	Patron my_patron2 = Patron("Wuethrich, Benjamin", 101, 0);
	my_lib.add_patron(my_patron2);
	my_lib.add_patron(Patron("Buehler, Catriona", 102, 0));
	my_lib.add_patron(Patron("Schaerli, Tobias", 103, 0));
	my_lib.add_patron(Patron("Bieler, Ueli", 104, 0));
	Patron fake_patron(Patron("Shmoe, Joe", 999, 0));

	// try to add patron that already exists
	//my_lib.add_patron(my_patron1);

	// print list of patrons
	cout << "List of patrons:\n\n";
	vector<Patron> patrons = my_lib.get_patrons();
	for (int i = 0; i<patrons.size(); ++i) {
		cout << patrons[i].get_name() << ", " <<
			patrons[i].get_card() << endl;
	}

	// set library fees of two patrons
	my_lib.set_fee(my_patron1, 10);
	my_lib.set_fee(my_patron2, 15);

	// try to set fee for non-existing patron
	//my_lib.set_fee(Patron("NoName",999,0),99);

	// get and print list of debtors
	cout << "\nList of debtors:\n\n";
	vector<Patron> debtors = my_lib.get_debtors();
	for (int i = 0; i<debtors.size(); ++i) {
		cout << debtors[i].get_name() << ", " <<
			debtors[i].get_fees() << endl;
	}

	// check out book
	my_lib.check_out(my_book, patrons[2], Date(2014, Date::jan, 31));

	// print transaction vector
	cout << "\nTransactions:\n";
	vector<Library::Transaction> transactions = my_lib.get_transactions();
	for (int i = 0; i<transactions.size(); ++i) {
		cout << transactions[i].aBook <<
			transactions[i].aDate << endl <<
			transactions[i].aPatron.get_name() << endl;
	}

	// try to check out book which is already checked out
	//my_lib.check_out(my_book,patrons[2],Date(2014,Date::Month::jan,31));

	// try to check out book which doesn't exist in library
	//my_lib.check_out(fake_book,patrons[2],Date());

	// try to check out book for patron who doesn't exist
	//my_lib.check_out(my_book2,fake_patron,Date());

	// try to check out book for patron who owes fees
	//my_lib.check_out(my_book2, my_patron2, Date());
}

int main()
try {
	test_liber();
	//test_leapyear();
	//test_lineardate();

	return 0;
}
catch (Date::Invalid&) {
	cerr << "error: Invalid date\n";
	return 1;
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << endl;
}
catch (...) {
	cerr << "Exception\n";
}