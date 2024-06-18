// function definition here
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

// date handling functions
unsigned int getDay()
{

	time_t now = time(0);
	struct tm date;
	localtime_s(&date, &now);

	return date.tm_mday;
}
unsigned int getMonth()
{
	time_t now = time(0);
	struct tm date;
	localtime_s(&date, &now);

	return date.tm_mon + 1;
}
unsigned int getYear()
{
	time_t now = time(0);
	struct tm date;
	localtime_s(&date, &now);
	//tm* ltm = localtime(&now);
	//char dateString[200];
	//cout << ctime(&now) << endl;

	return date.tm_year + 1900;
}
bool dateIsValid(int targetMonth_, int targetYear_, int targetDay_)
{
	// checks whether a given dd/yyyy date is still valid
	time_t timeA, timeB, timeC, timeN = time(0);

	struct tm tA, tB, tC, tN;
	int timeDiffDays;

	time(&timeA);
	time(&timeB);
	time(&timeC);
	time(&timeN);

	localtime_s(&tA, &timeA);
	localtime_s(&tB, &timeB);
	localtime_s(&tC, &timeC);
	localtime_s(&tN, &timeN);

	//tB.tm_mday = 10; // day input
	tB.tm_mon = targetMonth_ - 1; // month input
	tB.tm_year = targetYear_ - 1900; // year input

	tB.tm_mday = targetDay_ == NULL ? tN.tm_mday : targetDay_;

	timeA = mktime(&tA);
	timeB = mktime(&tB);
	timeC = mktime(&tC);

	timeDiffDays = (timeB - timeA) / 60 / 60 / 24;

	return timeDiffDays > 0 ? 1 : 0;
}
time_t dateToTimeT(int month, int day, int year)
{
	// january 5, 2000 is passed as (1, 5, 2000)
	tm tmp = tm();
	tmp.tm_mday = day;
	tmp.tm_mon = month - 1;
	tmp.tm_year = year - 1900;
	return mktime(&tmp);
}
time_t badTime()
{
	return time_t(-1);
}
time_t now()
{
	return time(0);
}
long calcTimeDifference(int month, int day, int year)
{
	time_t date1 = time(0);
	time_t date2 = dateToTimeT(month, day, year);

	if ((date1 == badTime()) || (date2 == badTime()))
	{
		cout << "unable to create a time_t struct" << endl;
		return EXIT_FAILURE;
	}
	double sec = difftime(date2, date1);
	long days = static_cast<long>(sec / (60 * 60 * 24));
	cout << days << endl;
	return days;
}

// print struct members functions
static void showPassengerMembers(const s_Passenger& target_)
{
	cout << "=================================" << endl;
	cout << "[PASSENGER]" << endl;
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
	cout << "=================================" << endl;
}
static void showAdminMembers(const s_Admin& target_)
{
	cout << "=================================" << endl;
	cout << "[ADMIN]" << endl;
	cout << "First name: " << target_.firstName << endl;
	cout << "Last name: " << target_.lastName << endl;
	cout << "Username: " << target_.username << endl;
	cout << "Password: " << target_.password << endl;
	cout << "=================================" << endl;
}
void showAll(const adminV_t* targetVector_)
{
	for (s_Admin item : *targetVector_)
	{
		showAdminMembers(item);
	}
}
void showAll(const passengerV_t* targetVector_)
{
	for (s_Passenger item : *targetVector_)
	{
		showPassengerMembers(item);
	}
}
//void showAll(const driverV_t* targetVector_)
//{
//	for (s_Driver item : *targetVector_)
//	{
//		showDriverMembers(item);
//	}
//}
//void showAll(const bookingV_t* targetVector_)
//{
//	for (s_Booking item : *targetVector_)
//	{
//		showBookingMembers(item);
//	}
//}

