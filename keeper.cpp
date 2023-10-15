#include "Keeper.h"

Keeper::Keeper()
{

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

void Keeper::addMemberAfter(const Bookshop* member, int number)
{

}

void Keeper::deleteMember(int i)
{

}

int Keeper::get_length() const
{
	return length;
}