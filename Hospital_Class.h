#pragma once
#include "Hospital.h"

using namespace std;

class Hospital_Class
{
public:
	vector < Patient> patientVector;
	vector < Personnel> personnelVector;
	//adds a Patient to patientVector 
	void add(Patient p);
	//adds Personnel to personnelVector
	void add(Personnel p2);

	// saves personnel list into file
	void save(vector < Personnel> list);
	// saves patient list into file
	void save(vector < Patient> list);
	// update Patient list
	void update(vector <Patient> list);


	// update Personnel list
	void update(vector <Personnel> list);
	// display all data of patient list
	void display(vector< Patient> patientVector);
	// display all data of personnel list
	void display(vector< Personnel> list);

	// read an id and delete its information from both memory and database of patients
	void remove(vector <Patient> list);
	// read an id and delete its information from both memory and database of personnel

	void remove(vector <Personnel> list);


	// trying to implement a search function that will search for a patient by name and 
	//return the patient id 

	void search(vector <Patient> list);

	void search(vector <Personnel> list);

	void set_password();

	string get_password();

	// sets information of the Hopspital
	void ourinfoset();
	// displays information of the hospital
	void displayInfo();

	// reads information of patients and personnel from file and stores them in memory
	void initialize();
	// read data for a personnel from keyboard
	Personnel read(Personnel p);


	// read data for a patient from keyboard

	Patient read(Patient p);

	void main_menu();
	void personnelManegment();
	void patientManagemnt();
	void setting();
	void clearScreen();
	void shutdown(int x);
};
