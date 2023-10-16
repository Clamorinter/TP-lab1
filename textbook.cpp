#include "textbook.h"

Textbook::Textbook()
{
	std::cout << "Textbook constructor without parameters" << std::endl;
	set_type('t');
	set_defined(false);
}
Textbook::Textbook(std::string name, std::string author, int year,
	std::string institution, int study_year, int num_of_pages, double price) :
	name(name), author(author), year(year), institution(institution), study_year(study_year),
	num_of_pages(num_of_pages), price(price) 
{
	std::cout << "Textbook constructor with parameters" << std::endl;
	set_type('t');
	set_defined(true);
};
Textbook::Textbook(const Textbook& original)
{
	std::cout << "Textbook copy constructor" << std::endl;
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
Textbook::~Textbook() 
{
	std::cout << "Textbook destructor" << std::endl;
}

void Textbook::fstream_in(std::ifstream& fin)
{
	bool defined;
	fin >> defined;
	set_type('t');
	set_defined(defined);
	if (defined)
	{
		fin.ignore();
		std::getline(fin, name);
		std::getline(fin, author);
		fin >> year;
		fin.ignore();
		std::getline(fin, institution);
		fin >> study_year >> num_of_pages >> price;
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
		std::cout << "\tName: " << name << std::endl;
		std::cout << "\tAuthor: " << author << std::endl;
		std::cout << "\tYear: " << year << std::endl;
		std::cout << "\tInstitution: " << institution << std::endl;
		std::cout << "\tStudy year: " << study_year << std::endl;
		std::cout << "\tNumber of pages: " << num_of_pages << std::endl;
		std::cout << "\tPrice: " << price << std::endl;
	}
	else
		std::cout << "\tNot defined" << std::endl;
}

void Textbook::iostream_in()
{
	std::cout << "Type name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Type author: ";
	std::getline(std::cin, author);
	std::cout << "Type year: ";
	std::cin >> year;
	if (cin_error_check(std::cin))
	{
		set_defined(false);
		year = 0;
		return;
	}
	std::cout << "Type institution: ";
	std::cin.ignore();
	std::getline(std::cin, institution);
	std::cout << "Type study year: ";
	std::cin >> study_year;
	if (cin_error_check(std::cin))
	{
		set_defined(false);
		study_year = 0;
		return;
	}
	std::cout << "Type number of pages: ";
	std::cin >> num_of_pages;
	if (cin_error_check(std::cin))
	{
		set_defined(false);
		num_of_pages = 0;
		return;
	}
	std::cout << "Type price: ";
	std::cin >> price;
	if (cin_error_check(std::cin))
	{
		set_defined(false);
		price = 0;
		return;
	}
	set_defined(true);
}

void Textbook::change_param()
{
	if (!is_defined())
	{
		std::cout << "This textbook is not defined." << std::endl;
		return;
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
	if (cin_error_check(std::cin)) return;
	switch (answer)
	{
	case 1:
		std::cout << "Old name: " << name << std::endl;
		std::cout << "New name: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		break;
	case 2:
		std::cout << "Old author: " << author << std::endl;
		std::cout << "New author: ";
		std::cin.ignore();
		std::getline(std::cin, author);
		break;
	case 3:
		std::cout << "Old year: " << year << std::endl;
		std::cout << "New year: ";
		std::cin >> year;
		if (cin_error_check(std::cin))
		{
			set_defined(false);
			year = 0;
			return;
		}
		break;
	case 4:
		std::cout << "Old institution: " << institution << std::endl;
		std::cout << "New institution: ";
		std::cin.ignore();
		std::getline(std::cin, institution);
		break;
	case 5:
		std::cout << "Old study year: " << study_year << std::endl;
		std::cout << "New study year: ";
		std::cin >> study_year;
		if (cin_error_check(std::cin))
		{
			set_defined(false);
			study_year = 0;
			return;
		}
		break;
	case 6:
		std::cout << "Old number of pages: " << num_of_pages << std::endl;
		std::cout << "New number of pages: ";
		std::cin >> num_of_pages;
		if (cin_error_check(std::cin))
		{
			set_defined(false);
			num_of_pages = 0;
			return;
		}
		break;
	case 7:
		std::cout << "Old price: " << price << std::endl;
		std::cout << "New price: ";
		std::cin >> price;
		if (cin_error_check(std::cin))
		{
			set_defined(false);
			price = 0;
			return;
		}
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