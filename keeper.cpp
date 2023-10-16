#include "Keeper.h"

Keeper_Error::Keeper_Error(const std::string& message) : message(message) {}

const char* Keeper_Error::what() const noexcept
{
	return message.c_str();
}

Keeper::Keeper()
{
	std::cout << "Keeper constructor without parameters" << std::endl;
	head = tail = nullptr;
	length = 0;
}
Keeper::Keeper(Bookshop* head)
{
	std::cout << "Keeper constructor with parameters" << std::endl;
	this->head = tail = nullptr;
	length = 0;
	insertMember(head);
}
Keeper::Keeper(const Keeper& original)
{
	std::cout << "Keeper copy constructor" << std::endl;
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
	std::cout << "Keeper destructor" << std::endl;
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
	bool check;
	while (!fin.eof())
	{
		fin >> type;
		if (fin.eof())
		{
			break;
		}
		if (fin.fail())
		{
			break;
		}
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
		insertMember(newData, length - 1);
	}
}

void Keeper::insertMember(Bookshop* member, int n)
{
	if (length == 0)
	{
		n = -1;
	}
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
		tail = newTail;
		length++;
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


void Keeper::deleteMember(int n)
{
	if (length == 0)
	{
		throw Keeper_Error("Where are no elements in Keeper");
	}
	KeeperNode* deletingNode = get_node(n);
	if (deletingNode == head)
	{
		KeeperNode* newHead = head->next;
		if (newHead)
		{
			newHead->prev = nullptr;
		}
		delete head->data;
		delete head;
		head = newHead;
		length--;
		return;
	}
	if (deletingNode == tail)
	{
		KeeperNode* newTail = tail->prev;
		if (newTail)
		{
			newTail->next = nullptr;
		}
		delete tail->data;
		delete tail;
		tail = newTail;
		length--;
		return;
	}
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

void Keeper::printMember(int n) const
{
	get_node(n)->data->iostream_out();
}

void Keeper::printAll() const
{
	if (length == 0)
	{
		std::cout << "There are no elemets." << std::endl;
		return;
	}
	int count = length;
	for (int i = 0; i < count; i++)
	{
		std::cout << i + 1 << ". ";
		printMember(i);
	}
}

void Keeper::operator+= (const Keeper& second)
{
	KeeperNode* secNode = second.get_node(-1);
	while (secNode)
	{
		insertMember(secNode->data, get_length() - 1);
		secNode = secNode->next;
	}
	return;
}

int Keeper::get_length() const
{
	return length;
}
KeeperNode* Keeper::get_node(int n = 0)
{
	if (length == 0)
	{
		throw Keeper_Error("Invalid number of Node");
	}
	if (n <= 0)
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
		for (int i = 0; i < length - n-1; i++)
		{
			Node = Node->prev;
		}
	}
	return Node;
}

KeeperNode* Keeper::get_node(int n = 0) const
{
	if (length == 0)
	{
		throw Keeper_Error("Invalid number of Node");
	}
	if (n <= 0)
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
		for (int i = 0; i < length - n-1; i++)
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