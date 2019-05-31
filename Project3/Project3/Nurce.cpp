#include <iostream>
#include <string>
using namespace std;

#include "Nurce.h"

void Nurce::add_nurce_info()
{
	string s1;
	int temp_int;
	cout << "\nPlease Enter Nurce's Name" << endl;
	getline(cin, s1);
	this->add_nurce_name(s1);
	cout << "Please Enter Nurce's ID number" << endl;
	cin >> temp_int;
	this->add_nurce_id(temp_int);
	cout << "Please Enter Nurce's Years of Experience" << endl;
	cin >> temp_int;
	this->add_nurce_exp(temp_int);
}
void Nurce::add_nurce_name(const string &name)
{	
	nurce_name = name;
}
void Nurce::add_nurce_id(const int &id_numb)
{
	id = id_numb;
}
void Nurce::add_nurce_exp(const int &years)
{
	years_of_exp = years;
}
void Nurce::print_nurce_info()
{
	cout << "Nurce's Name: " << nurce_name << endl;
	cout << "Nurce's ID number: " << id << endl;
	cout << "Nurce's years of experience: " << years_of_exp << endl;
	cout << "\n";
}