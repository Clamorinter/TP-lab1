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
		fin >> name >> author >> year >> annotation >> genre >> num_of_pages
			>> price;
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