#pragma once
#include "Person.cpp"
#include <iostream>

using namespace std;

class Personnel :public Person
{
public:
	string staff_post;
	string staff_expertise;
	Personnel() :Person()
	{
		staff_post = "Doctor";
		staff_expertise = "10 years";
	}
	Personnel(int id, string name, char gender, int dob_day, int dob_month, int dob_year, string address,
		string staff_post, string	staff_expertise)
		: Person(id, name, gender, dob_day, dob_month, dob_year, address)
	{
		this->staff_post = staff_post;
		this->staff_expertise = staff_expertise;

	}
	Personnel(const Personnel& p) : Person(p.id, p.name, p.gender, p.dob_day, p.dob_month, p.dob_year, p.address)
	{
		this->staff_post = p.staff_post;
		this->staff_expertise = p.staff_expertise;
	}
	void print()
	{
		cout << "Personnel ID: " << id << endl;
		cout << "Personnel Name: " << name << endl;
		cout << "Gender: " << gender << endl;
		cout << "Date of birth: " << dob_day << "/" << dob_month << "/" << dob_year << endl;
		int age = calculate_age(dob_day, dob_month, dob_year);
		cout << "Age: " << age << endl;
		cout << "Address: " << address << endl;
		cout << "Post: " << staff_post << endl;
		cout << "Expertise: " << staff_expertise << endl;
		cout << "------------------------------" << endl;
	}
};