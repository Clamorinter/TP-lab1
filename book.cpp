#include "book.h"

Book::Book()
{

}
Book::Book(std::string name, std::string author, int year,
	std::string annotation, std::string genre, int num_of_pages, double price) :
	name(name), author(author), year(year), annotation(annotation), genre(genre),
	num_of_pages(num_of_pages), price(price) {};
Book::Book(const Book& original)
{

}
Book::~Book()
{

}

void Book::fstream_in(const std::ifstream& fin)
{

}
Bookshop* Book::fstream_out(const std::ofstream& fout)
{

}

const std::string Book::get_name()
{
	return name;
}
const std::string Book::get_author()
{
	return author;
}
const int Book::get_year()
{
	return year;
}
const std::string Book::get_annotation()
{
	return annotation;
}
const std::string Book::get_genre()
{
	return genre;
}
const int Book::get_num_of_pages()
{
	return num_of_pages;
}
const double Book::get_price()
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