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
		fin >> type_of >> color >> purpose >> price;
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
		std::cout << "Type of the object: " << type_of << std::endl;
		std::cout << "Color: " << color << std::endl;
		std::cout << "Purpose: " << purpose << std::endl;
		std::cout << "Price: " << price << std::endl;
	}
	else
		std::cout << "Not defined" << std::endl;
}

void Office::iostream_in()
{
	std::cout << "Type type of the object: ";
	std::cin >> type_of;
	std::cout << "Type color: ";
	std::cin >> color;
	std::cout << "Type purpose: ";
	std::cin >> purpose;
	std::cout << "Type price: ";
	std::cin >> price;
}

void Office::change_param()
{

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