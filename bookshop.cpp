#include "bookshop.h"

Bookshop::Bookshop()
{
	type = 'a';
	defined = false;
}

Bookshop::~Bookshop() {}

char Bookshop::get_type() const
{
	return type;
}

void Bookshop::set_type(char type)
{
	this->type = type;
}

bool Bookshop::is_defined() const
{
	return defined;
}
void Bookshop::set_defined(bool def)
{
	defined = def;
}