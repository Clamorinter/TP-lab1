#include "book.h"

Book::Book()
{
	set_type('b');
	set_defined(false);
}
Book::Book(std::string name, std::string author, int year,
	std::string annotation, std::string genre, int num_of_pages, double price) :
	name(name), author(author), year(year), annotation(annotation), genre(genre),
	num_of_pages(num_of_pages), price(price) 
{
	set_type('b');
	set_defined(true);
};
Book::Book(const Book& original)
{
	set_defined(original.is_defined());
	set_type(original.get_type());
	if (is_defined())
	{
		name = original.get_name();
		author = original.get_author();
		year = original.get_year();
		annotation = original.get_annotation();
		genre = original.get_genre();
		num_of_pages = original.get_num_of_pages();
		price = original.get_price();
	}
}
Book::~Book() {}

void Book::fstream_in(std::ifstream& fin)
{
	bool defined;
	fin >> defined;
	set_type('b');
	set_defined(defined);
	if (defined)
	{
		fin.ignore();
		std::getline(fin, name);
		std::getline(fin, author);
		fin >> year;
		fin.ignore();
		std::getline(fin, annotation);
		std::getline(fin, genre);
		fin >> num_of_pages >> price;
	}
}
void Book::fstream_out(std::ofstream& fout) const
{
	fout << get_type() << std::endl << is_defined() << std::endl;
	if (is_defined())
	{
		fout << name << std::endl << author << std::endl << year
			<< std::endl << annotation << std::endl << genre
			<< std::endl << num_of_pages << std::endl << price << std::endl;
	}
}

void Book::iostream_out() const
{
	std::cout << "Type: Book" << std::endl;
	if (is_defined())
	{
		std::cout << "\tName: " << name << std::endl;
		std::cout << "\tAuthor: " << author << std::endl;
		std::cout << "\tYear: " << year << std::endl;
		std::cout << "\tAnnotation: " << annotation << std::endl;
		std::cout << "\tGenre: " << genre << std::endl;
		std::cout << "\tNumber of pages: " << num_of_pages << std::endl;
		std::cout << "\tPrice: " << price << std::endl;
	}
	else
		std::cout << "\tNot defined" << std::endl;
}

void Book::iostream_in()
{
	std::cout << "Type name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Type author: ";
	std::getline(std::cin, author);
	std::cout << "Type year: ";
	std::cin >> year;
	std::cout << "Type annotation: ";
	std::cin.ignore();
	std::getline(std::cin, annotation);
	std::cout << "Type genre: ";
	std::getline(std::cin, genre);
	std::cout << "Type number of pages: ";
	std::cin >> num_of_pages;
	std::cout << "Type price: ";
	std::cin >> price;
	set_defined(true);
}

void Book::change_param()
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
	std::cout << "4 - annotation" << std::endl;
	std::cout << "5 - genre" << std::endl;
	std::cout << "6 - number of pages" << std::endl;
	std::cout << "7 - price" << std::endl;
	std::cout << ">";
	std::cin >> answer;
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
		break;
	case 4:
		std::cout << "Old annotation: " << annotation << std::endl;
		std::cout << "New annotation: ";
		std::cin.ignore();
		std::getline(std::cin, annotation);
		break;
	case 5:
		std::cout << "Old genre: " << genre << std::endl;
		std::cout << "New genre: ";
		std::cin.ignore();
		std::getline(std::cin, genre);
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

std::string Book::get_name() const
{
	return name;
}
std::string Book::get_author() const
{
	return author;
}
int Book::get_year() const
{
	return year;
}
std::string Book::get_annotation() const
{
	return annotation;
}
std::string Book::get_genre() const
{
	return genre;
}
int Book::get_num_of_pages() const
{
	return num_of_pages;
}
double Book::get_price() const
{
	return price;
}

void Book::set_name(std::string name)
{
	this->name = name;
}
void Book::set_author(std::string author)
{
	this->author = author;
}
void Book::set_year(int year)
{
	this->year = year;
}
void Book::set_annotation(std::string annotation)
{
	this->annotation = annotation;
}
void Book::set_genre(std::string genre)
{
	this->genre = genre;
}
void Book::set_num_of_pages(int num_of_pagges)
{
	this->num_of_pages = num_of_pages;
}
void Book::set_price(double price)
{
	this->price = price;
}