#include <iostream>
#include <string>
using namespace std;

#include "Hospital.h"

Hospital::Hospital()
{
	this->all_departments = new Department*[1];
	this->all_departments[0] = new Department;
	return;
}
Hospital::~Hospital()
{
	cout << "Entered Destructor deleteing the Hospital";
	delete[]all_departments;
}
void Hospital::init_hospital() 
{
	cout << "Enter Department Name" << endl;
	string s1;
	getline(cin, s1);
	getline(cin, s1);
	this->all_departments[0]->d_name(s1);
	this->number_of_departments = 1;
	return;
}

void Hospital::add_departments()
{
	
	this->number_of_departments++;
	//this->all_departments = new Department*[this->number_of_departments];
	this->all_departments = (Department**)realloc(this->all_departments, this->number_of_departments * sizeof(Department));
	this->all_departments[this->number_of_departments - 1] = new Department;
	cout << "Enter Department Name" << endl;
	string s1;
	getline(cin, s1);
	getline(cin, s1);
	this->all_departments[this->number_of_departments - 1]->d_name(s1);
}
int Hospital::search_for_department(const string &department_name)
{
	int index;
	if (this->number_of_departments <= 0)
	{
		cout << "The Hospital Have no Departments. first add a department inorder to add the staff." << endl;
		return -1;
	}
	//Find the index for the department
	for (int i = 0; i < this->number_of_departments; i++)
	{
		if (this->all_departments[i]->index(department_name) == true)
		{
			index = i;
			break;
		}
		else
			index = -1;
	}
	if (index < 0)
	{
		cout << "No Department named:" << department_name << " was found. please check your spelling, and try again." << endl;
		return -1;
	}
	return index;
}
void Hospital::add_nurce_2_department(const string &department_name)
{	
	int index;
	index = this->search_for_department(department_name);
	if (index < 0)
	{
		cout << "department wasnt found try again." << endl;
		return;
	}
	cout << "Adding a Nurce to the " << department_name << " Department" << endl;
	this->all_departments[index]->add_nurce();
	return;
}
void Hospital::add_doctor_2_department(const string &department_name)
{
	int index;
	index = this->search_for_department(department_name);
	if (index < 0)
	{ 
		cout << "department was'nt found try again." << endl;
		return;
	}
	cout << "Adding a Doctor to the " << department_name << " Department" << endl;
	this->all_departments[index]->add_doctor();
	return;
}
Patient* Hospital::search_for_patient(const int &id_num, bool &flag)
{
	Patient *Joe=NULL;
	//temp_answers
	if (this->number_of_departments < 1)
	{
		cout << "there are no departments yet, add them first in order to search for a patient" << endl;
		flag = false;
		return Joe;
	}
	for (int i = 0; i < this->number_of_departments; i++)
	{
		Joe = this->all_departments[i]->find_patient(id_num , flag);
	}
	if (flag == true)
		cout << "Patient was Found Welcome back" << endl;
	return Joe;
}
void Hospital::add_patient(const string &pat_name,const string &b_date,const string &sexx, const string &date_of_arr ,const string &therapist,const int &pat_id_numb ,const string &depart_name)
{
	int index;
	index = this->search_for_department(depart_name);
	if (index < 0)
	{ 
		cout << "department wasnt found try again." << endl;
		return;
	}
	this->all_departments[index]->add_patient(pat_name, b_date, sexx, date_of_arr, therapist, pat_id_numb, depart_name);
	cout << "Adding a Patient to the " << depart_name << " Department" << endl;
}
void Hospital::print_all_patients_in_department(const string &depart_name)
{
	int index;
	index = this->search_for_department(depart_name);
	if (index < 0)
	{
		cout << "department wasnt found try again." << endl;
		return;
	}
	cout << "Printing all patients in " << depart_name << " Department" << endl;
	this->all_departments[index]->print_all_patients();
}
void Hospital::add_researcher(const string &name)
{
	this->research_department.add_researcher(name);
}
void Hospital::add_paper(string name, string date_of_publis, string magazine, string article_nam)
{
	this->research_department.check_researcher_exist(name, date_of_publis, magazine, article_nam);
}
void Hospital::print_all_medical_personnel() 
{
	if (this->number_of_departments <= 0)
	{
		cout << "The Hospital Have no Departments. first add a department in order to add the staff." << endl;
		return;
	}
	for (int i = 0; i < number_of_departments; i++)
	{
		all_departments[i]->print_all_medical_team();
	}
}
void Hospital::print_surgeons()
{
	if (this->number_of_departments <= 0)
	{
		cout << "The Hospital Have no Departments. first add a department in order to add the staff." << endl;
		return;
	}
	for (int i = 0; i < number_of_departments; i++)
	{
		all_departments[i]->print_all_surgeons();
	}
}
void Hospital::print_research() 
{
	research_department.print_research_team();
}
Researcher* Hospital::search_for_researcher(const string &name)
{
	Researcher *Joe = NULL;
	//temp_answers
	Joe = research_department.return_researcher(name);
	
	return Joe;

}