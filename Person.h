#pragma once
#include <string>
#include <ctime>

using namespace std;

class Person
{
public:
	// write the data for class person
	int id;
	string name;
	char gender;
	int dob_day;
	int dob_month;
	int dob_year;
	string address;

	// define constructors
	Person();
	Person(const Person& p);
	Person(int id, string name, char gender, int dob_day, int dob_month, int dob_year, string address);

	//calculate age
	// 

	int calculate_age(int day, int month, int year);

	//print section, ive added a print section for each class
	//not sure if that is right?
public:
	void print();

	void set_id(const int id);
	int get_id();

	void set_name(const string name);

	string get_name();
	void set_gender(const char gender);

	char get_gender();

	void set_dob_day(const int dob_day);
	int get_dob_day();
	void set_dob_month(const int dob_month);
	int get_dob_month();

	void set_dob_year(const int dob_year);
	int get_dob_year();


	void set_address(const string address);
	string get_address();




};