#pragma once
#include "bookshop.h"
#include <string>

class Office : public Bookshop
{
public:
	Office();
	//	Book(); with param
	Office(const Office& original);
	~Office();

	void fstream_in(const std::ifstream& fin);
	Bookshop* fstream_out(const std::ofstream& fout);

	const std::string get_type();
	const std::string get_color();
	const std::string get_purpose();
	const double get_price();

	void set_type(std::string type);
	void set_color(std::string color);
	void set_purpose(std::string purpose);
	void set_price(double price);

private:
	std::string type;
	std::string color;
	std::string purpose;
	double price;
};
