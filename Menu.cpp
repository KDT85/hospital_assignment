#include "Menu.h"
#include <string>
#include <iostream>

using namespace std;

Menu::Menu(string st[], int z)
{
	for (int i = 0; i < z; i++)
	{
		cout << st[i] << endl;
		data[i] = st[i];
	}
	size = z;
}


Menu::Menu(string one, int z)
{
	cout << one << endl;
	cout << z << endl;
	for (int i = 0; i < z; i++)
		data[i] = one;
}


void Menu::show(string title) {
	cout << endl << "========= " << title << " MENU   =============";
	for (int i = 0; i < size; i++)
	{
		cout << endl << i + 1 << " - " << data[i];
	}
	cout << endl << "===================================";
}


int Menu::choice()
{
	int c;

	cout << endl << "Enter your choice number: ";
	cin >> c;
	return c;
}
