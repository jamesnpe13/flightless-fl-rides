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
void displayTC();
void welcomeScreen();
void signInRegMenu();
void userTypeMenu(bool isRegister_ = 0);
//void dashboard();		

int main()
{
	int userSelection;
	// displayTC
	// welcome screen

	while (1)
	{
		int menuLoc = 3;

		cout << "---------------------" << endl;
		cout << "    PROGRAM START    " << endl;
		cout << "---------------------" << endl;

		switch (menuLoc)
		{
		case 1:
			displayTC();
			break;
		case 2:
			welcomeScreen();
			break;
		case 3:
			signInRegMenu();
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
void signInRegMenu()
{

	while (1)
	{
		cout << "---------------------" << endl;
		cout << " SIGN IN or REGISTER " << endl;
		cout << "---------------------" << endl;

		cout << "1. Sign in" << endl;
		cout << "2. Register new user" << endl;

		int menuLoc;

		userSelectionInput(&menuLoc);
		switch (menuLoc)
		{
		case 1:
			userTypeMenu();
			break;
		case 2:
			userTypeMenu(1);
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
void userTypeMenu(bool isRegister_)
{

	while (1)
	{
		if (isRegister_)
		{
			cout << "---------------------" << endl;
			cout << "     REGISTER AS     " << endl;
			cout << "---------------------" << endl;
		}
		else
		{
			cout << "---------------------" << endl;
			cout << "      SIGN IN AS     " << endl;
			cout << "---------------------" << endl;
		}

		cout << "1. Passenger" << endl;
		cout << "2. Driver" << endl;
		cout << "3. Admin" << endl;
		cout << "4. Passenger" << endl;
		cout << "0. Return to menu" << endl;

		int menuLoc;

		userSelectionInput(&menuLoc);
		switch (menuLoc)
		{
		case 1:
			isRegister_ ? registerNewPassenger() : signInPassenger();
			break;
		case 2:
			isRegister_ ? registerNewDriver() : signInDriver();
			break;
		case 3:
			isRegister_ ? registerNewAdmin() : signInAdmin();
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
//void dashboard()
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
