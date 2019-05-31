#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#pragma warning (disable : 4996)

#include "Doctor.h"
#include "Nurce.h"
#include "Patient.h"
#include "Researcher.h"

class Department
{
private:
	string department_name;
	Doctor **all_doctors;
	Nurce ** all_nurces;
	Patient **all_Patients;	
	int number_of_nurces   ;
	int number_of_doctors  ;
	int number_of_Patients ;
public:
	Department();
	~Department();
	void d_name(const string &s1);
	bool index(const string &name);
	void add_nurce();
	void add_doctor();
	void add_patient(const string &pat_name, const string &b_date, const string &sexx, const string &date_of_arr, const string &therapist, const int &pat_id_numb, const string &depart_name);
	Patient *find_patient(const int &id_num, bool &flag);
	void print_all_patients();
	void print_all_medical_team();
	void print_all_surgeons();
};


class Research
{
private:
	Researcher** all_researchers;
	int number_of_researchers;
public:

	Research();
	~Research();
	void add_researcher(const string &name);
	void check_researcher_exist(const string &name,const string &date_of_publis,const string &magazine,const string &article_nam);
	void print_research_team();
	Researcher* return_researcher(const string &name);

};




#endif // __DEPARTMENT_H

