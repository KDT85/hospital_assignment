#pragma once
#include "Person.cpp"
#include <iostream>

using namespace std;
class Patient :public Person
{
public:
	string illness;
	string admission_date;
	Patient() :Person()
	{
		illness = "some illness";
		admission_date = "some date";
	}
	Patient(int id, string name, char gender, int dob_day, int dob_month, int dob_year, string address,
		string illness, string	admission_date)
		: Person(id, name, gender, dob_day, dob_month, dob_year, address)
	{
		this->illness = illness;
		this->admission_date = admission_date;

	}
	Patient(const Patient& p) : Person(p.id, p.name, p.gender, p.dob_day, p.dob_month, p.dob_year, p.address)
	{
		//clog << "CPY CTR CALLED" << endl;
		this->illness = p.illness;
		this->admission_date = p.admission_date;

		print();

	}

	//print out all informaion of a given patient
	void print()

	{
		cout << "Patient ID: " << id << endl;
		cout << "Patient Name: " << name << endl;
		cout << "Gender: " << gender << endl;
		cout << "Date of birth: " << dob_day << "/" << dob_month << "/" << dob_year << endl;
		int age = calculate_age(dob_day, dob_month, dob_year);
		cout << "Age: " << age << endl;
		cout << "Address: " << address << endl;
		cout << "Illness: " << illness << endl;
		cout << "Addmission date: " << this->admission_date << endl;
		cout << "------------------------------" << endl;
	}
};