#include "Book.h"

const Book & default_book()
{
	static const Book b(ISBN(), "", "", Book::fiction, 0, false);
	return b;
}

void Book::check_in()
{
	if (!checked_out()) error("book already checked-in");
	is_checked_out = false;
}

void Book::check_out()
{
	if (checked_out()) error("book already cheked-out");
	is_checked_out = true;
}

Book::Book()
	:isbn_no(default_book().get_isbn()),
	title(default_book().get_title()),
	auth_name(default_book().get_author()),
	genre(default_book().get_genre()),
	copyright_date(default_book().get_c_date()),
	is_checked_out(default_book().checked_out())
{
}

Book::Book(ISBN i, string title, string author, Genre gen, int c_date, bool checked_out)
	:isbn_no(i), title(title), auth_name(author), genre(gen),
	copyright_date(c_date), is_checked_out(checked_out)
{
}

bool operator==(const Book& b1, const Book& b2)
{
	return (b1.get_isbn() == b2.get_isbn());
}

bool operator!=(const Book& b1, const Book& b2)
{
	return !(b1 == b2);
}

ostream & operator<<(ostream & os, const Book & b)
{
	os << b.get_title() << '\n' << b.get_author() << '\n' << b.get_isbn() << endl;
	return os;
}
