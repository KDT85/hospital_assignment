#include "Hospital_Class.h"
#include "Person.h"
#include "Patient.h"
#include "Personnel.h"
#include <iostream>
#include <synchapi.h>
#include <vector>
#include <fstream>
#include <string>
#include "Menu.h"
#include <conio.h>


using namespace std;

//adds a Patient to patientVector 
void Hospital_Class::add(Patient p)
{
	patientVector.push_back(p);
	cout << "Patient added to list" << p.id << endl;

	Sleep(900);
}

//adds Personnel to personnelVector
void Hospital_Class::add(Personnel p2)
{
	personnelVector.push_back(p2);
	cout << "Personnel added to list" << p2.id << endl;
}

// saves personnel list into file
void Hospital_Class::save(vector < Personnel> list)
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
void Hospital_Class::save(vector < Patient> list)
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
void Hospital_Class::update(vector <Patient> list)
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
void Hospital_Class::update(vector <Personnel> list)
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
void Hospital_Class::display(vector< Patient> patientVector)
{

	//clog << patientVector.size() << endl;

	for (int i = 0; i < patientVector.size(); i++)
	{
		patientVector[i].print();
	}


}
// display all data of personnel list
void Hospital_Class::display(vector< Personnel> list)
{
	for (int i = 0; i < personnelVector.size(); i++)
	{
		personnelVector[i].print();
	}

}

// read an id and delete its information from both memory and database of patients
void Hospital_Class::remove(vector <Patient> list)
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

void Hospital_Class::remove(vector <Personnel> list)
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

void Hospital_Class::search(vector <Patient> list)
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

void Hospital_Class::search(vector <Personnel> list)
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

void Hospital_Class::set_password()
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
		//cout << password << endl;
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

string Hospital_Class::get_password()
{
	string line;
	ifstream myfile("admin.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//cout << line << '\n';
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
void Hospital_Class::ourinfoset()
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
void Hospital_Class::displayInfo()
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
void Hospital_Class::initialize()
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
Personnel Hospital_Class::read(Personnel p)
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

Patient Hospital_Class::read(Patient p)
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

void Hospital_Class::main_menu()
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
		case 3: displayInfo(); _getch(); break;
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
void Hospital_Class::personnelManegment()
{
	int Selection;
	string arr[] = { "Add", "Search", "Update", "Delete", "Display", "Back to Main Menu" };
	int size = sizeof(arr) / sizeof(arr[0]);
	Menu pMenu(arr, size);

	Personnel p;
	do {
		clearScreen();
		pMenu.show("PERSONEL MANAGEMENT");
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
void Hospital_Class::patientManagemnt()
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
void Hospital_Class::setting()
{
	int Selection;
	string arr[] = { "Set Hospital Information", "Back to Main Menu" };
	int size = sizeof(arr) / sizeof(arr[0]);
	Menu pMenu(arr, size);


	do {
		clearScreen();
		pMenu.show("HOSPITAL SETTINGS");
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
void Hospital_Class::clearScreen()
{
	system("CLS");
};
void Hospital_Class::shutdown(int x)
{
	save(patientVector); // this is called elsewherew in program too
	save(personnelVector); // this is called elsewherew in program too

	exit(x);
}