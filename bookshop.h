#pragma once
#include <fstream>


class Bookshop
{
public:
	Bookshop();
	virtual ~Bookshop();

	virtual void fstream_in(const std::ifstream &fin) = 0;
	virtual Bookshop* fstream_out(const std::ofstream& fout) = 0;

	char get_type() const;
	void set_type(char type);

	bool is_defined() const;
	void set_defined(bool def);
private:
	char type;
	bool defined;
};