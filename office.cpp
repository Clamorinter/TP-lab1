#include "office.h"

Office::Office()
{
	set_type('o');
	set_defined(false);
}
Office::Office(std::string type_of, std::string color,
	std::string purpose, double price) :
	type_of(type_of), color(color), purpose(purpose), price(price) 
{
	set_type('o');
	set_defined(true);
};
Office::Office(const Office& original)
{
	set_defined(original.is_defined());
	set_type(original.get_type());
	if (is_defined())
	{
		type_of = original.get_type_of();
		color = original.get_color();
		purpose = original.get_purpose();
		price = original.get_price();
	}
}
Office::~Office() {}

void Office::fstream_in(std::ifstream& fin)
{
	bool defined;
	set_type('o');
	fin >> defined;
	set_defined(defined);
	if (defined)
	{
		fin.ignore();
		std::getline(fin, type_of);
		fin >> color;
		fin.ignore();
		std::getline(fin, purpose);
		fin >> price;
	}
}
void Office::fstream_out(std::ofstream& fout) const
{
	fout << get_type() << std::endl << is_defined() << std::endl;
	if (is_defined())
	{
		fout << type_of << std::endl << color << std::endl << purpose
			<< std::endl << price << std::endl;
	}
}

void Office::iostream_out() const
{
	std::cout << "Type: Office" << std::endl;
	if (is_defined())
	{
		std::cout << "\tType of the object: " << type_of << std::endl;
		std::cout << "\tColor: " << color << std::endl;
		std::cout << "\tPurpose: " << purpose << std::endl;
		std::cout << "\tPrice: " << price << std::endl;
	}
	else
		std::cout << "\tNot defined" << std::endl;
}

void Office::iostream_in()
{
	std::cout << "Type type of the object: ";
	std::cin.ignore();
	std::getline(std::cin, type_of);
	std::cout << "Type color: ";
	std::cin >> color;
	std::cout << "Type purpose: ";
	std::cin.ignore();
	std::getline(std::cin, purpose);
	std::cout << "Type price: ";
	std::cin >> price;
	set_defined(true);
}

void Office::change_param()
{
	if (!is_defined())
	{
		return; //place for a throw
	}
	int answer;
	std::cout << "Which parameter do you want to change?" << std::endl;
	std::cout << "1 - type of the object" << std::endl;
	std::cout << "2 - color" << std::endl;
	std::cout << "3 - purpose" << std::endl;
	std::cout << "4 - price" << std::endl;
	std::cout << ">";
	std::cin >> answer;
	switch (answer)
	{
	case 1:
		std::cout << "Old type of the object: " << type_of << std::endl;
		std::cout << "New type of the object: ";
		std::cin.ignore();
		std::getline(std::cin, type_of);
		break;
	case 2:
		std::cout << "Old color: " << color << std::endl;
		std::cout << "New color: ";
		std::cin >> color;
		break;
	case 3:
		std::cout << "Old purpose: " << purpose << std::endl;
		std::cout << "New purpose: ";
		std::cin.ignore();
		std::getline(std::cin, purpose);
		break;
	case 4:
		std::cout << "Old price: " << price << std::endl;
		std::cout << "New price: ";
		std::cin >> price;
		break;
	}
}

std::string Office::get_type_of() const
{
	return type_of;
}
std::string Office::get_color() const
{
	return color;
}
std::string Office::get_purpose() const
{
	return purpose;
}
double Office::get_price() const
{
	return price;
}

void Office::set_type_of(std::string type_of)
{
	this->type_of = type_of;
}
void Office::set_color(std::string color)
{
	this->color = color;
}
void Office::set_purpose(std::string purpose)
{
	this->purpose = purpose;
}
void Office::set_price(double price)
{
	this->price = price;
}