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