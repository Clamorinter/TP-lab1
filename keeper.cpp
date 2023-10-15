#include "Keeper.h"

Keeper_Error::Keeper_Error(const std::string& message) : message(message) {}

const char* Keeper_Error::what() const noexcept
{
	return message.c_str();
}

Keeper::Keeper()
{
	head = tail = nullptr;
	length = 0;
}
Keeper::Keeper(const Bookshop* head)
{

}
Keeper::Keeper(const Keeper& original)
{

}
Keeper::~Keeper()
{

}

void Keeper::save_all(const std::ifstream& fin) const
{
	
}


void Keeper::read_all(const std::ofstream& fout)
{

}

void Keeper::insertMember(Bookshop* member, int n = 0)
{

}


void Keeper::deleteMember(int n = 0)
{

}

void Keeper::deleteAll()
{

}

void Keeper::printMember(int n = 0) const
{

}

void Keeper::printAll() const
{

}

Keeper& Keeper::operator= (const Keeper&)
{

}
Keeper Keeper::operator+ (const Keeper&)
{

}

int Keeper::get_length() const
{
	return length;
}
Bookshop* Keeper::get_node(int n = 0) const
{

}