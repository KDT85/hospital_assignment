// hospital_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
// test 

//This program is hospital management system using object-oriented programming.
#include<iostream>
#include<fstream>
#include <limits>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <string>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <filesystem>


using namespace std;

class Menu {
	//stores the menu items
	string data[10] = {};
	int size = 10;
public:
	Menu(string st[], int z)
	{
		for (int i = 0; i < z; i++)
		{
			cout << st[i] << endl;
			data[i] = st[i];
		}
		size = z;
	}
	Menu(string one, int z)
	{
		cout << one << endl;
		cout << z << endl;
		for (int i = 0; i < z; i++)
			data[i] = one;
	}


	void show(string title) {
		cout << endl << "========= " << title << " MENU   =============";
		for (int i = 0; i < size; i++)
		{
			cout << endl << i + 1 << " - " << data[i];
		}
		cout << endl << "===================================";

	}
	int choice()
	{
		int c;

		cout << endl << "Enter your choice number: ";
		cin >> c;
		return c;
	}
};


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
	Person()
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
	Person(const Person& p) : id(p.id)
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
	Person(int id, string name, char gender, int dob_day, int dob_month, int dob_year, string address)
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

	int calculate_age(int day, int month, int year)
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
public:
	void print()
	{
		//not sure why this is here because the functionality is already covered

	}

	void set_id(const int id)
	{
		this->id = id;
	}

	int get_id()
	{
		return this->id;
	}

	void set_name(const string name)
	{
		this->name = name;
	}

	string get_name()
	{
		return this->name;
	}

	void set_gender(const char gender)
	{
		this->gender = gender;
	}

	char get_gender()
	{
		return this->gender;
	}

	void set_dob_day(const int dob_day)
	{
		this->dob_day = dob_day;
	}

	int get_dob_day()
	{
		return this->dob_day;
	}

	void set_dob_month(const int dob_month)
	{
		this->dob_month = dob_month;
	}

	int get_dob_month()
	{
		return this->dob_month;
	}

	void set_dob_year(const int dob_year)
	{
		this->dob_year = dob_year;
	}

	int get_dob_year()
	{
		return this->dob_year;
	}


	void set_address(const string address)
	{
		this->address = address;
	}

	string get_address()
	{
		return this->address;
	}




};
// use inheritance to make Patient class based on Person class

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
// use inheritance to make Personel class based on Person class

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

class Hospital_Class
{
public:
	vector < Patient> patientVector;
	vector < Personnel> personnelVector;
	//adds a Patient to patientVector 
	void add(Patient p)
	{
		patientVector.push_back(p);
		cout << "Patient added to list" << p.id << endl;

		Sleep(900);
	}

	//adds Personnel to personnelVector
	void add(Personnel p2)
	{
		personnelVector.push_back(p2);
		cout << "Personnel added to list" << p2.id << endl;
	}

