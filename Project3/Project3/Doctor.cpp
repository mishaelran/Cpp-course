#include <iostream>
#include <string>
using namespace std;

#include "Doctor.h"

void Doctor::add_doctor_info()
{
	string s1;
	int temp_int,i;
	cout << "\nPlease Enter Doctor's Name" << endl;
	getline(cin, s1);
	this->add_doctor_name(s1);
	cout << "Please Enter Doctor's ID number" << endl;
	cin >> temp_int;
	this->add_doctor_id(temp_int);
	cout << "Please Enter Doctor's field of Specialization" << endl;
	getline(cin, s1);
	getline(cin, s1);
	this->add_doctor_specialize(s1);
	for (;;)
	{
		cout << "Is this Doctor a surgeon yes/no" << endl;
		getline(cin, s1);
		if (s1 == "yes" || s1 == "no")
			break;
		else
			cout << "Wrong input was given. please answer yes/no" << endl;
	}
	set_doctor_surgeon(s1);
	if (s1 == "yes")
	{
		cout << "How many surgeries this doctor preformed?" << endl;
		getline(cin, s1);
		set_doctor_surgeries(s1);
	}
}
void Doctor::add_doctor_name(const string &name)
{
	doc_name = name;
}
void Doctor::add_doctor_id(const int &id_numb)
{
	id = id_numb;
}
void Doctor::add_doctor_specialize(const string &special)
{
	specialize = special;
}
void Doctor::print_doctor_info()
{
	cout << "Doctor's Name: " << doc_name << endl;
	cout << "Doctor's ID number: " << id << endl;
	cout << "Doctor's specialize: " << specialize << endl;
	cout << "Doctor is capable of surgeries: " << surgeon << endl;
	if (surgeon == "yes")
		cout << "Number of surgeries performed: " << surgeries << endl;
	cout << "\n";
}
void Doctor::print_surgeon_info()
{
	if (surgeon == "yes")
	{
		cout << "Printing all Surgeons: " << endl;
		cout << "Doctor's Name: " << doc_name << endl;
		cout << "Doctor's ID number: " << id << endl;
		cout << "Doctor's specialize: " << specialize << endl;
		cout << "Doctor is capable of surgeries: " << surgeon << endl;
		cout << "Number of surgeries performed: " << surgeries << endl;
		cout << "\n";
	}
}
void Doctor::set_doctor_surgeon(const string &surgeon_input)
{
	surgeon = surgeon_input;

}
void Doctor::set_doctor_surgeries(const string &surgeries_intput)
{
	surgeries = surgeries_intput;
}