// Input validation functions
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
bool isNumber(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

// file handling functions
void writeToFile(s_Passenger* tempUser)
{
	fstream file;
	file.open("passengers.txt", ios::app);

	if (file.is_open())
	{
		file << "firstName: " << tempUser->firstName << endl;
		file << "lastName: " << tempUser->lastName << endl;
		file << "gender: " << tempUser->gender << endl;
		file << "mobileNumber: " << tempUser->mobileNumber << endl;
		file << "email: " << tempUser->email << endl;
		file << "username: " << tempUser->username << endl;
		file << "password: " << tempUser->password << endl;
		file << "paymentMethod: " << tempUser->paymentMethod << endl;
		file << "cardNumber: " << tempUser->cardNumber << endl;
		file << "cardExpiryM: " << tempUser->cardExpiryM << endl;
		file << "cardExpiryY: " << tempUser->cardExpiryY << endl;
		file << endl;
	}

	file.close();
}
void writeToFile(s_Admin* tempUser)
{
	fstream file;
	file.open("admins.txt", ios::app);

	if (file.is_open())
	{
		file << "firstName: " << tempUser->firstName << endl;
		file << "lastName: " << tempUser->lastName << endl;
		file << "username: " << tempUser->username << endl;
		file << "password: " << tempUser->password << endl;
		file << endl;
	}

	file.close();
}
void loadUserData()
{
	string fileName = "user.txt";
	fstream file;
	file.open(fileName, ios::in);
	string line;
	string currentUserName;

	if (file.is_open())
	{
		getline(file, line);
		currentUserName = line.substr(line.find(":") + 2);

		cout << "Greetings, " << currentUserName << "!" << endl;

	}
}
void loadPassengerFile(passengerV_t* passengerVector_)
{
	string fileName = "passengers.txt"; // file to open
	fstream file; // create an fstream object
	Passenger tempUser; // create temp struct to store passenger data

	// attempt to open file with ios method of input
	file.open(fileName, ios::in);


	if (file.is_open()) // check if file successfully opened
	{
		string line; // create a storage for each line's value read from the file

		while (getline(file, line))
		{
			if (line.empty() || file.peek() == EOF)
			{
				(*passengerVector_).push_back(tempUser);
				continue;
			}

			string key = line.substr(0, line.find(":"));
			string val = line.substr(line.find(":") + 2);

			if (key == "firstName")	tempUser.firstName = val;
			if (key == "lastName")	tempUser.lastName = val;
			if (key == "gender")	tempUser.gender = stoi(val);
			if (key == "mobileNumber")	tempUser.mobileNumber = val;
			if (key == "email")	tempUser.email = val;
			if (key == "username")	tempUser.username = val;
			if (key == "password")	tempUser.password = val;
			if (key == "paymentMethod")	tempUser.paymentMethod = stoi(val);
			if (key == "cardNumber")	tempUser.cardNumber = val;
			if (key == "cardExpiryM")	tempUser.cardExpiryM = stoi(val);
			if (key == "cardExpiryY")	tempUser.cardExpiryY = stoi(val);
		}
	}
	else // if file fail to open
	{
		cout << "ERROR! Unable to open file " << fileName << endl;
	}

	file.close();
}
void loadAdminFile(adminV_t* adminVector_)
{
	string fileName = "admins.txt"; // file to open
	fstream file; // create an fstream object
	Admin tempUser; // create temp struct to store passenger data

	// attempt to open file with ios method of input
	file.open(fileName, ios::in);


	if (file.is_open()) // check if file successfully opened
	{
		string line; // create a storage for each line's value read from the file

		while (getline(file, line))
		{
			if (line.empty() || file.peek() == EOF)
			{
				(*adminVector_).push_back(tempUser);
				continue;
			}

			string key = line.substr(0, line.find(":"));
			string val = line.substr(line.find(":") + 2);

			if (key == "firstName")	tempUser.firstName = val;
			if (key == "lastName")	tempUser.lastName = val;
			if (key == "username")	tempUser.username = val;
			if (key == "password")	tempUser.password = val;

		}
	}
	else // if file fail to open
	{
		cout << "ERROR! Unable to open file " << fileName << endl;
	}

	file.close();
}

// user registration functions
void registerNewPassenger()
{
	// create struct
	s_Passenger tempPassenger;

	cout << "=================================" << endl;
	cout << "\tPASSENGER REGISTRATION " << endl;
	cout << "=================================" << endl;

	// first name
	cout << "First name: ";
	getline(cin, tempPassenger.firstName);

	// last name
	cout << "Last name: ";
	getline(cin, tempPassenger.lastName);

	// username
	cout << "Username: ";
	getline(cin, tempPassenger.username);

	// password
	cout << "Password: ";
	getline(cin, tempPassenger.password);

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
		while (dateIsValid(tempPassenger.cardExpiryM, tempPassenger.cardExpiryY))
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

	writeToFile(&tempPassenger);
	cout << "New passenger registration successful." << endl;
}
void registerNewAdmin()
{
	// create struct
	s_Admin tempAdmin;

	cout << "=================================" << endl;
	cout << "\ADMIN REGISTRATION " << endl;
	cout << "=================================" << endl;

	// first name
	cout << "First name: ";
	getline(cin, tempAdmin.firstName);

	// last name
	cout << "Last name: ";
	getline(cin, tempAdmin.lastName);

	// username
	cout << "Username: ";
	getline(cin, tempAdmin.username);

	// password
	cout << "Password: ";
	getline(cin, tempAdmin.password);

	writeToFile(&tempAdmin);
	cout << "New admin registration successful." << endl;
}
void registerNewDriver()
{
	// create temp struct
	s_Driver tempDriver;

	cout << "=================================" << endl;
	cout << "\tDRIVER REGISTRATION " << endl;
	cout << "=================================" << endl;

	// get input
	cout << "First name: ";
	getline(cin, tempDriver.firstName);

	cout << "Last name: ";
	getline(cin, tempDriver.lastName);

	cout << "Username: ";
	getline(cin, tempDriver.username);

	cout << "Password: ";
	getline(cin, tempDriver.password);

	cout << "Date of birth (dd-mm-yyyy): ";
	getline(cin, tempDriver.DOB);

	cout << "Gender (0 = male, 1 = female): ";
	cin >> tempDriver.gender;

	cout << "Mobile number: ";
	cin >> tempDriver.mobileNumber;

	cout << "Email: ";
	getline(cin, tempDriver.email);

	cout << "Ethnicity: ";
	getline(cin, tempDriver.ethnicity);

	cout << "Bank account number (Format: 12-1234-1234567-123): ";
	cin >> tempDriver.bankAccountNumber;

	cout << "Licence type: (0 = learner, 1 = restricted, 2 = full): ";
	cin >> tempDriver.licenceType;

	cout << "Driving experience in years: ";
	cin >> tempDriver.drivingYears;

	cout << "Licence expiry (dd-mm-yyyy): ";
	getline(cin, tempDriver.licenceExpiry);

	cout << "Vehicle registration number: ";
	getline(cin, tempDriver.registrationNumber);

	cout << "Vehicle registration expiry (dd-mm-yyyy): ";
	getline(cin, tempDriver.licenceExpiry);

	// validate input

	// check eligibility

	// generate endorsement number and expiry

	// register user
}

// UI functions
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
