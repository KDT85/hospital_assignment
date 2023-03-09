#pragma once

#include <string>
#include <iostream>

#include "Person.h"

using namespace std;

class Patient :public Person
{
public:
	string illness;
	string admission_date;
	Patient();
	Patient(int id, string name, char gender, int dob_day, int dob_month, int dob_year, string address,
		string illness, string	admission_date);
	Patient(const Patient& p);

	//print out all informaion of a given patient
	void print();
};