#pragma once
#include <string>
#include <iostream>

using namespace std;

class Menu {
	//stores the menu items
	string data[10] = {};
	int size = 10;
public:
	Menu(string st[], int z);
	Menu(string one, int z);


	void show(string title);
	int choice();
};