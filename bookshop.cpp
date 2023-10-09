#include "bookshop.h"

Bookshop::Bookshop()
{
	type = 'a';
}

Bookshop::~Bookshop() {}

const char Bookshop::get_type()
{
	return type;
}

void Bookshop::set_type(char type)
{
	this->type = type;
}