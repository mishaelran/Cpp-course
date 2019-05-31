#ifndef __DOCTOR_H
#define __DOCTOR_H
#pragma warning (disable : 4996)

class Doctor
{
private:
	string doc_name;
	int  id;
	string specialize;
	string surgeon;
	string surgeries;

public:

	void add_doctor_info();
	void add_doctor_name(const string &name);
	void add_doctor_id(const int &id_numb);
	void add_doctor_specialize(const string &special);
	void print_doctor_info();
	void print_surgeon_info();
	void set_doctor_surgeon(const string &surgeon_input);
	void set_doctor_surgeries(const string &surgeries_intput);
};
#endif // __DOCTOR_H