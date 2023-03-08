#pragma once

#include <iostream>
#include <string>

using namespace std;

class Menu
{

public:
	Menu(string st[], int z);
	Menu(string one, int z);
	void show(string title);
};
