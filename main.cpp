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
	std::string filepath;
	std::ifstream fin;
	std::ofstream fout;
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
		std::cout << "What element do you want to delete?" << std::endl;
		keep.printAll();
		std::cout << ">";
		std::cin >> answer;
		try
		{
			keep.deleteMember(answer - 1);
			std::cout << "Successfully deleted." << std::endl;
		}
		catch (const Keeper_Error& err)
		{
			std::cout << "Keeper error: " << err.what() << std::endl;
		}
		system("pause");
		system("cls");
		break;

	case 3:
		std::cout << "What element do you want to change?" << std::endl;
		keep.printAll();
		std::cout << ">";
		std::cin >> answer;
		system("cls");
		try {
			keep.get_node(answer - 1)->data->change_param();
			std::cout << "Successfully changed." << std::endl;
		}
		catch (const Keeper_Error& err)
		{
			std::cout << "Keeper error: " << err.what() << std::endl;
		}
		system("pause");
		system("cls");
		break;
	case 4:
		std::cout << "Enter the path there you want to be elements saved: " << std::endl;
		std::cout << ">";
		std::cin >> filepath;
		fout.open(filepath);
		if (!fout)
		{
			std::cout << "Cannot open this file" << std::endl;
			system("pause");
			system("cls");
			return true;
		}
		fout << keep;
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