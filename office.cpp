#include "office.h"

Office::Office()
{

}
Office::Office(std::string type_of, std::string color,
	std::string purpose, double price) :
	type_of(type_of), color(color), purpose(purpose), price(price) {};
Office::Office(const Office& original)
{

}
Office::~Office()
{

}

void Office::fstream_in(const std::ifstream& fin)
{

}
Bookshop* Office::fstream_out(const std::ofstream& fout)
{

}

const std::string Office::get_type_of()
{
	return type_of;
}
const std::string Office::get_color()
{
	return color;
}
const std::string Office::get_purpose()
{
	return purpose;
}
const double Office::get_price()
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