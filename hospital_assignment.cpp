// hospital_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
	int dob;
	string address;

	// define constructors
	Person()
	{
		id = 0;
		name = "person_name";
		gender = 'g';
		dob = 10011970;
		address = "qwerty";

		clog << "CALLED CTR" << endl;

	}
	Person(const Person& p) : id(p.id)
	{
		clog << "CALLED COPY CTR" << endl;
		this->id = p.id;
		this->name = p.name;
		this->gender = p.gender;
		this->dob = p.dob;
		this->address = p.address;
	}
	Person(int id, string name, char gender, int dob, string address)
	{
		this->id = id;
		this->name = name;
		this->gender = gender;
		this->dob = dob;
		this->address = address;

		clog << "CALLED OL CTR" << endl;

	}

	//print section, ive added a print section for each class
	//not sure if that is right?
public:
	void print()
	{
	//This should print one person from the vector

	}

	// i think luke did this
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

	void set_dob(const int dob)
	{
		this->dob = dob;
	}

	int get_dob()
	{
		return this->dob;
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
	Patient(int id, string name, char gender, int dob, string address,
		string illness, string	admission_date)
		: Person(id, name, gender, dob, address)
	{
		this->illness = illness;
		this->admission_date = admission_date;

	}
	Patient(const Patient& p) : Person(p.id, p.name, p.gender, p.dob, p.address)
	{
		clog << "CPY CTR CALLED" << endl;
		this->illness = p.illness;
		this->admission_date = p.admission_date;

		print();

	}

	//prtin out all informaion of a given patient
	void print()

	{
		cout << "Patient ID: " << id << endl;
		cout << "Patient Name: " << name << endl;
		cout << "Gender: " << gender << endl;
		cout << "Date of birth: " << dob << endl;
		cout << "Age: " << "todays date minus dob somwhow" << endl;
		cout << "Address: " << address << endl;
		cout << "Illness this one?: " << illness << endl;
		cout << "Addmission date: " << this->admission_date << endl;

	}
};
// use inheritance to make Personel class based on Person class

class Personnel :public Person
{
public:
	string staff_post;
	string staff_expertise;
	Personnel() :Person()
	{}
	Personnel(int id, string name, char gender, int dob, string address,
		string staff_post, string	staff_expertise)
		: Person(id, name, gender, dob, address)
	{

	}
	Personnel(const Personnel& p) : Person(p.id, p.name, p.gender, p.dob, p.address)
	{

	}
	void print()
	{
		//Person::print(p);


	}
};

class Hospital_Class
{
public:
	vector < Patient> patientVector;
	vector < Personnel> staffVector;
	// adds a Patient to patientVector 
	void add(Patient p)

