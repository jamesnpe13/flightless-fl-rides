// function definition here
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

unsigned int getDay()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return ltm->tm_mday;
}

unsigned int getYear()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return ltm->tm_year + 1900;
}

// check if date is valid. returns boolean
bool dateIsValid(int targetMonth_, int targetYear_)
{
	// checks whether a given dd/yyyy date is still valid
	time_t timeA, timeB;

	struct tm tA, tB, * tptr;
	int timeDiffDays;

	time(&timeA);
	time(&timeB);

	tptr = localtime(&timeA);
	tA = *tptr;
	tptr = localtime(&timeB);
	tB = *tptr;

	//tB.tm_mday = 10; // day input
	tB.tm_mon = targetMonth_ - 1; // month input
	tB.tm_year = targetYear_ - 1900; // year input

	timeA = mktime(&tA);
	timeB = mktime(&tB);

	timeDiffDays = (timeB - timeA) / 60 / 60 / 24;

	return timeDiffDays > 0 ? 1 : 0;
}

// cout struct members
void showPassengeMembers(const Passenger& target_)
{
	cout << "First name: " << target_.firstName << endl;
	cout << "Last name: " << target_.lastName << endl;
	cout << "Gender: " << target_.gender << endl;
	cout << "Mobile number: " << target_.mobileNumber << endl;
	cout << "Email: " << target_.email << endl;
	cout << "Username: " << target_.username << endl;
	cout << "Password: " << target_.password << endl;
	cout << "Payment method: " << target_.paymentMethod << endl;
	cout << "Card number: " << target_.cardNumber << endl;
	cout << "Card expiry month: " << target_.cardExpiryM << endl;
	cout << "Card expiry Year: " << target_.cardExpiryY << endl;
}

// cout struct members
void showAdminMembers(const Admin& target_)
{
	cout << "First name: " << target_.firstName << endl;
	cout << "Last name: " << target_.lastName << endl;
	cout << "Username: " << target_.username << endl;
	cout << "Password: " << target_.password << endl;
}

// check if input data type matches variable dataw type
void inputValidation(int* target_)
{
	while (!cin)
	{
		cout << "Invalid data type. Please enter an integer." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> *target_;
	}
}

// check if string consists of numbers
bool isNumber(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}



/*
		USER REGISTRATION
*/



// register new passenger
void registerNewPassenger()
{
	// create struct
	struct Passenger tempPassenger;

	// first name
	cout << "First name: ";
	cin >> tempPassenger.firstName;

	// last name
	cout << "Last name: ";
	cin >> tempPassenger.lastName;

	// username
	cout << "Username: ";
	cin >> tempPassenger.username;

	// password
	cout << "Password: ";
	cin >> tempPassenger.password;

	// gender
	cout << "Gender (0 = male, 1 = female): ";
	cin >> tempPassenger.gender;
	inputValidation(&tempPassenger.gender);
	while (tempPassenger.gender != 1 && tempPassenger.gender != 0)
	{
		cout << "Please select 0 for male or 1 for female." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> tempPassenger.gender;
	}

	// mobile number
	cout << "Mobile number: ";
	cin >> tempPassenger.mobileNumber;

	// email
	cout << "Email:  ";
	cin >> tempPassenger.email;

	// payment method
	cout << "Payment method (0 = cash, 1 = card): ";
	cin >> tempPassenger.paymentMethod;
	inputValidation(&tempPassenger.paymentMethod);
	while (tempPassenger.paymentMethod != 0 && tempPassenger.paymentMethod != 1)
	{
		cout << "Please select 0 for cash payment or 1 for card payment." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> tempPassenger.paymentMethod;
	}

	// card number

	if (tempPassenger.paymentMethod == 1)
	{
		cout << "Card number: ";
		cin >> tempPassenger.cardNumber;
		while (tempPassenger.cardNumber.length() != 16 || !isNumber(tempPassenger.cardNumber))
		{
			cout << "Your card number must be 16 digits." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> tempPassenger.cardNumber;
		}

		// card expiry month
		while (!dateIsValid(tempPassenger.cardExpiryM, tempPassenger.cardExpiryY))
		{
			cout << "Card expiry month (mm): ";
			cin >> tempPassenger.cardExpiryM;
			inputValidation(&tempPassenger.cardExpiryM);
			while (to_string(tempPassenger.cardExpiryM).length() > 2 || to_string(tempPassenger.cardExpiryM).length() == 0)
			{
				cout << "Card expiry month must be entered as mm." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> tempPassenger.cardExpiryM;
			}

			// card expiry year
			cout << "Card expiry year (yyyy): ";
			cin >> tempPassenger.cardExpiryY;
			inputValidation(&tempPassenger.cardExpiryY);
			while (to_string(tempPassenger.cardExpiryY).length() != 4)
			{
				cout << "Card expiry year must be entered as yyyy." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> tempPassenger.cardExpiryY;
			}
		}
	}

	cout << "New passenger registration successful." << endl;
}

// register new administrator
void registerNewAdmin()
{
	// create struct
	struct Admin tempAdmin;

	// first name
	cout << "First name: ";
	cin >> tempAdmin.firstName;

	// last name
	cout << "Last name: ";
	cin >> tempAdmin.lastName;

	// username
	cout << "Username: ";
	cin >> tempAdmin.username;

	// password
	cout << "Password: ";
	cin >> tempAdmin.password;

	cout << "New admin registration successful." << endl;
}

void mainMenu()
{
	int choice;

	cout << "\n\t===============================================================================" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t|=|        ||||||||  ||                    COST EFFECTIVE                   |=|" << endl;
	cout << "\t|=|        ||        ||                    &                                |=|" << endl;
	cout << "\t|=|        ||||||||  ||                    SEAMLESS RIDE                    |=|" << endl;
	cout << "\t|=|        ||        ||                                                     |=|" << endl;
	cout << "\t|=|        ||        ||||||||              KIWI EXPERIENCE                  |=|" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t===============================================================================" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t|=|                   -------------------------------                       |=|" << endl;
	cout << "\t|=|                   ! WELCOME TO FLIGHTLESS RIDES !                       |=|" << endl;
	cout << "\t|=|                   -------------------------------                       |=|" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t|=|                               1. Rider                                  |=|" << endl;
	cout << "\t|=|                               2. Driver                                 |=|" << endl;
	cout << "\t|=|                               3. Admin                                  |=|" << endl;
	cout << "\t|=|                               Q. Quit                                   |=|" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t===============================================================================" << endl;

	cout << "\n\tPress a key to continue: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		
		break;
	case 2:
	
		break;
	case 3:
		
		break;
	case 4:
		cout << "Thank you for visiting FL RIDES!" << endl;
		break;
	}
}
