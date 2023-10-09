#pragma once
#include "bookshop.h"
#include "book.h"
#include "textbook.h"
#include "office.h"

class Keeper
{
public:
	Keeper();
	Keeper(const Keeper& original);
	~Keeper();

	const void save_all(const std::ifstream &fin);
	void read_all(const std::ofstream &fout);

	void addMember(const Bookshop* member);
	void deleteMember(int i);

	int get_length();
private:
	Bookshop* storage;
	int length;
};