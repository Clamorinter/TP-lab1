#include "Keeper.h"

Keeper_Error::Keeper_Error(const std::string& message) : message(message) {}

const char* Keeper_Error::what() const noexcept
{
	return message.c_str();
}

Keeper::Keeper()
{
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

void Keeper::addMemberAfter(const Bookshop* member, int number)
{
	if (number >= length)
	{
		throw Keeper_Error("Invalid number of the previous Node");
	}
	if (number == -1)
	{

	}
}

void Keeper::deleteMember(int i)
{

}

int Keeper::get_length() const
{
	return length;
}