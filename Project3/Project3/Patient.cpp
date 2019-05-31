#include <iostream>
#include <string>
using namespace std; 

#include "Patient.h"
Patient::Patient()
{
	number_of_visits = 0;
}
Patient::~Patient()
{
	delete[]date_of_arrival;
	delete[]therapist_handler;
	delete[]reason_of_arrival;
	delete[]tzom;
	delete[]room_number;
}
void Patient::add_Patient_info(const string &pat_name,const string &b_date,const string &sexx,const string &date_of_arr,const string &therapist,const int &pat_id_numb,const string &depart_name)
{	
	string s1;
	number_of_visits = 1;
	date_of_arrival = (string**)realloc(date_of_arrival, number_of_visits * sizeof(string));
	therapist_handler = (string**)realloc(therapist_handler, number_of_visits * sizeof(string));
	reason_of_arrival = (string**)realloc(reason_of_arrival, number_of_visits * sizeof(string));
	tzom = (string**)realloc(tzom, number_of_visits * sizeof(string));
	room_number = (string**)realloc(room_number, number_of_visits * sizeof(string));
	date_of_arrival[0] = new string;
	therapist_handler[0] = new string;
	reason_of_arrival[0] = new string;
	tzom[0] = new string;
	room_number[0] = new string;

	birth_date = b_date;
	id_number = pat_id_numb;
	patient_name = pat_name;
	sex = sexx;
	*date_of_arrival[0] = date_of_arr;
	*therapist_handler[0] = therapist;
	department_name = depart_name;
	for (;;)
	{
		cout << "patient reason of arrival insert: surgery/test." << endl;
		getline(cin, s1);
		*reason_of_arrival[0] = s1;
		if (*reason_of_arrival[0] == "surgery" || *reason_of_arrival[0] == "test")
			break;
		else
			cout << "Wrong input was given. please answer surgery/test" << endl;
	}
	if (*reason_of_arrival[0] == "surgery")
	{
		cout << "did the patient eat in the last 24 hours?" << endl;
		getline(cin, s1);
		*tzom[0] = s1;
		cout << "please insert the surgery room number:" << endl;
		getline(cin, s1);
		*room_number[0] = s1;
	}
}
bool Patient::verify_patient(const int &id_n)
{
	if (id_n == id_number)
		return true;
	else
		return false;
}
void Patient::print_info()
{
	cout << "Hi Patient: " << patient_name << endl;
	cout << "Name of Department: " << department_name << endl;
}
void Patient::add_Patient_info_for_x_visit(const string &date_of_arr,const string &therapist)
{
	string s1;
	number_of_visits++;
	date_of_arrival = (string**)realloc(date_of_arrival, number_of_visits * sizeof(string));
	date_of_arrival[number_of_visits - 1] = new string;
	therapist_handler = (string**)realloc(therapist_handler, number_of_visits * sizeof(string));
	therapist_handler[number_of_visits - 1] = new string;
	*date_of_arrival[number_of_visits - 1] = date_of_arr;
	*therapist_handler[number_of_visits - 1] = therapist;
	reason_of_arrival = (string**)realloc(reason_of_arrival, number_of_visits * sizeof(string));
	tzom = (string**)realloc(tzom, number_of_visits * sizeof(string));
	room_number = (string**)realloc(room_number, number_of_visits * sizeof(string));
	reason_of_arrival[number_of_visits - 1] = new string;
	tzom[number_of_visits - 1] = new string;
	room_number[number_of_visits - 1] = new string;
	for (;;)
	{
		cout << "patient reason of arrival insert: surgery/test." << endl;
		getline(cin, s1);
		*reason_of_arrival[number_of_visits - 1] = s1;
		if (*reason_of_arrival[number_of_visits - 1] == "surgery" || "test")
			break;
		else
			cout << "Wrong input was given. please answer surgery/test" << endl;
	}
	if (*reason_of_arrival[number_of_visits - 1] == "surgery")
	{
		cout << "did the patient eat in the last 24 hours?" << endl;
		getline(cin, s1);
		*tzom[number_of_visits - 1] = s1;
		cout << "please insert the surgery room number:" << endl;
		getline(cin, s1);
		*room_number[number_of_visits - 1] = s1;
	}

}
void Patient::print_all_info()
{
	cout << "\n";
	cout << "Name: " << patient_name << endl;
	cout << "Birth date: " << birth_date << endl;
	cout << "ID number: " << id_number << endl;
	cout << "sex: " << sex << endl;
	for (int i = 0; i < this->number_of_visits; i++)
	{
		cout << "Visit Number " << (i + 1) << endl;
		cout << "Date of arrival: " << *date_of_arrival[i] << endl;
		cout << "Therapist: " << *therapist_handler[i]  << endl;
		cout << "reason for arrival: " << *reason_of_arrival[i] << endl;
		if (*reason_of_arrival[i] == "surgery")
		{
			cout << "did the patient eat in the last 24 hours before the surgery: " << *tzom[i] << endl;
			cout << "the room number where the surgery was performed: " << *room_number[i] << endl;

		}
	}
	return;
}