	{


		patientVector.push_back(p);
		cout << "Patient added to list" << p.id << endl;

		Sleep(900);
	}
	//adds a Personnel to staffVector
	void add(Personnel p2)
	{
		staffVector.push_back(p2);


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
		for (int i = 0; i < 10; i++)
		{
			
			printPersonnel  << i << endl;
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
			int dob = list.at(i).dob;
			string address = list.at(i).address;
			string illness = list.at(i).illness;
			string admission_date = list.at(i).admission_date;

			// there must be a way to this in a for loop
			printPatient << id << endl << name  << endl << gender << endl << dob << endl  << address << endl << illness << endl << admission_date << endl;
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
		cin >> patientVector[element_to_update].name;
		cout << patientVector[element_to_update].name << endl;
		cout << "Enter patient gender (M/F): ";
		cin >> patientVector[element_to_update].gender;
		cout << patientVector[element_to_update].gender << endl;
		cout << "Enter patient date of birth (DDMMYYYY): ";
		cin >> patientVector[element_to_update].dob;
		cout << patientVector[element_to_update].dob << endl;
		cout << "Enter patient address: ";
		cin >> patientVector[element_to_update].address;
		cout << patientVector[element_to_update].address << endl;
		cout << "Enter patient illness: ";
		cin >> patientVector[element_to_update].illness;
		cout << patientVector[element_to_update].illness << endl;
		cout << "Enter patient admission date (DDMMYYYY): ";
		cin >> patientVector[element_to_update].admission_date;
		cout << patientVector[element_to_update].admission_date << endl;


		//patientVector.erase(patientVector.begin() + element_to_update);
		cout << patientVector[element_to_update].name << " has been updated" << endl;

	}
	

	// update Personnel list
	void update(vector <Personnel> list)
	{
		cout << "Updating Personnel List" << endl;
	}
	// display all data of patient list
	void display(vector< Patient> patientVector)
	{

		clog << patientVector.size() << endl;

		for (int i = 0; i < patientVector.size(); i++)
		{
			patientVector[i].print();
			
			/*cout << "id = " << patientVector.at(i).get_id() << endl;
			cout << "name = " << patientVector.at(i).name << endl;
			/*		cout << "gender = " << patientVector[i].gender << endl;
						cout << "date of birth = " << patientVector[i].dob << endl;
						cout << "address = " << patientVector[i].address << endl;
						cout << "illness = " << patientVector[i].illness << endl;
						cout << "admission date = " << patientVector[i].admission_date << endl;*

*/
		}


	}
	// display all data of personnel list
	void display(vector< Personnel> list)
	{
		for (int i = 0; i < staffVector.size(); i++)
		{
			cout << staffVector[i].name << endl;
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
		
	
	}
	// read an id and delete its information from both memory and database of personnel

	void remove(vector <Personnel> list)
	{
	
	}

	// trying to implement a search function that will search for a patient by name and 
	//return the patient id 

	void search(vector <Patient> list)
	{
		string name;
		cout << "Enter name of patient you wish to search for > ";
		cin >> name;
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

	// sets information of the Hopspital
	void ourinfoset()
	{

	}
	// displays information of the hospital
	void displayInfo()
	{

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

/*		while (getline(patientFile, line))
		{
			p.id;
			p.name;
			sscanf(line.c_str(), "%[^],%d", &p.id, &p.name);
			patientVector.push_back((p));
			}*/
		
		while (!patientFile.eof())
		{

			if (!(patientFile >> p.id)) break;
			if (!(patientFile >> p.name)) break;
			if (!(patientFile >> p.gender))break;
			if (!(patientFile >> p.dob))break;
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
			if (!(personnelFile >> p2.dob)) break;
			if (!(personnelFile >> p2.address)) break;
			if (!(personnelFile >> p2.staff_post)) break;
			if (!(personnelFile >> p2.staff_expertise)) break;
			staffVector.push_back(p2);
		}
		personnelFile.close();
	}
	// read data for a personnel from keyboard
	Personnel read(Personnel p)
	{
		cout << "Enter personnel id: ";//how can we auto generate a unique id for each person?		
		cin >> p.id;
		cout << "Enter personnel name: ";
		cin >> p.name;
		cout << "Enter personnel gender: ";
		cin >> p.gender;
		cout << "Enter personnel date of birth (DDMMYYYY): ";
		cin >> p.dob;
		cout << "Enter personnel address: ";
		cin >> p.address;
		cout << "Enter personnel post: ";
		cin >> p.staff_post;
		cout << p.staff_post << endl;
		cout << "Enter personnel expertise: ";
		cin >> p.staff_expertise;
		cout << p.staff_expertise << endl;
		add(p);
		return p;
	}


	// read data for a patient from keyboard

	Patient read(Patient p)
	{
		clog << "patient read called" << endl;
		// im going to increment the id by 1 each time a new patient is added
		//then i need to use the name to search for the id in the vector
		//cout << "Enter patient id: ";
		int id = 0;
		for (int i = 0; i < patientVector.size(); i++)
		{
			cout << "ID " << patientVector[i].id << endl;
			cout << i << endl;
			if (patientVector[i].id != i)
			{
				 id = i;
			} 
			else
			{
				id = i + 1;
			}
		}
		p.id = id;
		cout << "ID " << p.id << endl;
		cout << "Enter patient name: ";
		cin >> p.name;
		cout << p.name << endl;
		cout << "Enter patient gender (M/F): ";
		cin >> p.gender;
		cout << p.gender << endl;
		cout << "Enter patient date of birth (DDMMYYYY): ";
		cin >> p.dob;
		cout << p.dob << endl;
		cout << "Enter patient address: ";
		cin >> p.address;
		cout << p.address << endl;
		cout << "Enter patient illness: ";
		cin >> p.illness;
		cout << p.illness << endl;
		cout << "Enter patient admission date (DDMMYYYY): ";
		cin >> p.admission_date;
		cout << p.admission_date << endl;

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
		string arr[] = { "Add", "Update", "Delete", "Display", "Back to Main Menu" };
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
				update(staffVector);
				break;
			case 3:
				remove(staffVector);
				break;
			case 4:
				display(staffVector);
				_getch();
				break;
			case 5: return;
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
		save(patientVector); // this should be called else wherrer in the program too

		//test for loop to see whats in the vetor
		for (int i = 0; i < patientVector.size(); i++)
		{
			cout << "patientVector" << i << " - ";
			cout <<patientVector[i].name << endl;
		}
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
