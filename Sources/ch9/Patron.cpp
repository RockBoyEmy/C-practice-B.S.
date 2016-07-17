#include "Patron.h"

bool has_fees(const Patron& p)
{
	return (p.get_fees() > 0);
}

void Patron::set_fees(double fee)
{
	if (fee < 0)
		error("Patron::set_fees(): invalid fee added");
	fees = fee;
}

Patron::Patron()
	:name(default_patron().get_name()),
	card_number(default_patron().get_card()),
	fees(default_patron().get_fees())
{
}

Patron::Patron(string n, int card_no, double f)
	:name(n), card_number(card_no), fees(f)
{
}

const Patron& default_patron()
{
	static const Patron p("", 0, 0);
	return p;
}

bool operator==(const Patron& p1, const Patron& p2)
{
	return p1.get_card() == p2.get_card();
}
