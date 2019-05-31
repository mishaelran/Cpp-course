#ifndef __HOSPITAL_H
#define __HOSPITAL_H
#pragma warning (disable : 4996)


#include "Department.h"


class Hospital
{
private:
	Research research_department;
	Department** all_departments;
	int number_of_departments = 0;
public:

	Hospital();
	~Hospital();
	void add_departments();
	void init_hospital();
	int search_for_department(const string &department_name);
	void add_nurce_2_department(const string &department_name);
	void add_doctor_2_department(const string &department_name);
	Patient* search_for_patient(const int &id_num, bool &flag);
	void add_patient(const string &pat_name, const string &b_date, const string &sexx, const string &date_of_arr, const string &therapist, const int &pat_id_numb, const string &depart_name);
	void print_all_patients_in_department(const string &depart_name);
	void add_researcher(const string &name);
	void add_paper(string name, string date_of_publis, string magazine, string article_nam);
	void print_all_medical_personnel();
	void print_surgeons();
	void print_research();
	Researcher* search_for_researcher(const string &name);
};

#endif // __HOSPITAL_H