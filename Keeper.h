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
	Keeper(Bookshop* member);
	Keeper(const Keeper& original);
	~Keeper();

	void save_all(std::ofstream &fout) const;
	void read_all(std::ifstream &fin);

	void insertMember(Bookshop* member, int n = -1);

	void deleteMember(int n = -1);
	void deleteAll();

	void printMember(int n = -1) const;
	void printAll() const;

	Keeper& operator= (const Keeper& original);
	Keeper operator+ (const Keeper& second);

	int get_length() const;
	KeeperNode* get_node(int n);
	KeeperNode* get_node(int n) const;

	friend void operator<< (std::ostream& os, const Keeper& keep);

	friend void operator<< (std::ofstream& fout, const Keeper& keep);
	friend void operator>> (std::ifstream& fin, Keeper& keep);
private:
	KeeperNode* head;
	KeeperNode* tail;
	int length;
};