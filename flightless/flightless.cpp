#define _CRT_SECURE_NO_WARNINGS
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
	//load data
	loadUserData();
	loadAdminFile(&adminVector);
	loadPassengerFile(&passengerVector);
	//loadBookingFile(&bookingVector);

	// user registrations
	//registerNewPassenger();
	//registerNewAdmin();

	//showAll(&passengerVector);
	//showAll(&adminVector);


	return 0;
}






