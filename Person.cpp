#include "Person.h"
#include <string>
#include <ctime>



using namespace std;



// define constructors
Person::Person()
{
	id = 0;
	name = "person_name";
	gender = 'g';
	dob_day = 01;
	dob_month = 01;
	dob_year = 1970;
	address = "qwerty";

	//clog << "CALLED CTR" << endl;

}
Person::Person(const Person& p) : id(p.id)
{
	//clog << "CALLED COPY CTR" << endl;
	this->id = p.id;
	this->name = p.name;
	this->gender = p.gender;
	this->dob_day = p.dob_day;
	this->dob_month = p.dob_month;
	this->dob_year = p.dob_year;
	this->address = p.address;
}
Person::Person(int id, string name, char gender, int dob_day, int dob_month, int dob_year, string address)
{
	this->id = id;
	this->name = name;
	this->gender = gender;
	this->dob_day = dob_day;
	this->dob_month = dob_month;
	this->dob_year = dob_year;
	this->address = address;

	//clog << "CALLED OL CTR" << endl;

}

//calculate age
// 

int Person::calculate_age(int day, int month, int year)
{
	// get current date
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int current_year = 1900 + newtime.tm_year;
	int current_month = 1 + newtime.tm_mon;
	int current_day = newtime.tm_mday;

	// calculate age
	int age = current_year - year;
	if (current_month < month)
	{
		age--;
	}
	else if (current_month == month)
	{
		if (current_day < day)
		{
			age--;
		}
	}
	return age;
}

//print section, ive added a print section for each class
//not sure if that is right?

void Person::print()
{
	//not sure why this is here because the functionality is already covered

}

void Person::set_id(const int id)
{
	this->id = id;
}

int Person::get_id()
{
	return this->id;
}

void Person::set_name(const string name)
{
	this->name = name;
}

string Person::get_name()
{
	return this->name;
}

void Person::set_gender(const char gender)
{
	this->gender = gender;
}

char Person::get_gender()
{
	return this->gender;
}

void Person::set_dob_day(const int dob_day)
{
	this->dob_day = dob_day;
}

int Person::get_dob_day()
{
	return this->dob_day;
}

void Person::set_dob_month(const int dob_month)
{
	this->dob_month = dob_month;
}

int Person::get_dob_month()
{
	return this->dob_month;
}

void Person::set_dob_year(const int dob_year)
{
	this->dob_year = dob_year;
}

int Person::get_dob_year()
{
	return this->dob_year;
}


void Person::set_address(const string address)
{
	this->address = address;
}

string Person::get_address()
{
	return this->address;
}
