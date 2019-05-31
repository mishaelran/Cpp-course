#ifndef __NURCE_H
#define __NURCE_H
#pragma warning (disable : 4996)


class Nurce 
{
private:
	string nurce_name;
	int  id;
	int years_of_exp;

public:

	void add_nurce_info();
	void add_nurce_name(const string &name);
	void add_nurce_id(const int &id_numb);
	void add_nurce_exp(const int &years);
	void print_nurce_info();
};

#endif // __NURCE_H

