#include <iostream>
using namespace std;
#include <string>

#include "Department.h"
Department::Department()
{
	number_of_nurces   = 0;
	number_of_doctors  = 0;
	number_of_Patients = 0;
}
Department::~Department()
{
	delete[]all_doctors;
	delete[]all_nurces;
	delete[]all_Patients;
}
void Department::d_name(const string &s1) 
{
	this->department_name = s1;
}
bool Department::index(const string &name)
{
	bool index;
	if (this->department_name == name)
		index = true;
	else
		index = false;
	return index;
}
void Department::add_nurce()
{
	this->number_of_nurces++;
	this->all_nurces = (Nurce**)realloc(this->all_nurces, this->number_of_nurces * sizeof(Nurce));
	this->all_nurces[this->number_of_nurces - 1] = new Nurce;
	this->all_nurces[this->number_of_nurces - 1]->add_nurce_info();
}
void Department::add_doctor()
{
	this->number_of_doctors++;
	this->all_doctors = (Doctor**)realloc(this->all_doctors, this->number_of_doctors * sizeof(Doctor));
	this->all_doctors[this->number_of_doctors - 1] = new Doctor;
	this->all_doctors[this->number_of_doctors - 1]->add_doctor_info();
}
void Department::add_patient(const string &pat_name,const string &b_date,const string &sexx,const string &date_of_arr,const string &therapist,const int &pat_id_numb,const string &depart_name)
{
	this->number_of_Patients++;
	this->all_Patients = (Patient**)realloc(this->all_Patients, this->number_of_Patients * sizeof(Patient));
	this->all_Patients[this->number_of_Patients - 1] = new Patient;
	this->all_Patients[this->number_of_Patients - 1]->add_Patient_info(pat_name, b_date, sexx, date_of_arr, therapist, pat_id_numb, depart_name);
}
Patient* Department::find_patient(const int &id_num, bool &flag)
{
	bool res;
	for (int i = 0; i < this->number_of_Patients; i++)
	{
		res = this->all_Patients[i]->verify_patient(id_num);
		if (res == true)
		{
			flag = true;
			return all_Patients[i];
		}
	}
	flag = false;
	Patient *somthing_to_return = NULL;
	return somthing_to_return;
}
void Department::print_all_patients()
{
	for (int i = 0; i < this->number_of_Patients; i++)
	{
		cout << "Printing Patiant Numer: " << (i + 1) << " information:" << endl;
		this->all_Patients[i]->print_all_info();
	}

	return;
}
void Department::print_all_medical_team()
{
	cout << "Department: " << department_name << endl;
	cout << "\nDoctors:" << endl;
	for (int i = 0; i < number_of_doctors; i++)
	{
		cout << "\nDoctor Number: " << (i + 1) << endl;
		all_doctors[i]->print_doctor_info();
	}
	cout << "\nNurces:" << endl;
	for (int i = 0; i < number_of_nurces; i++)
	{
		cout << "\nNurce Number: " << (i + 1) << endl;
		all_nurces[i]->print_nurce_info();
	}
}
void Department::print_all_surgeons()
{
	cout << "Department: " << department_name << endl;
	for (int i = 0; i < number_of_doctors; i++)
	{
		all_doctors[i]->print_surgeon_info();
	}
}
Research::Research()
{
	number_of_researchers = 0;
}
Research::~Research()
{
	delete[]all_researchers;
}
void Research::add_researcher(const string &name)
{
	this->number_of_researchers++;
	this->all_researchers = (Researcher**)realloc(this->all_researchers, this->number_of_researchers * sizeof(Researcher));
	this->all_researchers[this->number_of_researchers - 1] = new Researcher;
	this->all_researchers[number_of_researchers - 1]->add_researcher_name(name);

}
void Research::check_researcher_exist(const string &name, const string &date_of_publis, const string &magazine, const string &article_nam)
{
	int index;
	bool res;
	if (number_of_researchers == 0)
	{
		cout << "there are no researchers in hospital add them first." << endl;
		return;
	}
	for (int i = 0; i < number_of_researchers; i++)
	{
		res = this->all_researchers[i]->verify_researcher(name);
		if (res == true)
		{
			index = i;
			break;
		}
	}
	if (res == false)
	{
		cout << "wasnt able to find the researcher check spelling and try again" << endl;
		return;
	}

	this->all_researchers[index]->add_a_paper(date_of_publis, magazine, article_nam);
	return;
}

void Research::print_research_team()
{
	if (number_of_researchers == 0)
	{
		cout << "there are no researchers in hospital add them first." << endl;
		return;
	}
	for (int i = 0; i < number_of_researchers; i++)
	{
		cout << "\nResearcher Number: " << (i + 1) << endl;
		all_researchers[i]->print_info();
	}
}
Researcher* Research::return_researcher(const string &name)
{
	int index;
	bool res;
	Researcher *somthing_to_return = NULL;
	if (number_of_researchers == 0)
	{
		cout << "there are no researchers in hospital add them first." << endl;
		return somthing_to_return;
	}
	for (int i = 0; i < number_of_researchers; i++)
	{
		res = this->all_researchers[i]->verify_researcher(name);
		if (res == true)
		{
			index = i;
			break;
		}
	}
	if (res == false)
	{
		cout << "wasnt able to find the researcher check spelling and try again" << endl;
		return somthing_to_return;
	}
	return all_researchers[index];

}





