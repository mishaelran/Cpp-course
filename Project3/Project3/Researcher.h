#ifndef __RESEARCHER_H
#define __RESEARCHER_H
#pragma warning (disable : 4996)


class Paper
{
private:
	string date_of_publish; // DD/MM/YY
	string magazine_name;
	string article_name;
public:
	void init_paper_info(const string &date_of_publis, const string &magazine, const string &article_nam);
	void print_paper_info();
};


class Researcher
{
private:
	Paper** all_papers;
	string name_of_res;
	int number_of_papers;
public:
	Researcher operator>(const Researcher& one)
	{
		if (this->number_of_papers > one.number_of_papers)
		{
			cout << "The number of papers of Researcher named: " << this->name_of_res << endl << "is BIGGER than the number of papers of Researcher named: " << one.name_of_res << endl;
		}
		else if (one.number_of_papers > this->number_of_papers)
			cout << "The number of papers of Researcher named: " << one.name_of_res << endl << "is BIGGER than the number of papers of Researcher named: " << this->name_of_res << endl;
		else
			cout << "The number of papers of both researchers are the same." << endl;
		return one;
	}

	Researcher();
	~Researcher();
	void add_researcher_name(const string &name);
	bool verify_researcher(const string &name);
	void add_a_paper(const string &date_of_publis, const string &magazine, const string &article_nam);
	void print_info();
	
};





#endif // __RESEARCHER_H

