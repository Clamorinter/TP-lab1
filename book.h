#pragma once
#include "bookshop.h"
#include <string>

class Book : public Bookshop
{
public:
	Book();
	Book(std::string name, std::string author, int year,
		std::string annotation, std::string genre, int num_of_pages, double price);
	Book(const Book& original);
	~Book();

	void fstream_in(std::ifstream& fin);
	void fstream_out(std::ofstream& fout) const;

	void iostream_in();
	void iostream_out() const;

	std::string get_name() const;
	std::string get_author() const;
	int get_year() const;
	std::string get_annotation() const;
	std::string get_genre() const;
	int get_num_of_pages() const;
	double get_price() const;

	void set_name(std::string name);
	void set_author(std::string author);
	void set_year(int year);
	void set_annotation(std::string annotation);
	void set_genre(std::string genre);
	void set_num_of_pages(int num_of_pages);
	void set_price(double price);

private:
	std::string name;
	std::string author;
	int year;
	std::string annotation;
	std::string genre;
	int num_of_pages;
	double price;
};
