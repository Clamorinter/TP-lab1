#include "textbook.h"

Textbook::Textbook()
{
	set_type('t');
	set_defined(false);
}
Textbook::Textbook(std::string name, std::string author, int year,
	std::string institution, int study_year, int num_of_pages, double price) :
	name(name), author(author), year(year), institution(institution), study_year(study_year),
	num_of_pages(num_of_pages), price(price) 
{
	set_type('t');
	set_defined(true);
};
Textbook::Textbook(const Textbook& original)
{
	set_defined(original.is_defined());
	set_type(original.get_type());
	if (is_defined())
	{
		name = original.get_name();
		author = original.get_author();
		year = original.get_year();
		institution = original.get_institution();
		study_year = original.get_study_year();
		num_of_pages = original.get_num_of_pages();
		price = original.get_price();
	}
}
Textbook::~Textbook() {}

void Textbook::fstream_in(std::ifstream& fin)
{
	bool defined;
	fin >> defined;
	set_type('t');
	set_defined(defined);
	if (defined)
	{
		fin >> name >> author >> year >> institution >> study_year >> num_of_pages
			>> price;
	}
}
void Textbook::fstream_out(std::ofstream& fout) const
{
	fout << get_type() << std::endl << is_defined() << std::endl;
	if (is_defined())
	{
		fout << name << std::endl << author << std::endl << year
			<< std::endl << institution << std::endl << study_year
			<< std::endl << num_of_pages << std::endl << price << std::endl;
	}
}

void Textbook::iostream_out() const
{
	std::cout << "Type: Textbook" << std::endl;
	if (is_defined())
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Author: " << author << std::endl;
		std::cout << "Year: " << year << std::endl;
		std::cout << "Institution: " << institution << std::endl;
		std::cout << "Study year: " << study_year << std::endl;
		std::cout << "Number of pages: " << num_of_pages << std::endl;
		std::cout << "Price: " << price << std::endl;
	}
	else
		std::cout << "Not defined" << std::endl;
}

void Textbook::iostream_in()
{
	std::cout << "Type name: ";
	std::cin >> name;
	std::cout << "Type author: ";
	std::cin >> author;
	std::cout << "Type year: ";
	std::cin >> year;
	std::cout << "Type institution: ";
	std::cin >> institution;
	std::cout << "Type study year: ";
	std::cin >> study_year;
	std::cout << "Type number of pages: ";
	std::cin >> num_of_pages;
	std::cout << "Type price: ";
	std::cin >> price;
}

void Textbook::change_param()
{
	if (!is_defined())
	{
		return; //place for a throw
	}
	int answer;
	std::cout << "Which parameter do you want to change?" << std::endl;
	std::cout << "1 - name" << std::endl;
	std::cout << "2 - author" << std::endl;
	std::cout << "3 - year" << std::endl;
	std::cout << "4 - institution" << std::endl;
	std::cout << "5 - study year" << std::endl;
	std::cout << "6 - number of pages" << std::endl;
	std::cout << "7 - price" << std::endl;
	std::cout << ">";
	std::cin >> answer;
	switch (answer)
	{
	case 1:
		std::cout << "Old name: " << name << std::endl;
		std::cout << "New name: ";
		std::cin >> name;
		break;
	case 2:
		std::cout << "Old author: " << author << std::endl;
		std::cout << "New author: ";
		std::cin >> author;
		break;
	case 3:
		std::cout << "Old year: " << year << std::endl;
		std::cout << "New year: ";
		std::cin >> year;
		break;
	case 4:
		std::cout << "Old institution: " << institution << std::endl;
		std::cout << "New institution: ";
		std::cin >> institution;
		break;
	case 5:
		std::cout << "Old study year: " << study_year << std::endl;
		std::cout << "New study year: ";
		std::cin >> study_year;
		break;
	case 6:
		std::cout << "Old number of pages: " << num_of_pages << std::endl;
		std::cout << "New number of pages: ";
		std::cin >> num_of_pages;
		break;
	case 7:
		std::cout << "Old price: " << price << std::endl;
		std::cout << "New price: ";
		std::cin >> price;
		break;
	}
}

std::string Textbook::get_name() const
{
	return name;
}
std::string Textbook::get_author() const
{
	return author;
}
int Textbook::get_year() const
{
	return year;
}
std::string Textbook::get_institution() const
{
	return institution;
}
int Textbook::get_study_year() const
{
	return study_year;
}
int Textbook::get_num_of_pages() const
{
	return num_of_pages;
}
double Textbook::get_price() const
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