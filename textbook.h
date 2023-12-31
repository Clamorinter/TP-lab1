#pragma once
#include "bookshop.h"
#include <string>

class Textbook : public Bookshop
{
public:
	Textbook();
	Textbook(std::string name, std::string author, int year,
		std::string institution, int study_year, int num_of_pages, double price);
	Textbook(const Textbook& original);
	~Textbook();

	void fstream_in(std::ifstream& fin);
	void fstream_out(std::ofstream& fout) const;

	void iostream_in();
	void iostream_out() const;

	void change_param();

	std::string get_name() const;
	std::string get_author() const;
	int get_year() const;
	std::string get_institution() const;
	int get_study_year() const;
	int get_num_of_pages() const;
	double get_price() const;

	void set_name(std::string name);
	void set_author(std::string author);
	void set_year(int year);
	void set_institution(std::string instition);
	void set_study_year(int study_year);
	void set_num_of_pages(int num_of_pages);
	void set_price(double price);

private:
	std::string name;
	std::string author;
	int year;
	std::string institution;
	int study_year;
	int num_of_pages;
	double price;
};