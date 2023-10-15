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

class Keeper_Error : public std::exception
{
public:
	Keeper_Error(const std::string& message);
	const char* what() const noexcept override;
private:
	std::string message;
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

	void insertMember(Bookshop* member, int n = 0);

	void deleteMember(int n);
	void deleteAll();

	void printMember(int n) const;
	void printAll() const;

	Keeper& operator= (const Keeper&);
	Keeper operator+ (const Keeper&);

	int get_length() const;
	Bookshop* get_node(int n) const;
private:
	KeeperNode* head;
	KeeperNode* tail;
	int length;
};