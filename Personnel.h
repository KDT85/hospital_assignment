#pragma once

#include <string>
#include <iostream>

#include "Person.h"

using namespace std;

class Personnel :public Person
{
public:
	string staff_post;
	string staff_expertise;
	Personnel();
	Personnel(int id, string name, char gender, int dob_day, int dob_month, int dob_year, string address,
		string staff_post, string	staff_expertise);
	Personnel(const Personnel& p);
	void print();
};