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

void loadFiles()
{
	loadUserData();
	loadAdminFile(&adminVector);
	loadPassengerFile(&passengerVector);
}

void menu(int* userSelect_)
{
	cout << "1. Register new admin." << endl;
	cout << "2. Show all admins." << endl;
	cout << endl;
	cout << "3. Register new passenger." << endl;
	cout << "4. Show all passengers." << endl;
	cout << endl;
	cout << "5. Register new driver." << endl;
	cout << "6. Show all drivers." << endl;
	cout << endl;
	cout << "7. TEST - Calculate date difference." << endl;

	cin >> *userSelect_;
}

int main()
{

	while (1)
	{
		loadFiles();
		int userSelect;

		menu(&userSelect);

		switch (userSelect)
		{
		case 1:
			registerNewAdmin();
			break;
		case 2:
			showAll(&adminVector);
			break;
		case 3:
			registerNewPassenger();
			break;
		case 4:
			showAll(&passengerVector);
			break;
		case 5:
			registerNewDriver();
			break;
		case 6:
			showAll(&driverVector);
			break;
		case 7:
			s_Driver newDriver;
			cout << "Calculate date difference." << endl;
			int m, y, d;
			cout << "Enter day: ";
			cin >> d;
			cout << "Enter month: ";
			cin >> m;
			cout << "Enter year: ";
			cin >> y;
			newDriver.getAge(d, m, y);
			cout << "My age is " << newDriver.age << endl;

			break;
		}
	}

	//cout << getDay() << "-" << getMonth() << "-" << getYear() << endl;
	//load data
	//loadUserData();
	//loadAdminFile(&adminVector);
	//loadPassengerFile(&passengerVector);
	//loadBookingFile(&bookingVector);

	// user registrations
	//registerNewPassenger();
	//registerNewAdmin();
	//registerNewDriver();

	//showAll(&passengerVector);
	//showAll(&adminVector);

	return 0;
}
