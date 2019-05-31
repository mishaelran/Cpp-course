// Ran Mishael 308069640.
#include <iostream>
using namespace std;
#include <string>


#include "Researcher.h"
#include "Doctor.h"
#include "Nurce.h"
#include "Patient.h"
#include "Department.h"
#include "Hospital.h"

void get_patient_inforation(string &pat_name, string &b_date, string &sexx, string &date_of_arr, string &therapist, int &pat_id_numb, string &depart_name);
void get_patient_partial_info(string &date_of_arr, string &therapist);
void get_paper_info(string  &paper_name, string &magazine, string &date);
string get_researcher_names_for_compare(int i);

void main()
{	
	Hospital Asuta;
	int users_choise,number_of_departments=0;
	string temp_names;
	int temp_answers;
	Patient *temp_patient;
	// patients information vars
	string pat_name, b_date, sexx, date_of_arr,therapist, depart_name;
	int pat_id_numb;
	// researcher information vars
	string paper_name, magazine, date, researcher_1_compare, researcher_2_compare;
	//
	Researcher *num1, *num2;

	bool flag = true;
	bool pat_flag = true;

	cout << "Welcome to Ran Mishael's Hospital" << endl;
	cout << "Enter 911 to exit" << endl;
	for (;;)
	{
		cout << "Make sure your input is an int" << endl;
		cout << "Choose one of the following Options:" << endl;
		cout << "1. Adding a Department for the hospital." << endl;
		cout << "2. Adding a Nurce to a specific Department" << endl;
		cout << "3. Adding a Doctor to a specific Department" << endl;
		cout << "4. Adding a Patient Visit." << endl;
		cout << "5. Adding a Researcher to a the Research Department." << endl;
		cout << "6. Adding a Paper for a specific Researcher." << endl;
		cout << "7. Showing all of the Patients belonging to a specific Department." << endl;
		cout << "8. Showing all the Medical Team in all Departments." << endl;
		cout << "9. Presenting all of the Researchers in the Hospital system." << endl;
		cout << "10. Search for a Patient with ID number and see his Name + Department." << endl;
		cout << "11. Print all Surgeons." << endl;
		cout << "12. Compare between two researchers (using operators)" << endl;
		cin >> users_choise;
		

		switch (users_choise)
		{
			case 1:
				number_of_departments++;
				if (number_of_departments == 1)
				{ 
					Asuta.init_hospital();
				}
				else
				{
					Asuta.add_departments();
				}
				break;

			case 2:
				cout << "Enter the name of the department you want to add a Nurce to." << endl;
				getline(cin, temp_names);
				getline(cin, temp_names);
				Asuta.add_nurce_2_department(temp_names);
				break;

			case 3:
				cout << "Enter the name of the department you want to add a Doctor to." << endl;
				getline(cin, temp_names);
				getline(cin, temp_names);
				Asuta.add_doctor_2_department(temp_names);
				break;

			case 4:
				cout << "Hi Patient, did you visit this hospital before? answer \"yes\"/\"no\"" << endl;
				cin >> temp_names; 
				if (temp_names == "yes")
				{ //fix this
					cout << "Welcome Back, can you give me your id number?" << endl;
					cin >> temp_answers;
					pat_flag = true;
					temp_patient = Asuta.search_for_patient(temp_answers, pat_flag);
					if (pat_flag == true)
					{
						get_patient_partial_info(date_of_arr, therapist);
						temp_patient->add_Patient_info_for_x_visit(date_of_arr, therapist);
					}
					else
					{
						cout << "id wasnt found, try again." << endl;
					}
				}
				else
				{
					get_patient_inforation(pat_name, b_date, sexx, date_of_arr, therapist, pat_id_numb, depart_name);
					Asuta.add_patient(pat_name, b_date, sexx, date_of_arr, therapist, pat_id_numb, depart_name);
				}
				break;

			case 5:
				cout << "Add the name of the Researcher" << endl;
				cin >> temp_names;
				Asuta.add_researcher(temp_names);
				break;

			case 6:
				cout << "write the name of the Researcher you would like to add a paper to" << endl;
				cin >> temp_names;
				get_paper_info(paper_name, magazine, date);
				Asuta.add_paper(temp_names, paper_name, magazine, date);
				break;
			case 7:
				cout << "Please enter the desired department name" << endl;
				cin >> temp_names;
				cout << "\n";
				cout << "####################################" << endl;
				cout << "#     Presenting all Patients      #" << endl;
				cout << "#          in " << temp_names << " Department        #" << endl;
				cout << "####################################" << endl;
				cout << "\n";
				Asuta.print_all_patients_in_department(temp_names);

				break;


			case 8:
				cout << "\n";
				cout << "####################################" << endl;
				cout << "#     Presenting all Personnel     #" << endl;
				cout << "####################################" << endl;
				cout << "\n";
				Asuta.print_all_medical_personnel();
				break;
					
			case 9:
				cout << "\n";
				cout << "####################################" << endl;
				cout << "#     Presenting Research Team     #" << endl;
				cout << "####################################" << endl;
				cout << "\n";
				Asuta.print_research();

				break;
			case 10:
				cout << "Welcome Back, can you give me your id number?" << endl;
				cin >> temp_answers;
				pat_flag = true;
				temp_patient = Asuta.search_for_patient(temp_answers, pat_flag);
				if (pat_flag == true)
					temp_patient->print_info();
				else
					cout << "patient id number wasnt found try again" << endl;

				break;

			case 11:
				cout << "\n";
				cout << "####################################" << endl;
				cout << "#     Presenting Surgeons          #" << endl;
				cout << "####################################" << endl;
				cout << "\n";
				Asuta.print_surgeons();
				break;
			case 12:
				cout << "Enter two names of researchers to compare." << endl;
				researcher_1_compare = get_researcher_names_for_compare(1);
				researcher_2_compare = get_researcher_names_for_compare(2);
				cout << "\n";
				cout << "####################################" << endl;
				cout << "#    Comparing Researchers         #" << endl;
				cout << "####################################" << endl;
				cout << "\n";
				
				num1 = Asuta.search_for_researcher(researcher_1_compare);
				num2 = Asuta.search_for_researcher(researcher_2_compare);
				if (num1 == NULL || num2 == NULL)
					cout << "Failed to search for researchers. check spelling and try again." << endl;
				else
				{
					num1->operator>(*num2);
				}
				break;
			case 911:
				cout << "911 What is your emergency?" << endl;
				cout << "Kidding, GoodBye!" << endl;
				flag = false;
				break;
			default:
				cout << "Wrong input please try again." << endl;
		
		}
		if (flag == false)
		{
			break;
		}
		cout << "\n";
	}
	system("pause");
}

