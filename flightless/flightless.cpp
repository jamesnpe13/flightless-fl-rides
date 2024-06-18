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

int main()
{
	while (1)
	{
		loadFiles();
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
