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
time_t now()
{
	return time(0);
}
tm calcTimeDifference(int month, int day, int year, bool reverse)
{
	time_t now = time(0);
	struct tm date, tmp = tm();
	localtime_s(&date, &now);

	tmp.tm_mday = date.tm_mday;
	tmp.tm_mon = date.tm_mon;
	tmp.tm_year = date.tm_year;

	time_t date1, date2, dateDiff;

	if (!reverse)
	{
		date1 = mktime(&tmp);
		date2 = dateToTimeT(month, day, year);
	}
	else
	{
		date2 = mktime(&tmp);
		date1 = dateToTimeT(month, day, year);
	}

	dateDiff = date2 - date1;

	/*cout << date1 << endl;
	cout << date2 << endl;
	cout << dateDiff << endl;*/

	struct tm dateDiffTm;
	localtime_s(&dateDiffTm, &dateDiff);

	//cout << "DATE DIFF MONTHS: " << dateDiffTm.tm_mon << endl;
	//cout << "DATE DIFF YEARS: " << dateDiffTm.tm_year - 70 << endl;

	double sec = difftime(date2, date1);

	long days = static_cast<long>(sec / (60 * 60 * 24));
	//cout << days << endl;
	return dateDiffTm;
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
	cout << "Address: " << target_.address << endl;
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
static void showDriverMembers(const s_Driver& target_)
{
	cout << "=================================" << endl;
	cout << "[DRIVER]" << endl;
	cout << "First name: " << target_.firstName << endl;
	cout << "Last name: " << target_.lastName << endl;
	cout << "Username: " << target_.username << endl;
	cout << "Password: " << target_.password << endl;
	cout << "Email: " << target_.email << endl;
	cout << "Address: " << target_.address << endl;
	cout << "Date of birth: " << target_.DOB << endl;
	cout << "Age: " << target_.age << endl;
	cout << "Gender: " << target_.gender << endl;
	cout << "Ethnicity: " << target_.ethnicity << endl;
	cout << "Bank account number: " << target_.bankAccountNumber << endl;
	cout << "`Bank name: " << target_.bankName << endl;
	cout << "Driver licence number: " << target_.licenceNumber << endl;
	cout << "Driver licence type: " << target_.licenceType << endl;
	cout << "Vehicle registration number: " << target_.registrationNumber << endl;
	cout << "Years of driving experience: " << target_.drivingYears << endl;
	cout << "Edorsement number: " << target_.endorsementNumber << endl;
	cout << "Edorsement expiry: " << target_.endorsementExpiry << endl;
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
void showAll(const driverV_t* targetVector_)
{
	for (s_Driver item : *targetVector_)
	{
		showDriverMembers(item);
	}
}
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
	while (!cin >> *target_)
	{
		cout << "Invalid data type. Please enter an integer." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> *target_;
	}
}
bool isValidDataType(int* target_)
{
	if (!cin >> *target_)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
bool isNumber(const string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
void getLine(string* target_)
{
	string temp;
	getline(cin, temp);

	(*target_) = temp;
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
void writeToFile(s_Driver* tempUser)
{
	fstream file;
	file.open("drivers.txt", ios::app);

	if (file.is_open())
	{
		file << "firstName: " << tempUser->firstName << endl;
		file << "lastName: " << tempUser->lastName << endl;
		file << "username: " << tempUser->username << endl;
		file << "password: " << tempUser->password << endl;
		file << "gender: " << tempUser->gender << endl;
		file << "mobileNumber: " << tempUser->mobileNumber << endl;
		file << "email: " << tempUser->email << endl;
		file << "DOB: " << tempUser->DOB << endl;
		file << "age: " << tempUser->age << endl;
		file << "ethnicity: " << tempUser->ethnicity << endl;
		file << "bankAccountNumber: " << tempUser->bankAccountNumber << endl;
		file << "licenceType: " << tempUser->licenceType << endl;
		file << "drivingYears: " << tempUser->drivingYears << endl;
		file << "licenceNumber: " << tempUser->licenceNumber << endl;
		file << "licenceExpiry: " << tempUser->licenceExpiry << endl;
		file << "registrationNumber: " << tempUser->registrationNumber << endl;
		file << "registrationExpiry: " << tempUser->registrationExpiry << endl;
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
	cin.ignore();
	getLine(&tempPassenger.firstName);

	cout << "Last name: ";
	getLine(&tempPassenger.lastName);

	cout << "Username: ";
	getLine(&tempPassenger.username);

	cout << "Password: ";
	getLine(&tempPassenger.password);

	cout << "Gender (0 = male, 1 = female): ";
	do
	{
		cin >> tempPassenger.gender;

		while (!cin)
		{
			cout << "Please enter an integer." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> tempPassenger.gender;
		}

		if (tempPassenger.gender != 1 && tempPassenger.gender != 0)
		{
			cout << "Please select 0 for male or 1 for female." << endl;
		}

	} while (tempPassenger.gender != 1 && tempPassenger.gender != 0);

	cout << "Mobile number: ";
	do
	{
		cin >> tempPassenger.mobileNumber;

		if (tempPassenger.mobileNumber.size() < 6)
		{
			cout << "Please enter a valid mobile number that is no less than 6 digits." << endl;
		}

		if (tempPassenger.mobileNumber.size() > 12)
		{
			cout << "Please enter a valid mobile number that is no more than 12 digits." << endl;
		}

	} while (tempPassenger.mobileNumber.size() < 6 || tempPassenger.mobileNumber.size() > 12);

	cout << "Email:  ";
	do
	{
		cin >> tempPassenger.email;

		if ((tempPassenger.email.find("@") != string::npos) == 0 || tempPassenger.email.substr(0, tempPassenger.email.find("@")).size() == 0 || tempPassenger.email.substr(tempPassenger.email.find("@") + 1).size() == 0)
		{
			cout << "Please enter a valid email address." << endl;
			continue;
		}

		if (tempPassenger.email.size() < 5)
		{
			cout << "Email address too short. Please enter at least 5 characters." << endl;
		}

	} while (tempPassenger.email.size() < 5 || (tempPassenger.email.find("@") != string::npos) == 0 || tempPassenger.email.substr(0, tempPassenger.email.find("@")).size() == 0 || tempPassenger.email.substr(tempPassenger.email.find("@") + 1).size() == 0);

	cin.ignore();
	cout << "Address: ";
	do
	{
		getLine(&tempPassenger.address);

		if (tempPassenger.address.size() < 8)
		{
			cout << "Address too short." << endl;
		}

	} while (tempPassenger.address.size() < 8);

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
		cout << "Card number (1234-1234-1234-1234): ";
		{
			string val;
			do
			{
				cin >> tempPassenger.cardNumber;

				while (tempPassenger.cardNumber.size() != 19)
				{
					cout << "Please enter 16 digit bank account number including hyphen in between." << endl;
					cin >> tempPassenger.cardNumber;
				}

				val = tempPassenger.cardNumber.substr(0, 4) + tempPassenger.cardNumber.substr(5, 4) + tempPassenger.cardNumber.substr(10, 4) + tempPassenger.cardNumber.substr(15, 4);

				if (!isNumber(val))
				{
					cout << "Your input contained characters that are not integers. Please enter a valid card account number." << endl;
				}

				if (tempPassenger.cardNumber.size() != 19 || tempPassenger.cardNumber.substr(4, 1) != "-" || tempPassenger.cardNumber.substr(9, 1) != "-" || tempPassenger.cardNumber.substr(14, 1) != "-")
				{
					cout << "Please enter your bank account number in the following format: 12-1234-1234567-123." << endl;
				}

			} while (!isNumber(val) || tempPassenger.cardNumber.size() != 19 || tempPassenger.cardNumber.substr(4, 1) != "-" || tempPassenger.cardNumber.substr(9, 1) != "-" || tempPassenger.cardNumber.substr(14, 1) != "-");

		}

		cout << "Card expiry (mm/yy): ";
		{

			string temp;
			string month, year;
			do
			{
				cin >> temp;

				while (temp.size() != 5)
				{
					cout << "Enter card expiry date in the following format: (dd/mm)." << endl;

					cin >> temp;
				}

				if (!isNumber(temp.substr(0, 2) + temp.substr(3, 2)))
				{
					cout << "Please enter expiry date as integers." << endl;
				}

			} while (!isNumber(temp.substr(0, 2) + temp.substr(3, 2)));
			month = temp.substr(0, 2);
			year = temp.substr(3, 2);

			tempPassenger.cardExpiryM = stoi(month);
			tempPassenger.cardExpiryY = stoi(year);
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
	cout << "\tADMIN REGISTRATION " << endl;
	cout << "=================================" << endl;
	cin.ignore();

	// first name
	cout << "First name: ";
	getLine(&tempAdmin.firstName);

	// last name
	cout << "Last name: ";
	getLine(&tempAdmin.lastName);

	// username
	cout << "Username: ";
	getLine(&tempAdmin.username);

	// password
	cout << "Password: ";
	getLine(&tempAdmin.password);

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
	cin.ignore();

	// get input
	cout << "First name: ";
	getLine(&tempDriver.firstName);

	cout << "Last name: ";
	getLine(&tempDriver.lastName);

	cout << "Username: ";
	getLine(&tempDriver.username);

	cout << "Password: ";
	getLine(&tempDriver.password);

	cout << "Date of birth (dd-mm-yyyy): ";
	{
		string word, word_x, day, month, year;
		word_x = day + month + year;

		cout << word_x << endl;

		do
		{
			cin >> tempDriver.DOB;
			while (tempDriver.DOB.size() != 10)
			{
				cout << "Please enter date of birith in the following format: dd-mm-yyyy." << endl;
				cin >> tempDriver.DOB;
			}

			day = tempDriver.DOB.substr(0, 2);
			month = tempDriver.DOB.substr(3, 2);
			year = tempDriver.DOB.substr(6, 4);
			word_x = day + month + year;

			if (tempDriver.DOB.substr(2, 1) != "-" || tempDriver.DOB.substr(5, 1) != "-")
			{
				cout << "Please include hyphens in between day, month, and year." << endl;
			}

			if (!isNumber(word_x))
			{
				cout << "Please enter date of birith as intergers." << endl;
			}

		} while (tempDriver.DOB.size() != 10 || !isNumber(day + month + year) || tempDriver.DOB.substr(2, 1) != "-" || tempDriver.DOB.substr(5, 1) != "-");

		tempDriver.getAge(stoi(day), stoi(month), stoi(year));

	}
	cout << "Gender (0 = male, 1 = female): ";
	do
	{
		cin >> tempDriver.gender;

		while (!cin)
		{
			cout << "Please enter an integer." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> tempDriver.gender;
		}

		if (tempDriver.gender != 1 && tempDriver.gender != 0)
		{
			cout << "Please select 0 for male or 1 for female." << endl;
		}

	} while (tempDriver.gender != 1 && tempDriver.gender != 0);

	cout << "Mobile number: ";
	do
	{
		cin >> tempDriver.mobileNumber;

		if (tempDriver.mobileNumber.size() < 6)
		{
			cout << "Please enter a valid mobile number that is no less than 6 digits." << endl;
		}

		if (tempDriver.mobileNumber.size() > 12)
		{
			cout << "Please enter a valid mobile number that is no more than 12 digits." << endl;
		}

	} while (tempDriver.mobileNumber.size() < 6 || tempDriver.mobileNumber.size() > 12);

	cout << "Email: ";

	do
	{
		cin >> tempDriver.email;

		if ((tempDriver.email.find("@") != string::npos) == 0 || tempDriver.email.substr(0, tempDriver.email.find("@")).size() == 0 || tempDriver.email.substr(tempDriver.email.find("@") + 1).size() == 0)
		{
			cout << "Please enter a valid email address." << endl;
			continue;
		}

		if (tempDriver.email.size() < 5)
		{
			cout << "Email address too short. Please enter at least 5 characters." << endl;
		}

	} while (tempDriver.email.size() < 5 || (tempDriver.email.find("@") != string::npos) == 0 || tempDriver.email.substr(0, tempDriver.email.find("@")).size() == 0 || tempDriver.email.substr(tempDriver.email.find("@") + 1).size() == 0);

	cin.ignore();
	cout << "Address: ";
	do
	{
		getLine(&tempDriver.address);

		if (tempDriver.address.size() < 8)
		{
			cout << "Address too short." << endl;
		}

	} while (tempDriver.address.size() < 8);

	cout << "Ethnicity: ";
	cin.ignore();
	getLine(&tempDriver.ethnicity);

	cout << "Bank name: ";
	getLine(&tempDriver.bankName);

	cout << "Bank account number (Format: 12-1234-1234567-123): ";
	{
		string val;
		do
		{
			cin >> tempDriver.bankAccountNumber;

			while (tempDriver.bankAccountNumber.size() != 19)
			{
				cout << "Please enter 16 digit bank account number including hyphen in between." << endl;
				cin >> tempDriver.bankAccountNumber;
			}

			val = tempDriver.bankAccountNumber.substr(0, 2) + tempDriver.bankAccountNumber.substr(3, 4) + tempDriver.bankAccountNumber.substr(8, 7) + tempDriver.bankAccountNumber.substr(16, 3);

			if (!isNumber(val))
			{
				cout << "Your input contained characters that are not integers. Please enter a valid bank account number." << endl;
			}

			if (tempDriver.bankAccountNumber.size() != 19 || tempDriver.bankAccountNumber.substr(2, 1) != "-" || tempDriver.bankAccountNumber.substr(7, 1) != "-")
			{
				cout << "Please enter your bank account number in the following format: 12-1234-1234567-123." << endl;
			}

		} while (!isNumber(val) || tempDriver.bankAccountNumber.size() != 19 || tempDriver.bankAccountNumber.substr(2, 1) != "-" || tempDriver.bankAccountNumber.substr(7, 1) != "-");

	}
	cout << "Licence type: (0 = learner, 1 = restricted, 2 = full): ";

	do
	{
		cin >> tempDriver.licenceType;
		while (!cin)
		{
			cout << "Please select a number." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> tempDriver.licenceType;
		}

		if (tempDriver.licenceType < 0 || tempDriver.licenceType > 2)
		{
			cout << "Please select 0 for learner, 1 for restricted, or 2 for full." << endl;
		}
	} while (tempDriver.licenceType < 0 || tempDriver.licenceType > 2);

	cout << "Driver licence number: ";

	do
	{
		cin >> tempDriver.licenceNumber;

		if (tempDriver.licenceNumber.size() != 8)
		{
			cout << "Driver licence number must be 8 characters long." << endl;
		}

	} while (tempDriver.licenceNumber.size() != 8);

	cout << "Driving experience in years: ";

	do
	{
		cin >> tempDriver.drivingYears;
		while (!cin)
		{
			cout << "Please enter an integer." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> tempDriver.drivingYears;
		}

		if (tempDriver.drivingYears < 0)
		{
			cout << "Cannot enter a nagative number." << endl;
		}

	} while (tempDriver.drivingYears < 0);

	cout << "Licence expiry (dd-mm-yyyy): ";
	{

		string word, word_x, day, month, year;
		word_x = day + month + year;

		cout << word_x << endl;

		do
		{
			cin >> tempDriver.licenceExpiry;
			while (tempDriver.licenceExpiry.size() != 10)
			{
				cout << "Please enter licence expiry date in the following format: dd-mm-yyyy." << endl;
				cin >> tempDriver.licenceExpiry;
			}

			day = tempDriver.licenceExpiry.substr(0, 2);
			month = tempDriver.licenceExpiry.substr(3, 2);
			year = tempDriver.licenceExpiry.substr(6, 4);
			word_x = day + month + year;

			if (tempDriver.licenceExpiry.substr(2, 1) != "-" || tempDriver.licenceExpiry.substr(5, 1) != "-")
			{
				cout << "Please include hyphens in between day, month, and year." << endl;
			}

			if (!isNumber(word_x))
			{
				cout << "Please enter licence expiry date as intergers." << endl;
			}

		} while (tempDriver.licenceExpiry.size() != 10 || !isNumber(day + month + year) || tempDriver.licenceExpiry.substr(2, 1) != "-" || tempDriver.licenceExpiry.substr(5, 1) != "-");
	}

	cout << "Vehicle registration number: ";
	do
	{
		cin >> tempDriver.registrationNumber;

		if (tempDriver.registrationNumber.size() < 3 || tempDriver.registrationNumber.size() > 8)
		{
			cout << "Registration number must be between 3 to 8 characters" << endl;
		}
	} while (tempDriver.registrationNumber.size() < 3 || tempDriver.registrationNumber.size() > 8);

	cout << "Vehicle registration expiry (dd-mm-yyyy): ";

	{

		string word, word_x, day, month, year;
		word_x = day + month + year;

		do
		{
			cin >> tempDriver.registrationExpiry;
			while (tempDriver.registrationExpiry.size() != 10)
			{
				cout << "Please enter registration expiry date in the following format: dd-mm-yyyy." << endl;
				cin >> tempDriver.registrationExpiry;
			}

			day = tempDriver.registrationExpiry.substr(0, 2);
			month = tempDriver.registrationExpiry.substr(3, 2);
			year = tempDriver.registrationExpiry.substr(6, 4);
			word_x = day + month + year;

			if (tempDriver.registrationExpiry.substr(2, 1) != "-" || tempDriver.registrationExpiry.substr(5, 1) != "-")
			{
				cout << "Please include hyphens in between day, month, and year." << endl;
			}

			if (!isNumber(word_x))
			{
				cout << "Please enter licence expiry date as intergers." << endl;
			}

		} while (tempDriver.registrationExpiry.size() != 10 || !isNumber(day + month + year) || tempDriver.registrationExpiry.substr(2, 1) != "-" || tempDriver.registrationExpiry.substr(5, 1) != "-");
	}

	showDriverMembers(tempDriver);

	// validate input

	// check eligibility

	// generate endorsement number and expiry

	// register user

	writeToFile(&tempDriver);
	cout << "New Driver registration successful." << endl;
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