	// saves personnel list into file
	void save(vector < Personnel> list)
	{
		cout << "Saving Personnel List" << endl;
		ofstream printPersonnel("Personnel.txt");
		if (!printPersonnel)
		{
			cout << "Error opening file" << endl;
			//exit(1);
		}
		for (int i = 0; i < list.size(); i++)
		{
			int id = list.at(i).get_id();
			string name = list.at(i).get_name();
			char gender = list.at(i).gender;
			int dob_day = list.at(i).dob_day;
			int dob_month = list.at(i).dob_month;
			int dob_year = list.at(i).dob_year;
			string address = list.at(i).address;
			string staff_post = list.at(i).staff_post;
			string staff_expertise = list.at(i).staff_expertise;

			// there must be a way to this in a for loop
			printPersonnel << id << endl << name << endl << gender << endl << dob_day << endl << dob_month << endl << dob_year << endl << address << endl << staff_post << endl << staff_expertise << endl;
		}
		printPersonnel.close();
	}
	// saves patient list into file
	void save(vector < Patient> list)
	{

		cout << "Saving Patient List" << endl;
		ofstream printPatient("Patient.txt");
		if (!printPatient)
		{
			cout << "Error opening file" << endl;
			//exit(1);
		}
		for (int i = 0; i < list.size(); i++)
		{
			int id = list.at(i).get_id();
			string name = list.at(i).get_name();
			char gender = list.at(i).gender;
			int dob_day = list.at(i).dob_day;
			int dob_month = list.at(i).dob_month;
			int dob_year = list.at(i).dob_year;
			string address = list.at(i).address;
			string illness = list.at(i).illness;
			string admission_date = list.at(i).admission_date;

			// there must be a way to this in a for loop
			printPatient << id << endl << name << endl << gender << endl << dob_day << endl << dob_month << endl << dob_year << endl << address << endl << illness << endl << admission_date << endl;
		}
		printPatient.close();

	}
	// update Patient list
	void update(vector <Patient> list)
	{

		// find the patient to update
		int id;
		cout << "Enter id of patient you wish to update > ";
		cin >> id;
		int element_to_update = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].id == id)
			{
				element_to_update = i;
				cout << list[element_to_update].name << " will be updated" << endl;
			}
		}

		//i would like to ask which attribute to update and then update only that attribute
		cout << "Enter patient name: ";
		getline(cin, patientVector[element_to_update].name);
		cout << patientVector[element_to_update].name << endl;
		cout << "Enter patient gender (M/F): ";
		cin >> patientVector[element_to_update].gender;
		cout << patientVector[element_to_update].gender << endl;
		cout << "Enter patient date of birth (DD/MM/YYYY): ";
		cout << "Day (DD): ";
		cin >> patientVector[element_to_update].dob_day;
		cout << patientVector[element_to_update].dob_day << endl;
		cout << "Month (MM): ";
		cin >> patientVector[element_to_update].dob_month;
		cout << patientVector[element_to_update].dob_month << endl;
		cout << "Year (YYYY): ";
		cin >> patientVector[element_to_update].dob_year;
		cout << patientVector[element_to_update].dob_year << endl;
		cout << "Enter patient address: ";
		getline(cin, patientVector[element_to_update].address);
		cout << patientVector[element_to_update].address << endl;
		cout << "Enter patient illness: ";
		cin >> patientVector[element_to_update].illness;
		cout << patientVector[element_to_update].illness << endl;
		cout << "Enter patient admission date (DDMMYYYY): ";
		getline(cin, patientVector[element_to_update].admission_date);
		cout << patientVector[element_to_update].admission_date << endl;



		cout << patientVector[element_to_update].name << " has been updated" << endl;

		save(patientVector);

	}


	// update Personnel list
	void update(vector <Personnel> list)
	{
		// find the personnel to update
		int id;
		cout << "Enter id of personnel you wish to update > ";
		cin >> id;
		int element_to_update = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].id == id)
			{
				element_to_update = i;
				cout << list[element_to_update].name << " will be updated" << endl;
			}
		}

		//i would like to ask which attribute to update and then update only that attribute
		cout << "Enter personnel name: ";
		getline(cin, personnelVector[element_to_update].name);
		cout << personnelVector[element_to_update].name << endl;
		cout << "Enter personnel gender (M/F): ";
		cin >> personnelVector[element_to_update].gender;
		cout << personnelVector[element_to_update].gender << endl;
		cout << "Enter personnel date of birth (DD/MM/YYYY): ";
		cout << "Day (DD): ";
		cin >> personnelVector[element_to_update].dob_day;
		cout << personnelVector[element_to_update].dob_day << endl;
		cout << "Month (MM): ";
		cin >> personnelVector[element_to_update].dob_month;
		cout << personnelVector[element_to_update].dob_month << endl;
		cout << "Year (YYYY): ";
		cin >> personnelVector[element_to_update].dob_year;
		cout << personnelVector[element_to_update].dob_year << endl;
		cout << "Enter personnel address: ";
		getline(cin, personnelVector[element_to_update].address);
		cout << personnelVector[element_to_update].address << endl;
		cout << "Enter personnel post: ";
		getline(cin, personnelVector[element_to_update].staff_post);
		cout << personnelVector[element_to_update].staff_post << endl;
		cout << "Enter personnel expertise: ";
		getline(cin, personnelVector[element_to_update].staff_expertise);
		cout << personnelVector[element_to_update].staff_expertise << endl;



		cout << personnelVector[element_to_update].name << " has been updated" << endl;

		save(personnelVector);

	}
	// display all data of patient list
	void display(vector< Patient> patientVector)
	{

		//clog << patientVector.size() << endl;

		for (int i = 0; i < patientVector.size(); i++)
		{
			patientVector[i].print();
		}


	}
	// display all data of personnel list
	void display(vector< Personnel> list)
	{
		for (int i = 0; i < personnelVector.size(); i++)
		{
			personnelVector[i].print();
		}

	}

	// read an id and delete its information from both memory and database of patients
	void remove(vector <Patient> list)
	{
		int id;
		cout << "Enter id of patient you wish to remove > ";
		cin >> id;
		int element_to_remove = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].id == id)
			{
				element_to_remove = i;
				cout << list[element_to_remove].name << " will be removed" << endl;
			}
		}


		patientVector.erase(patientVector.begin() + element_to_remove);
		cout << list[element_to_remove].name << " has been removed" << endl;
		save(patientVector);


	}
	// read an id and delete its information from both memory and database of personnel

	void remove(vector <Personnel> list)
	{
		int id;
		cout << "Enter id of personnel you wish to remove > ";
		cin >> id;
		int element_to_remove = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].id == id)
			{
				element_to_remove = i;
				cout << list[element_to_remove].name << " will be removed" << endl;
			}
		}


		personnelVector.erase(personnelVector.begin() + element_to_remove);
		cout << list[element_to_remove].name << " has been removed" << endl;
		save(personnelVector);

	}


	// trying to implement a search function that will search for a patient by name and 
	//return the patient id 

	void search(vector <Patient> list)
	{
		string name;
		cout << "Enter name of patient you wish to search for > ";
		getline(cin, name);
		int element_to_search;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].name == name)
			{
				element_to_search = i;
				cout << list[element_to_search].name << " has been found" << endl;
				cout << "id = " << list[element_to_search].id << endl;
				cout << "name = " << list[element_to_search].name << endl;

				break;
			}
			else
			{
				cout << "Patient not found" << endl;
			}
		}
	}

	void search(vector <Personnel> list)
	{
		string name;
		cout << "Enter name of personnel you wish to search for > ";
		getline(cin, name);
		int element_to_search;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].name == name)
			{
				element_to_search = i;
				cout << list[element_to_search].name << " has been found" << endl;
				cout << "id = " << list[element_to_search].id << endl;
				cout << "name = " << list[element_to_search].name << endl;

				break;
			}
			else
			{
				cout << "Personnel not found" << endl;
			}
		}
	}

	void set_password()
	{
		string password;
		string passwordverify;
		cout << "Create a password: ";
		cin >> password;
		cout << "Verify password:";
		cin >> passwordverify;
		if (password == passwordverify)
		{
			for (int i = 0; i < password.length(); i++)
			{
				password[i] = password[i] + 100;
			}
			cout << password << endl;
			ofstream myoutputfile;
			myoutputfile.open("admin.txt");
			myoutputfile << password;
			myoutputfile.close();
		}
		else
		{
			cout << "passwords do not match" << endl;
			set_password();
		}
	}

	string get_password()
	{
		string line;
		ifstream myfile("admin.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				cout << line << '\n';
				for (int i = 0; i < line.length(); i++)
				{
					line[i] = line[i] - 100;
					//cout << line[i];
				}
			}

			//cout << "line: " << line << endl;
			myfile.close();
		}

		else
		{
			cout << "Unable to open file";
		}

		cout << "Enter password: ";
		string passwordguess;
		cin >> passwordguess;
		if (passwordguess == line)
		{
			cout << "Correct password" << endl;
			return line;
		}
		else
		{
			cout << "Incorrect password" << endl;
		}
	}

	// sets information of the Hopspital
	void ourinfoset()
	{
		//check if password file exists, if not force user to create one 

		ifstream admin;
		admin.open("admin.txt");
		if (!admin)
		{
			cout << "You need to create a password" << endl;
			//cout << "Default password is 'admin'" << endl;
			set_password();
		}
		admin.close();


		string input = " ";
		cout << "Enter password > ";
		cin >> input;
		string password = get_password();

		if (password == input)
		{
			ofstream infoFile;
			infoFile.open("HospitalInfo.txt");
			if (!infoFile)
			{
				cout << "Error opening file" << endl;
				//exit(1);
			}

			string name, address, manager;
			cin.ignore(1, '\n'); // for some reason this is needed to clear the buffer because it was skipping the fist input
			cout << "Enter hospital name > ";
			getline(cin, name);
			cout << "Enter hospital address > ";
			getline(cin, address);
			cout << "Enter hospital manager > ";
			getline(cin, manager);

			infoFile << name << endl << address << endl << manager << endl;
			cout << "name = " << name << " - address = " << address << " - manager = " << manager << endl;

			infoFile.close();

		}
		else
		{
			cout << "Incorrect password" << endl;
		}




	}
	// displays information of the hospital
	void displayInfo()
	{
		string name, address, manager;
		ifstream infoFile;
		infoFile.open("HospitalInfo.txt");
		string line;

		while (!infoFile.eof())
		{
			if (!(getline(infoFile, name, '\n'))) break;
			cout << "Hospital name: " << name << endl;
			if (!(getline(infoFile, address, '\n'))) break;
			cout << "Hospital address: " << address << endl;
			if (!(getline(infoFile, manager, '\n'))) break;
			cout << "Hospital manager: " << manager << endl;
		}

		infoFile.close();
	}

	// reads information of patients and personnel from file and stores them in memory
	void initialize()
	{
		cout << "Initializing" << endl;
		ifstream patientFile, personnelFile;
		patientFile.open("Patient.txt");
		personnelFile.open("Personnel.txt");
		string line;
		Patient p;

		while (!patientFile.eof())
		{

			if (!(patientFile >> p.id)) break;
			if (!(patientFile >> p.name)) break;
			if (!(patientFile >> p.gender))break;
			if (!(patientFile >> p.dob_day))break;
			if (!(patientFile >> p.dob_month))break;
			if (!(patientFile >> p.dob_year))break;
			if (!(patientFile >> p.address))break;
			if (!(patientFile >> p.illness))break;
			if (!(patientFile >> p.admission_date))break;
			patientVector.push_back(p);
		}

		patientFile.close();

		Personnel p2;
		while (!personnelFile.eof())
		{
			if (!(personnelFile >> p2.id)) break;
			if (!(personnelFile >> p2.name))break;
			if (!(personnelFile >> p2.gender))break;
			if (!(personnelFile >> p2.dob_day)) break;
			if (!(personnelFile >> p2.dob_month)) break;
			if (!(personnelFile >> p2.dob_year)) break;
			if (!(personnelFile >> p2.address)) break;
			if (!(personnelFile >> p2.staff_post)) break;
			if (!(personnelFile >> p2.staff_expertise)) break;
			personnelVector.push_back(p2);
		}
		personnelFile.close();
	}
	// read data for a personnel from keyboard
	Personnel read(Personnel p)
	{
		//clog << "personnel read called" << endl;
		// im going to increment the id by 1 each time a new personnel is added
		//then i need to use the name to search for the id in the vector
		int id = 0;
		for (int i = 0; i < personnelVector.size(); i++)
		{
			cout << "ID " << personnelVector[i].id << endl;
			cout << i << endl;
			if (personnelVector[i].id != i)
			{
				//cout << "if id = i" << endl;
				id = i;
				break;
			}
			else
			{
				//cout << "else id = i + 1" << endl;
				id = i + 1;
			}
		}
		p.id = id;
		cout << "Enter personnel name: ";
		cin.ignore(1, '\n');
		getline(cin, p.name);
		cout << "Enter personnel gender (M/F): ";
		cin >> p.gender;
		cout << "Enter personnel date of birth (DDMMYYYY)" << endl;
		cout << "Day (DD): ";
		cin >> p.dob_day;
		cout << "Month (MM): ";
		cin >> p.dob_month;
		cout << "Year (YYYY): ";
		cin >> p.dob_year;
		cout << "Enter personnel address: ";
		cin.ignore(1, '\n');
		getline(cin, p.address);
		cout << "Enter personnel post: ";
		cin >> p.staff_post;
		cout << "Enter personnel expertise: ";
		cin >> p.staff_expertise;

		add(p);
		return p;
	}


	// read data for a patient from keyboard

	Patient read(Patient p)
	{
		clog << "patient read called" << endl;
		// im going to increment the id by 1 each time a new patient is added
		//then i need to use the name to search for the id in the vector
		int id = 0;
		for (int i = 0; i < patientVector.size(); i++)
		{
			cout << "ID " << patientVector[i].id << endl;
			cout << i << endl;
			if (patientVector[i].id != i)
			{
				//cout << "if id = i" << endl;
				id = i;
				break;
			}
			else
			{
				//cout << "else id = i + 1" << endl;
				id = i + 1;
			}
		}
		p.id = id;
		cout << "Enter patient name: ";
		cin.ignore(1, '\n');
		getline(cin, p.name);
		cout << "Enter patient gender (M/F): ";
		cin >> p.gender;
		cout << "Enter patient date of birth (DDMMYYYY)" << endl;
		cout << "Day (DD): ";
		cin >> p.dob_day;
		cout << "Month (MM): ";
		cin >> p.dob_month;
		cout << "Year (YYYY): ";
		cin >> p.dob_year;
		cout << "Enter patient address: ";
		cin.ignore(1, '\n');
		getline(cin, p.address);
		cout << "Enter patient illness: ";
		cin >> p.illness;
		cout << "Enter patient admission date (DDMMYYYY): ";
		cin >> p.admission_date;

		add(p);
		return p;
	}

	void main_menu()
	{
		int Selection;
		string arr[] = { "Patient Management", "Personnel Management", "Display Information", "Setting", "Shutdown" };
		int size = sizeof(arr) / sizeof(arr[0]);
		Menu mainMenu(arr, size);

		do
		{
			clearScreen();
			mainMenu.show("HOSPITAL MANAGEMENT SYSTEM MAIN");
			Selection = mainMenu.choice();
			switch (Selection)
			{
			case 1: patientManagemnt(); break;
			case 2: personnelManegment(); break;
			case 3: displayInfo(); break;
			case 4: setting(); break;
			case 5: shutdown(0);
			default:
				cout << "Invalid input!\nPlease select correct option. \n";
				Sleep(900);
				cin.clear();
				cin.ignore(100, '\n');
				break;
			}
		} while (1);

	}
	void personnelManegment()
	{
		int Selection;
		string arr[] = { "Add", "Search", "Update", "Delete", "Display", "Back to Main Menu" };
		int size = sizeof(arr) / sizeof(arr[0]);
		Menu pMenu(arr, size);

		Personnel p;
		do {
			clearScreen();
			pMenu.show("PERSONEL MANAGEMENT PATIENT");
			Selection = pMenu.choice();
			switch (Selection)
			{

			case 1:
				read(p);
				break;
			case 2:
				search(personnelVector);
				break;
			case 3:
				update(personnelVector);
				break;
			case 4:
				remove(personnelVector);
				_getch();
				break;
			case 5:
				display(personnelVector);
				_getch();
				break;
			case 6: return;
			default:
				cout << "Invalid input!\nPlease select correct option. \n";
				Sleep(900);
				cin.clear();
				cin.ignore(100, '\n');
				break;
			}
		} while (1);

	}
	void patientManagemnt()
	{
		int Selection;
		string arr[] = { "Add", "Search", "Update", "Delete", "Display", "Back to Main Menu" };
		int size = sizeof(arr) / sizeof(arr[0]);
		Menu pMenu(arr, size);


		Patient p;
		do
		{
			clearScreen();
			pMenu.show("PATIENT MANAGEMENT");
			Selection = pMenu.choice();
			switch (Selection)
			{
			case 1:
				read(p);
				break;

			case 2:
				search(patientVector);
				break;

			case 3:
				update(patientVector);
				break;
			case 4:
				remove(patientVector);
				break;
			case 5:
				display(patientVector);
				_getch();
				break;
			case 6: return;

			default:
				cout << "Invalid input!\nPlease select correct option. \n";
				Sleep(600);
				cin.clear();
				cin.ignore(100, '\n');
				break;
			}
		} while (1);

	}
	void setting()
	{
		int Selection;
		string arr[] = { "Set Hospital Information", "Back to Main Menu" };
		int size = sizeof(arr) / sizeof(arr[0]);
		Menu pMenu(arr, size);


		do {
			clearScreen();
			pMenu.show("HOSPITAL SETTIENG");
			Selection = pMenu.choice();
			switch (Selection)
			{
			case 1:
				ourinfoset();
				break;
			case 2: return;

			default:
				cout << "Invalid input!\nPlease select correct option. \n";
				Sleep(600);
				cin.clear();
				cin.ignore(100, '\n');
				break;
			}
		} while (1);


	}
	void clearScreen()
	{
		//system("CLS");
	};
	void shutdown(int x)
	{
		save(patientVector); // this is called elsewherew in program too
		save(personnelVector); // this is called elsewherew in program too

		exit(x);
	}
};

int main()
{

	Hospital_Class hospital;
	hospital.initialize();
	hospital.main_menu();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
