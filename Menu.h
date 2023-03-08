#pragma once


using namespace std;

class Menu
{

public:
	string data[10] = {};
	int size = 10;
	Menu(string st[], int z);
	Menu(string one, int z);
	void show(string title);
	int choice();
};
