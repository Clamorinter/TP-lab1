#include "textbook.h"

Textbook::Textbook()
{

}
Textbook::Textbook(std::string name, std::string author, int year,
	std::string institution, int study_year, int num_of_pages, double price) :
	name(name), author(author), year(year), institution(institution), study_year(study_year),
	num_of_pages(num_of_pages), price(price) {};
Textbook::Textbook(const Textbook& original)
{

}
Textbook::~Textbook()
{

}

void Textbook::fstream_in(const std::ifstream& fin)
{

}
Bookshop* Textbook::fstream_out(const std::ofstream& fout)
{

}

const std::string Textbook::get_name()
{
	return name;
}
const std::string Textbook::get_author()
{
	return author;
}
const int Textbook::get_year()
{
	return year;
}
const std::string Textbook::get_institution()
{
	return institution;
}
const int Textbook::get_study_year()
{
	return study_year;
}
const int Textbook::get_num_of_pages()
{
	return num_of_pages;
}
const double Textbook::get_price()
{
	return price;
}

void Textbook::set_name(std::string name)
{
	this->name = name;
}
void Textbook::set_author(std::string author)
{
	this->author = author;
}
void Textbook::set_year(int year)
{
	this->year = year;
}
void Textbook::set_institution(std::string institution)
{
	this->institution = institution;
}
void Textbook::set_study_year(int study_year)
{
	this->study_year = study_year;
}
void Textbook::set_num_of_pages(int num_of_pagges)
{
	this->num_of_pages = num_of_pages;
}
void Textbook::set_price(double price)
{
	this->price = price;
}