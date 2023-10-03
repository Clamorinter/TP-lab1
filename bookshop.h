#pragma once
#include <fstream>


class Bookshop
{
public:
	Bookshop();
	virtual ~Bookshop();

	virtual void fstream_in(const std::ifstream &fin) = 0;
	virtual Bookshop* fstream_out(const std::ofstream& fout) = 0;

	const char get_type();
	void set_type(char type);
private:
	char type;
};