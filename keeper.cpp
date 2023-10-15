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
Keeper::Keeper(Bookshop* head)
{
	this->head = tail = nullptr;
	length = 0;
	insertMember(head);
}
Keeper::Keeper(const Keeper& original)
{
	head = tail = nullptr;
	length = 0;
	int count = original.get_length();
	for (int i = 0; i < count; i++)
	{
		insertMember(original.get_node(i-1)->data);
	}
}
Keeper::~Keeper()
{
	deleteAll();
}

void Keeper::save_all(std::ofstream& fout) const
{
	KeeperNode* node = head;
	for (int i = 0; i < length; i++)
	{
		node->data->fstream_out(fout);
		node = node->next;
		if (!node)
		{
			break;
		}
	}
}


void Keeper::read_all(std::ifstream& fin)
{
	char type;
	Bookshop* newData;
	while (!fin.eof())
	{
		fin >> type;
		switch (type)
		{
		case 'b':
			newData = new Book;
			break;
		case 'o':
			newData = new Office;
			break;
		case 't':
			newData = new Textbook;
			break;
		default:
			return;
		}
		newData->fstream_in(fin);
		length++;
	}
}

void Keeper::insertMember(Bookshop* member, int n = -1)
{
	if (n <= -1)
	{
		KeeperNode* newHead = new KeeperNode;
		newHead->prev = nullptr;
		newHead->next = head;
		newHead->data = member;
		if (head)
		{
			head->prev = newHead;
		}
		else
		{
			tail = newHead;
		}
		head = newHead;
		length++;
		return;
	}
	if (n >= length - 1)
	{
		KeeperNode* newTail = new KeeperNode;
		newTail->prev = tail;
		newTail->next = nullptr;
		newTail->data = member;
		if (tail)
		{
			tail->next = newTail;
		}
		else
		{
			head = newTail;
		}
		tail = newTail;
		return;
	}
	KeeperNode* newNode = new KeeperNode;
	KeeperNode* prevNode = get_node(n);
	newNode->prev = prevNode;
	newNode->next = prevNode->next;
	newNode->data = member;
	prevNode->next->prev = newNode;
	prevNode->next = newNode;
	length++;
	return;
}


void Keeper::deleteMember(int n = -1)
{
	if (length == 0)
	{
		throw Keeper_Error("Where are no elements in Keeper");
	}
	if (n <= -1)
	{
		KeeperNode* newHead = head->next;
		newHead->prev = nullptr;
		delete head->data;
		delete head;
		head = newHead;
		length--;
		return;
	}
	if (n >= length - 1)
	{
		KeeperNode* newTail = tail->prev;
		newTail->next = nullptr;
		delete tail->data;
		delete tail;
		tail = newTail;
		length--;
		return;
	}
	KeeperNode* deletingNode = get_node(n);
	deletingNode->prev->next = deletingNode->next;
	deletingNode->next->prev = deletingNode->prev;
	delete deletingNode->data;
	delete deletingNode;
	length--;
	return;
}

void Keeper::deleteAll()
{
	int count = length;
	for (int i = 0; i < count; i++)
	{
		deleteMember();
	}
}

void Keeper::printMember(int n = -1) const
{
	get_node(n)->data->iostream_out();
}

void Keeper::printAll() const
{
	int count = length;
	for (int i = 0; i < count; i++)
	{
		printMember(i);
	}
}

Keeper& Keeper::operator= (const Keeper& original)
{
	if (this == &original)
	{
		return *this;
	}
	deleteAll();
	head = tail = nullptr;
	length = 0;
	int count = original.get_length();
	for (int i = 0; i < count; i++)
	{
		insertMember(original.get_node(i-1)->data);
	}
	return *this;
}
Keeper Keeper::operator+ (const Keeper& second)
{
	Keeper sum(*this);
	KeeperNode* secNode = second.get_node(-1);
	while (secNode)
	{
		sum.insertMember(secNode->data, sum.get_length() - 1);
		secNode = secNode->next;
	}
	return sum;
}

int Keeper::get_length() const
{
	return length;
}
KeeperNode* Keeper::get_node(int n = -1)
{
	if (length == 0)
	{
		throw Keeper_Error("Invalid number of Node");
	}
	if (n <= -1)
	{
		n = 0;
	}
	if (n >= length - 1)
	{
		n = length - 1;
	}
	KeeperNode* Node;
	if (n <= length / 2)
	{
		Node = head;
		for (int i = 0; i < n; i++)
		{
			Node = Node->next;
		}
	}
	else
	{
		Node = tail;
		for (int i = 0; i < length - n; i++)
		{
			Node = Node->prev;
		}
	}
	return Node;
}

KeeperNode* Keeper::get_node(int n = -1) const
{
	if (length == 0)
	{
		throw Keeper_Error("Invalid number of Node");
	}
	if (n <= -1)
	{
		n = 0;
	}
	if (n >= length - 1)
	{
		n = length - 1;
	}
	KeeperNode* Node;
	if (n <= length / 2)
	{
		Node = head;
		for (int i = 0; i < n; i++)
		{
			Node = Node->next;
		}
	}
	else
	{
		Node = tail;
		for (int i = 0; i < length - n; i++)
		{
			Node = Node->prev;
		}
	}
	return Node;
}

void operator<< (std::ostream& os, const Keeper& keep)
{
	keep.printAll();
}

void operator<< (std::ofstream& fout, const Keeper& keep)
{
	keep.save_all(fout);
}

void operator>> (std::ifstream& fin, Keeper& keep)
{
	keep.read_all(fin);
}