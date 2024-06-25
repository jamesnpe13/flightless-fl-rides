#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Header.h"
#include "Structs.h"
#include <stdio.h>
#include <ctime>
#include <fstream>

using namespace std;

int userSelectionInput(int* target_);
void displayTC();							// 1
void welcomeScreen();						// 2
void signInRegMenu(int* masterMenuLoc_);	// 3
void userTypeMenu(int* masterMenuLoc_);		// 4
//void dashboard(int* masterMenuLoc_);		// 5

int main()
{
	int menuLoc = 0;
	cout << "program start" << endl;

	// displayTC
	// welcome screen

	while (1)
	{
		int userSelection;
		cout << "Main menu" << endl;
		userSelectionInput(&menuLoc);
		switch (menuLoc)
		{
		case 1:
			displayTC();
			break;
		case 2:
			welcomeScreen();
			break;
		case 3:
			signInRegMenu(&menuLoc);
			break;
		case 4:
			userTypeMenu(&menuLoc);
			break;
			/*case 5:
				dashboard(&menuLoc);
				break;*/
		default:
			cout << "Please select from the menu options." << endl;
			break;
		}
	}

	return 0;
}

int userSelectionInput(int* target_)
{
	do
	{
		cin >> *target_;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (!cin);

	return *target_;
}
void displayTC()
{
	cout << "T&C" << endl;
}
void welcomeScreen()
{
	cout << "Welcome screen" << endl;
}
void signInRegMenu(int* masterMenuLoc_)
{
	cout << "sign in or reg" << endl;

	while (*masterMenuLoc_ == 3)
	{
		int menuLoc;

		userSelectionInput(&menuLoc);
		switch (menuLoc)
		{
		case 1:
			cout << "Sign in" << endl;
			break;
		case 2:
			cout << "Register" << endl;
			break;
		case 0:
			return;
			break;
		default:
			cout << "Please select from the menu options." << endl;
			break;
		}
	}
}
void userTypeMenu(int* masterMenuLoc_)
{
	cout << "Select user type" << endl;

	while (*masterMenuLoc_ == 4)
	{
		int menuLoc;

		userSelectionInput(&menuLoc);
		switch (menuLoc)
		{
		case 1:
			cout << "Passenger" << endl;
			break;
		case 2:
			cout << "Driver" << endl;
			break;
		case 3:
			cout << "Admin" << endl;
			break;
		case 0:
			return;
			break;
		default:
			cout << "Please select from the menu options." << endl;
			break;
		}
	}
}
//void dashboard(int* masterMenuLoc_)
//{
//	cout << "User dashboard" << endl;
//
//	while (*masterMenuLoc_ == 5)
//	{
//		int menuLoc;
//
//		userSelectionInput(&menuLoc);
//		switch (menuLoc)
//		{
//		case 1:
//			cout << "Sign in" << endl;
//			break;
//		case 2:
//			cout << "Register" << endl;
//			break;
//		case 0:
//			return;
//			break;
//		default:
//			cout << "Please select from the menu options." << endl;
//			break;
//		}
//	}
//}
