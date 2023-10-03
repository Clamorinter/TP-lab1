#pragma once
#include "bookshop.h"
#include "book.h"
#include "textbook.h"
#include "office.h"

class KeeperNode
{
public:
	KeeperNode();
	KeeperNode(Bookshop* value, Bookshop* previous, Bookshop* next);
	KeeperNode(const KeeperNode& original);
	~KeeperNode();
private:
	Bookshop* value;
	Bookshop* previous;
	Bookshop* next;
};

class Keeper
{
public:
	const void save_all(const std::ifstream &fin);
	void read_all(const std::ofstream &fout);

	void insert_begin(Bookshop* value);
	void insert_end(Bookshop* value);

/*	void remove_node(..) 
	
*/
private:
	KeeperNode head;
	KeeperNode tail;
	KeeperNode node;
};