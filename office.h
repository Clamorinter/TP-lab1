#pragma once
#include "bookshop.h"
#include <string>

class Office : public Bookshop
{
public:
	Office();
	Office(std::string type_of, std::string color,
		std::string purpose, double price);
	Office(const Office& original);
	~Office();

	void fstream_in(const std::ifstream& fin);
	Bookshop* fstream_out(const std::ofstream& fout);

	std::string get_type_of() const;
	std::string get_color() const;
	std::string get_purpose() const;
	double get_price() const;

	void set_type_of(std::string type_of);
	void set_color(std::string color);
	void set_purpose(std::string purpose);
	void set_price(double price);

private:
	std::string type_of;
	std::string color;
	std::string purpose;
	double price;
};
