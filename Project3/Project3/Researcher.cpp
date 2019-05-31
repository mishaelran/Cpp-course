#include <iostream>
#include <string>
using namespace std;

#include "Researcher.h"
Researcher::Researcher()
{
	number_of_papers = 0;
}
Researcher::~Researcher()
{
	delete[]all_papers;
}
void Researcher::add_researcher_name(const string &name)
{
	name_of_res = name;
}
bool Researcher::verify_researcher(const string &name)
{
	if (name_of_res == name)
		return true;
	else
		return false;
}
void Researcher::add_a_paper(const string &date_of_publis,const string &magazine,const string &article_nam)
{
	number_of_papers++;
	all_papers = (Paper**)realloc(all_papers, number_of_papers * sizeof(Paper));
	all_papers[number_of_papers - 1] = new Paper;
	all_papers[number_of_papers - 1]->init_paper_info(date_of_publis, magazine, article_nam);
	return;
}
void Researcher::print_info()
{
	cout << "\nResearcher Name: " << name_of_res << endl;
	for (int i = 0; i < number_of_papers; i++)
	{
		cout << "\nPaper Number: " << (i + 1) << endl;
		all_papers[i]->print_paper_info();
	}
}

void Paper::init_paper_info(const string &date_of_publis,const string &magazine,const string &article_nam)
{
	article_name = article_nam;
	date_of_publish = date_of_publis;
	magazine_name = magazine;
}
void Paper::print_paper_info()
{
	cout << "Article Name: " << article_name << endl;
	cout << "Date of publish: " << date_of_publish << endl;
	cout << "Magazine: " << magazine_name << endl;
}
