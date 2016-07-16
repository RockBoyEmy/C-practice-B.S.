#include "Book.h"

const Book & default_book()
{
	static const Book b(ISBN(), "", "", 0, false);
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
	copyright_date(default_book().get_c_date()),
	is_checked_out(default_book().checked_out())
{
}

Book::Book(ISBN i, string title, string author, int c_date, bool checked_out)
	:isbn_no(i), title(title), auth_name(author), 
	copyright_date(c_date), is_checked_out(checked_out)
{
}
