#include "bookshop.h"

Bookshop::Bookshop()
{
	std::cout << "Bookshop constructor without parameters" << std::endl;
	type = 'a';
	defined = false;
}

Bookshop::~Bookshop() 
{
	std::cout << "Bookshop destructor" << std::endl;
}

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

bool Bookshop::cin_error_check(std::istream& cin)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return true;
	}
	return false;
}