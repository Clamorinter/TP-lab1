#pragma once
#include "bookshop.h"
#include "book.h"
#include "textbook.h"
#include "office.h"

class KeeperNode
{
public:
	Bookshop* data = nullptr;
	KeeperNode* next = nullptr;
	KeeperNode* prev = nullptr;
};

class Keeper
{
public:
	Keeper();
	Keeper(const Bookshop* member);
	Keeper(const Keeper& original);
	~Keeper();

	void save_all(const std::ifstream &fin) const;
	void read_all(const std::ofstream &fout);

	void addMemberAfter(const Bookshop* member, int number);
	void deleteMember(int i);

	int get_length() const;
private:
	KeeperNode* head;
	KeeperNode* tail;
	int length;
};