#include "Keeper.h"

bool menu(Keeper& keep);

int main(void)
{
	Keeper keep;
	while (menu(keep)) {};
	return 0;
}

bool menu(Keeper& keep)
{
	int answer; 
	Bookshop* member;
	std::cout << "Select an action:" << std::endl;
	std::cout << "1 - Add an element" << std::endl;
	std::cout << "2 - Delete an element" << std::endl;
	std::cout << "3 - Change element" << std::endl;
	std::cout << "4 - Save elements in file" << std::endl;
	std::cout << "5 - Load elements from file" << std::endl;
	std::cout << "6 - Show elements" << std::endl;
	std::cout << "0 - Exit program" << std::endl;
	std::cout << ">";
	std::cin >> answer;
	system("cls");
	switch (answer)
	{
	case 1:
		std::cout << "Choose a type:" << std::endl;
		std::cout << "1 - book" << std::endl;
		std::cout << "2 - textbook" << std::endl;
		std::cout << "3 - office" << std::endl;
		std::cout << "0 - go back" << std::endl;
		std::cout << ">";
		std::cin >> answer;
		switch (answer)
		{
		case 1:
			member = new Book;
			break;
		case 2:
			member = new Textbook;
			break;
		case 3:
			member = new Office;
			break;
		case 0:
			return true;
		default:
			return true;
		}
		member->iostream_in();
		keep.insertMember(member, keep.get_length()-1);
		std::cout << "Successfully added." << std::endl;
		system("pause");
		system("cls");
		break;
	case 2:

		break;

	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:
		keep.printAll();
		system("pause");
		system("cls");
		break;
	case 0:
		return false;
	}
	return true;
}