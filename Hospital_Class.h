#pragma once
#include "Person.h"
#include "Personnel.h"
#include "Patient.h"


using namespace std;

class Hospital_Class
{
public:
	vector < Patient> patientVector;
	vector < Personnel> personnelVector;
	void add(Patient p);
	void add(Personnel p2);
	void save(vector < Personnel> list);
	void save(vector < Patient> list);
	void update(vector <Patient> list);
	void update(vector <Personnel> list);
	void display(vector< Patient> patientVector);
	void display(vector< Personnel> list);
	void remove(vector <Patient> list);
	void remove(vector <Personnel> list);
	void search(vector <Patient> list);
	void search(vector <Personnel> list);
	void set_password();
	string get_password();
	void ourinfoset();
	void displayInfo();
	void initialize();
	Personnel read(Personnel p);
	Patient read(Patient p);
	void main_menu();
	void personnelManegment();
	void patientManagemnt();
	void setting();
	void clearScreen();
	void shutdown(int x);
};