void get_patient_inforation(string &pat_name, string &b_date, string &sexx, string &date_of_arr, string &therapist,int &pat_id_numb, string &depart_name)
{
	cout << "Hi Patient Welcome to our Hospital\nPlease enter your name" << endl;
	getline(cin, pat_name);
	getline(cin, pat_name);
	cout << "Hi " << pat_name << " please enter your birth date DD/MM/YY format" << endl; 
	getline(cin, b_date);
	cout << "Please enter your sex female/male/other" << endl;
	getline(cin, sexx);
	cout << "Please enter date of arrival DD/MM/YY format" << endl; 
	getline(cin, date_of_arr);
	cout << "Please enter the therapist" << endl;
	getline(cin, therapist);
	cout << "Please enter your id number" << endl;
	cin >> pat_id_numb;
	cout << "Please enter the department name" << endl;
	getline(cin, depart_name);
	getline(cin, depart_name);
	return;
}
void get_patient_partial_info(string &date_of_arr, string &therapist)
{
	cout << "Hi Patient, because you already visited us before we need less information." << endl;
	cout << "Please enter the current date DD/MM/YY format" << endl;
	getline(cin, date_of_arr);
	getline(cin, date_of_arr);
	cout << "Please enter the therapist" << endl;
 	getline(cin, therapist);

}
void get_paper_info(string  &paper_name, string &magazine, string &date)
{
	cout << "Adding New Paper" << endl;
	cout << "Enter article's name" << endl;
	getline(cin, paper_name);
	getline(cin, paper_name);
	cout << "Enter Magazine's name" << endl;
	getline(cin, magazine);
	cout << "enter publish date" << endl;
	getline(cin, date);
	return;
}
string get_researcher_names_for_compare(int i)
{
	string s1;
	cout << "Compare Researchers" << endl;
	cout << "Enter Researcher Number: " << i << "Name" << endl;
	getline(cin, s1);
	if (i < 2)
		getline(cin, s1);
	return s1;
}