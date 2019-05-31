#ifndef __PATIENT_H
#define __PATIENT_H
#pragma warning (disable : 4996)

#include "Researcher.h"
#include "Doctor.h"
#include "Nurce.h"

class Patient
{
private:

	string patient_name;
	int id_number;
	string birth_date; //dd/mm/yy
	string sex; //male/female/other
	string **date_of_arrival; //dd/mm/yy
	string **therapist_handler;
	string department_name;
	int number_of_visits;
	string **reason_of_arrival;
	string **tzom;
	string **room_number;

public:
	Patient();
	~Patient();
	void add_Patient_info(const string &pat_name, const string &b_date, const string &sexx, const string &date_of_arr, const string &therapist, const int &pat_id_numb, const string &depart_name);
	bool verify_patient(const int &id_n);
	void print_info();
	void add_Patient_info_for_x_visit(const string &date_of_arr, const string &therapist);
	void print_all_info();
};


#endif // __PATIENT_H


