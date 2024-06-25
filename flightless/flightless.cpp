
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

int main()
{

	// displayTC
	// welcome screen

	loadFiles();
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
		showAll(&driverVector);

		cout << activeUserType << endl;
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
		cout << "0. Return to menu" << endl;

		int menuLoc;

		userSelectionInput(&menuLoc);
		switch (menuLoc)
		{
		case 1:
			isRegister_ ? registerNewPassenger() : signInForm(1);
			break;
		case 2:
			isRegister_ ? registerNewDriver() : signInForm(2);
			break;
		case 3:
			isRegister_ ? registerNewAdmin() : signInForm(3);
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
void dashboard(const UserType* activeUserType_)
{
	int menuLoc;
	switch (*activeUserType_)
	{
	case passenger:
		while (1)
		{
			cout << "---------------------" << endl;
			cout << " PASSENGER DASHBOARD " << endl;
			cout << "---------------------" << endl;

			cout << "1. View active bookings" << endl;
			cout << "2. Create a new booking" << endl;
			cout << "3. See booking history" << endl;
			cout << "0. Sign out" << endl;

			userSelectionInput(&menuLoc);

			switch (menuLoc)
			{
			case 1:
				// view active bookings
				break;
			case 2:
				// create new booking
				break;
			case 3:
				// see booking history
				break;
			case 0:
				signInRegMenu();
				break;
			default:
				cout << "Please select from the menu options." << endl;
				break;
			}
		}

		break;
	case driver:
		while (1)
		{
			cout << "---------------------" << endl;
			cout << "   DRIVER DASHBOARD  " << endl;
			cout << "---------------------" << endl;

			cout << "1. View available bookings" << endl;
			// list all bookings and choose to accept trip
			cout << "2. Trip reports" << endl;
			// shows todays trips and search by date
			cout << "3. My payment details" << endl;
			// show payment details			
			cout << "0. Sign out" << endl;

			userSelectionInput(&menuLoc);

			switch (menuLoc)
			{
			case 1:
				cout << "all bookings available" << endl;
				break;
			case 2:
				cout << "trip reports" << endl;
				break;
			case 3:
				cout << "payment details" << endl;
				break;
			case 0:
				signInRegMenu();
				break;
			default:
				cout << "Please select from the menu options." << endl;
				break;
			}
		}
		break;
	case admin:
		while (1)
		{
			cout << "---------------------" << endl;
			cout << "   ADMIN DASHBOARD   " << endl;
			cout << "---------------------" << endl;

			cout << "1. Trip reports" << endl;
			// list all bookings and choose to accept trip
			cout << "2. Trip cancellation report" << endl;
			// list all trip cancellations
			cout << "3. View all drivers" << endl;
			// shows todays trips and search by date
			cout << "4. View all passengers" << endl;
			// show payment details			
			cout << "0. Sign out" << endl;

			userSelectionInput(&menuLoc);

			switch (menuLoc)
			{
			case 1:
				cout << "trip reports" << endl;
				break;
			case 2:
				cout << "trip cancellation report" << endl;
				break;
			case 3:
				cout << "all drivers" << endl;
				break;
			case 4:
				cout << "all passengers" << endl;
				break;
			case 0:
				signInRegMenu();
				break;
			default:
				cout << "Please select from the menu options." << endl;
				break;
			}
			break;
		}
	}

}
