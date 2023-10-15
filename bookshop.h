#pragma once
#include <fstream>
#include <iostream>

class Bookshop
{
public:
	Bookshop();
	virtual ~Bookshop();

	virtual void fstream_in(std::ifstream &fin) = 0;
	virtual void fstream_out(std::ofstream& fout) const = 0;

	virtual void iostream_in() = 0;
	virtual void iostream_out() const = 0;

	virtual void change_param() = 0;

	char get_type() const;
	void set_type(char type);

	bool is_defined() const;
	void set_defined(bool def);
private:
	char type;
	bool defined;
};