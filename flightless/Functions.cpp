// function definition here

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Header.h"
#include <stdio.h>
#include <ctime>
#include <fstream>
#include<windows.h>
using namespace std;

passengerV_t passengerVector;
adminV_t adminVector;
driverV_t driverVector;
bookingV_t bookingVector;

s_Passenger activeUserPassenger;
s_Driver activeUserDriver;
s_Admin activeUserAdmin;
UserType activeUserType;

bool isSignedIn = 0;

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
	cout << "Bank name: " << target_.bankName << endl;
	cout << "Driver licence number: " << target_.licenceNumber << endl;
	cout << "Driver licence type: " << target_.licenceType << endl;
	cout << "Vehicle registration number: " << target_.registrationNumber << endl;
	cout << "Vehicle make and model: " << target_.vehicleMakeModel << endl;
	cout << "Vehicle year: " << target_.vehicleModelYear << endl;
	cout << "Years of driving experience: " << target_.drivingYears << endl;
	cout << "Edorsement number: " << target_.endorsementNumber << endl;
	cout << "Edorsement expiry: " << target_.endorsementExpiry << endl;
	cout << "WOF expiry: " << target_.wofExpiry << endl;
	cout << "=================================" << endl;
}
static void showBookingMembers(const s_Booking& target_)
{
	cout << "=================================" << endl;
	cout << target_.tripNumber << endl;
	cout << target_.customerName << endl;
	cout << target_.customerMobileNumber << endl;
	cout << target_.startAddress << endl;
	cout << target_.endAddress << endl;
	cout << target_.bookingDate << endl;
	cout << target_.bookingTime << endl;
	cout << target_.numberOfPersons << endl;
	cout << target_.notes << endl;
	cout << target_.luggageType << endl;
	cout << target_.cardNumber << endl;
	cout << target_.cardExpiry << endl;
	cout << target_.isPaid << endl;
	cout << target_.isAvailable << endl;
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
void showAll(const bookingV_t* targetVector_)
{
	for (s_Booking item : *targetVector_)
	{
		showBookingMembers(item);
	}
}

// print reports / search
void listItems(passengerV_t* targetVector_, bool isSearch, string keyword_)
{
	loadFiles();
	//if ((*targetVector_).size() == 0)
	//{
	//	cout << "No registered users." << endl;
	//	return;
	//}

	//if (isSearch)
	//{
	//	// search list
	//	for (int i = 0; i < (*targetVector_).size(); i++)
	//	{
	//		if ((*targetVector_)[i].firstName == activeUserPassenger.firstName && (*targetVector_)[i].lastName == activeUserPassenger.lastName)
	//		{
	//			(*targetVector_)[i].showSummary();
	//		}
	//	}
	//}
	//else
	//{
	//	// show all
	//	for (int i = 0; i < (*targetVector_).size(); i++)
	//	{
	//		(*targetVector_)[i].showSummary();
	//	}

	//}
}
void listItems(adminV_t* targetVector_, bool isSearch, string keyword_)
{
	loadFiles();
	if (isSearch)
	{
		// search list
	}
	else
	{
		// show all
		if ((*targetVector_).size() > 0)
		{
			for (int i = 0; i < (*targetVector_).size(); i++)
			{
				(*targetVector_)[i].showSummary();
			}
		}
		else
		{
			cout << "No registered users." << endl;
		}
	}
}
void listItems(driverV_t* targetVector_, bool isSearch, string keyword_)
{
	loadFiles();
	if (isSearch)
	{
		if (isSearch)
		{
			// search list
		}
		else
		{
			// show all
			if ((*targetVector_).size() > 0)
			{
				for (int i = 0; i < (*targetVector_).size(); i++)
				{
					(*targetVector_)[i].showSummary();
				}
			}
			else
			{
				cout << "No registered users." << endl;
			}
		}

	}
	else
	{
		// show all
		if (isSearch)
		{
			// search list
		}
		else
		{
			// show all
			if ((*targetVector_).size() > 0)
			{
				for (int i = 0; i < (*targetVector_).size(); i++)
				{
					(*targetVector_)[i].showSummary();
				}
			}
			else
			{
				cout << "No registered users." << endl;
			}
		}
	}
}
void listItems(bookingV_t* targetVector_, bool isAvailable, int searchParam)
{
	loadFiles();
	int counter = 0;
	if ((*targetVector_).size() == 0)
	{
		cout << "You have no active bookings." << endl;
		return;
	}

	for (int i = 0; i < (*targetVector_).size(); i++)
	{

		if (searchParam == 1) // name
		{
			if (activeUserPassenger.firstName + " " + activeUserPassenger.lastName == (*targetVector_)[i].customerName)
			{
				if (isAvailable)
				{
					if ((*targetVector_)[i].isAvailable)
					{
						counter++;
						(*targetVector_)[i].showSummary();
					}
				}
				else
				{
					counter++;
					(*targetVector_)[i].showSummary();
				}
			}
		}

		if (searchParam == 2) // date
		{

		}
		if (searchParam == 0)
		{
			if (isAvailable)
			{
				if ((*targetVector_)[i].isAvailable)
				{
					counter++;
					(*targetVector_)[i].showSummary();
				}
			}
			else
			{
				(*targetVector_)[i].showSummary();
			}
		}

	}

	if (counter == 0)
	{
		cout << "There are no bookings to display." << endl;
	}

}

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
void writeToFile(const s_Passenger* tempUser)
{
	fstream file;
	file.open("passengers.txt", ios::app);

	if (file.is_open())
	{
		file << "firstName: " << tempUser->firstName << endl;
		file << "lastName: " << tempUser->lastName << endl;
		file << "gender: " << tempUser->gender << endl;
		file << "mobileNumber: " << tempUser->mobileNumber << endl;
		file << "address: " << tempUser->address << endl;
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
void writeToFile(const s_Driver* tempUser)
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
		file << "address: " << tempUser->address << endl;
		file << "mobileNumber: " << tempUser->mobileNumber << endl;
		file << "email: " << tempUser->email << endl;
		file << "DOB: " << tempUser->DOB << endl;
		file << "age: " << tempUser->age << endl;
		file << "ethnicity: " << tempUser->ethnicity << endl;
		file << "bankAccountNumber: " << tempUser->bankName << endl;
		file << "bankName: " << tempUser->bankAccountNumber << endl;
		file << "licenceType: " << tempUser->licenceType << endl;
		file << "drivingYears: " << tempUser->drivingYears << endl;
		file << "licenceNumber: " << tempUser->licenceNumber << endl;
		file << "licenceExpiry: " << tempUser->licenceExpiry << endl;
		file << "vehicleMakeModel: " << tempUser->vehicleMakeModel << endl;
		file << "vehicleModelYear: " << tempUser->vehicleModelYear << endl;
		file << "registrationNumber: " << tempUser->registrationNumber << endl;
		file << "registrationExpiry: " << tempUser->registrationExpiry << endl;
		file << "wofExpiry: " << tempUser->wofExpiry << endl;
		file << endl;
	}

	file.close();
}
void writeToFile(const s_Admin* tempUser)
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
void writeToFile(const s_Booking* tempBooking)
{
	fstream file;
	file.open("bookings.txt", ios::app);

	if (file.is_open())
	{
		file << "tripNumber: " << tempBooking->tripNumber << endl;
		file << "customerName: " << tempBooking->customerName << endl;
		file << "customerMobileNumber: " << tempBooking->customerMobileNumber << endl;
		file << "startAddress: " << tempBooking->startAddress << endl;
		file << "endAddress: " << tempBooking->endAddress << endl;
		file << "bookingDate: " << tempBooking->bookingDate << endl;
		file << "bookingTime: " << tempBooking->bookingTime << endl;
		file << "numberOfPersons: " << tempBooking->numberOfPersons << endl;
		file << "notes: " << tempBooking->notes << endl;
		file << "luggageType: " << tempBooking->luggageType << endl;
		file << "cardNumber: " << tempBooking->cardNumber << endl;
		file << "cardExpiry: " << tempBooking->cardExpiry << endl;
		file << "isPaid: " << tempBooking->isPaid << endl;
		file << "isAvailable: " << tempBooking->isAvailable << endl;
		file << endl;
	}

	file.close();
}
void setActiveUser(const s_Passenger* target_)
{
	activeUserType = passenger;
	activeUserPassenger = *target_;
	isSignedIn = 1;
	// go to passenger dashboard

}
void setActiveUser(const s_Driver* target_)
{
	activeUserType = driver;
	activeUserDriver = *target_;
	isSignedIn = 1;
	// go to driver dashboard
}
void setActiveUser(const s_Admin* target_)
{
	activeUserType = admin;
	activeUserAdmin = *target_;
	isSignedIn = 1;
	// go to admin dashboard
}

void loadFiles()
{
	loadAdminFile(&adminVector);
	loadPassengerFile(&passengerVector);
	loadDriverFile(&driverVector);
	loadBookingFile(&bookingVector);
}
void loadPassengerFile(passengerV_t* passengerVector_)
{
	(*passengerVector_).clear();
	string fileName = "passengers.txt"; // file to open
	fstream file; // create an fstream object
	Passenger tempUser; // create temp struct to store passenger data

	// attempt to open file with ios method of input
	file.open(fileName, ios::in);

	if (file.is_open()) // check if file successfully opened
	{
		string line; // create a storage for each line's value read from the file
		if (file.peek() != ifstream::traits_type::eof())
		{
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
				if (key == "address")	tempUser.address = val;
				if (key == "username")	tempUser.username = val;
				if (key == "password")	tempUser.password = val;
				if (key == "paymentMethod")	tempUser.paymentMethod = stoi(val);
				if (key == "cardNumber")	tempUser.cardNumber = val;
				if (key == "cardExpiryM")	tempUser.cardExpiryM = stoi(val);
				if (key == "cardExpiryY")	tempUser.cardExpiryY = stoi(val);
			}
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
	(*adminVector_).clear();
	string fileName = "admins.txt"; // file to open
	fstream file; // create an fstream object
	Admin tempUser; // create temp struct to store passenger data

	// attempt to open file with ios method of input
	file.open(fileName, ios::in);

	if (file.is_open()) // check if file successfully opened
	{
		string line; // create a storage for each line's value read from the file

		if (file.peek() != ifstream::traits_type::eof())
		{
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
	}
	else // if file fail to open
	{
		cout << "ERROR! Unable to open file " << fileName << endl;
	}

	file.close();
}
void loadDriverFile(driverV_t* driverVector_)
{
	(*driverVector_).clear();
	string fileName = "drivers.txt"; // file to open
	fstream file; // create an fstream object
	Driver tempUser; // create temp struct to store passenger data

	// attempt to open file with ios method of input
	file.open(fileName, ios::in);

	if (file.is_open()) // check if file successfully opened
	{
		string line; // create a storage for each line's value read from the file

		if (file.peek() != ifstream::traits_type::eof())
		{
			while (getline(file, line))
			{
				if (line.empty() || file.peek() == EOF)
				{
					(*driverVector_).push_back(tempUser);
					continue;
				}

				string key = line.substr(0, line.find(":"));
				string val = line.substr(line.find(":") + 2);

				if (key == "firstName")	tempUser.firstName = val;
				if (key == "lastName")	tempUser.lastName = val;
				if (key == "gender")	tempUser.gender = stoi(val);
				if (key == "mobileNumber")	tempUser.mobileNumber = val;
				if (key == "email")	tempUser.email = val;
				if (key == "address")	tempUser.address = val;
				if (key == "DOB")	tempUser.DOB = val;
				if (key == "age")	tempUser.age = stoi(val);
				if (key == "ethnicity")	tempUser.ethnicity = val;
				if (key == "bankAccountNumber")	tempUser.bankAccountNumber = val;
				if (key == "username")	tempUser.username = val;
				if (key == "password")	tempUser.password = val;
				if (key == "bankName")	tempUser.bankName = val;
				if (key == "licenceType")	tempUser.licenceType = stoi(val);
				if (key == "drivingYears")	tempUser.drivingYears = stoi(val);
				if (key == "licenceNumber")	tempUser.licenceNumber = val;
				if (key == "licenceExpiry")	tempUser.licenceExpiry = val;
				if (key == "endorsementNumber")	tempUser.endorsementNumber = val;
				if (key == "endorsementExpiry")	tempUser.endorsementExpiry = val;
				if (key == "vehicleMakeModel")	tempUser.vehicleMakeModel = val;
				if (key == "vehicleModelYear")	tempUser.vehicleModelYear = stoi(val);
				if (key == "registrationNumber")	tempUser.registrationNumber = val;
				if (key == "registrationExpiry")	tempUser.registrationExpiry = val;
				if (key == "wofExpiry")	tempUser.wofExpiry = val;
			}

		}
	}
	else // if file fail to open
	{
		cout << "ERROR! Unable to open file " << fileName << endl;
	}

	file.close();
}
void loadBookingFile(bookingV_t* bookingVector_)
{
	(*bookingVector_).clear();
	string fileName = "bookings.txt"; // file to open
	fstream file; // create an fstream object
	Booking tempBooking; // create temp struct to store passenger data

	// attempt to open file with ios method of input
	file.open(fileName, ios::in);

	if (file.is_open()) // check if file successfully opened
	{
		string line; // create a storage for each line's value read from the file

		if (file.peek() != ifstream::traits_type::eof())
		{
			while (getline(file, line))
			{
				if (line.empty() || file.peek() == EOF)
				{
					(*bookingVector_).push_back(tempBooking);
					continue;
				}

				string key = line.substr(0, line.find(":"));
				string val = line.substr(line.find(":") + 2);

				if (key == "tripNumber") tempBooking.tripNumber = stoll(val);
				if (key == "customerName")	tempBooking.customerName = val;
				if (key == "customerMobileNumber")	tempBooking.customerMobileNumber = val;
				if (key == "startAddress")	tempBooking.startAddress = val;
				if (key == "endAddress")	tempBooking.endAddress = val;
				if (key == "bookingDate")	tempBooking.bookingDate = val;
				if (key == "bookingTime")	tempBooking.bookingTime = val;
				if (key == "numberOfPersons")	tempBooking.numberOfPersons = stoi(val);
				if (key == "notes")	tempBooking.notes = val;
				if (key == "luggageType")	tempBooking.luggageType = stoi(val);
				if (key == "cardNumber")	tempBooking.cardNumber = val;
				if (key == "cardExpiry")	tempBooking.cardExpiry = val;
				if (key == "isPaid")	tempBooking.isPaid = stoi(val);
				if (key == "isAvailable")	tempBooking.isAvailable = stoi(val);
			}

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

	cout << "-------------------------" << endl;
	cout << "  PASSENGER REGISTRATION " << endl;
	cout << "-------------------------" << endl;

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

	// confirmation or cancel
	{
		int x;
		cout << "Confirm registration? (1: confirm, 2: cancel) " << endl;
		do
		{
			cin >> x;

			while (!cin || to_string(x).size() != 1)
			{
				cout << "Select 1 for confirm or 2 for cancel." << endl;
				cin.clear();
				cin.ignore(100, '\n');
				cin >> x;
			}

		} while (to_string(x).size() != 1 || !cin);

		if (x == 1)
		{
			writeToFile(&tempPassenger);
			cout << "New passenger registration successful." << endl;
			loadFiles();
			Sleep(2000);
			system("cls");
			signInRegMenu();
		}
		else if (x == 2)
		{
			system("cls");
			signInRegMenu();	// return to main menu
		}
	}

}
void registerNewAdmin()
{
	// create struct
	s_Admin tempAdmin;

	cout << "-------------------------" << endl;
	cout << "    ADMIN REGISTRATION   " << endl;
	cout << "-------------------------" << endl;
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

	// confirmation or cancel
	{
		int x;
		cout << "Confirm registration? (1: confirm, 2: cancel) " << endl;
		do
		{
			cin >> x;

			while (!cin || to_string(x).size() != 1)
			{
				cout << "Select 1 for confirm or 2 for cancel." << endl;
				cin.clear();
				cin.ignore(100, '\n');
				cin >> x;
			}

		} while (to_string(x).size() != 1 || !cin);

		if (x == 1)
		{
			writeToFile(&tempAdmin);
			cout << "New admin registration successful." << endl;
			loadFiles();
			Sleep(2000);
			system("cls");
			signInRegMenu();
		}
		else if (x == 2)
		{
			system("cls");
			signInRegMenu();	// return to main menu
		}
	}
}
void registerNewDriver()
{
	// create temp struct
	s_Driver tempDriver;

	cout << "-------------------------" << endl;
	cout << "   DRIVER REGISTRATION   " << endl;
	cout << "-------------------------" << endl;
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
				cout << "Please enter date of birth as intergers." << endl;
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

			if (!tempDriver.isDatePositive(&tempDriver.licenceExpiry))
			{
				cout << "The licence expiry you entered is expired." << endl;
			}

		} while (tempDriver.licenceExpiry.size() != 10 ||
			!isNumber(day + month + year) ||
			tempDriver.licenceExpiry.substr(2, 1) != "-" ||
			tempDriver.licenceExpiry.substr(5, 1) != "-" ||
			!tempDriver.isDatePositive(&tempDriver.licenceExpiry));
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
				cout << "Please enter registration expiry date as intergers." << endl;
			}

			if (!tempDriver.isDatePositive(&tempDriver.registrationExpiry))
			{
				cout << "The registration expiry you entered is expired." << endl;
			}

		} while (tempDriver.registrationExpiry.size() != 10 ||
			!isNumber(day + month + year) ||
			tempDriver.registrationExpiry.substr(2, 1) != "-" ||
			tempDriver.registrationExpiry.substr(5, 1) != "-" ||
			!tempDriver.isDatePositive(&tempDriver.registrationExpiry));
	}

	cout << "Vehicle Make and Model: ";
	do
	{
		cin.ignore();
		getLine(&tempDriver.vehicleMakeModel);

		if (tempDriver.vehicleMakeModel.size() < 5)
		{
			cout << "Make and model too short. Please enter a valid vehicle make and model." << endl;
		}
	} while (tempDriver.vehicleMakeModel.size() < 5);

	cout << "Vehicle year: ";
	do
	{
		cin >> tempDriver.vehicleModelYear;

		while (!cin)
		{
			cout << "Please enter your vehicle year as an integer in the following format: yyyy." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> tempDriver.vehicleModelYear;
		}

		if (to_string(tempDriver.vehicleModelYear).size() != 4)
		{
			cout << "Please enter your vehicle year in the following format: yyyy." << endl;
		}
	} while (to_string(tempDriver.vehicleModelYear).size() != 4);

	cout << "WOF expiry (dd-mm-yyyy): ";
	{

		string word, word_x, day, month, year;
		word_x = day + month + year;

		do
		{
			cin >> tempDriver.wofExpiry;
			while (tempDriver.wofExpiry.size() != 10)
			{
				cout << "Please enter WOF expiry date in the following format: dd-mm-yyyy." << endl;
				cin >> tempDriver.wofExpiry;
			}

			day = tempDriver.wofExpiry.substr(0, 2);
			month = tempDriver.wofExpiry.substr(3, 2);
			year = tempDriver.wofExpiry.substr(6, 4);
			word_x = day + month + year;

			if (tempDriver.wofExpiry.substr(2, 1) != "-" || tempDriver.wofExpiry.substr(5, 1) != "-")
			{
				cout << "Please include hyphens in between day, month, and year." << endl;
			}

			if (!isNumber(word_x))
			{
				cout << "Please enter WOF expiry date as intergers." << endl;
			}

			if (!tempDriver.isDatePositive(&tempDriver.wofExpiry))
			{
				cout << "The WOF expiry you entered is expired." << endl;
			}

		} while (tempDriver.wofExpiry.size() != 10 ||
			!isNumber(day + month + year) ||
			tempDriver.wofExpiry.substr(2, 1) != "-" ||
			tempDriver.wofExpiry.substr(5, 1) != "-" ||
			!tempDriver.isDatePositive(&tempDriver.wofExpiry));
	}

	if (tempDriver.isEligible())
	{
		// confirmation or cancel
		int x;
		cout << "Confirm registration? (1: confirm, 2: cancel) " << endl;
		do
		{
			cin >> x;

			while (!cin || to_string(x).size() != 1)
			{
				cout << "Select 1 for confirm or 2 for cancel." << endl;
				cin.clear();
				cin.ignore(100, '\n');
				cin >> x;
			}

		} while (to_string(x).size() != 1 || !cin);

		if (x == 1)
		{
			writeToFile(&tempDriver);
			cout << "New driver registration successful." << endl;
			loadFiles();
			Sleep(2000);
			system("cls");
			signInRegMenu();
		}
		else if (x == 2)
		{
			system("cls");
			signInRegMenu();	// return to main menu
		}

	}
	else
	{
		int selection;
		cout << "You are not eligible to register as a driver." << endl;
		cout << "Would you like to complete another registration? (1: yes, 0: no)";

		do
		{
			cin >> selection;

			while (!cin)
			{
				cout << "Please select 1 for yes or 0 for no." << endl;
				cin >> selection;
			}

			if (to_string(selection).size() != 1)
			{
				cout << "Please enter 1 digit, 1 for yes or 0 for no." << endl;
			}

			if (selection == 1)
			{
				registerNewDriver();
			}
			else if (selection == 0)
			{
				signInRegMenu();
			}

		} while (to_string(selection).size() != 1);

	}
}

// trip booking form
void createNewBooking()
{
	s_Booking tempBooking;

	cout << "-------------------------" << endl;
	cout << "       NEW BOOKING       " << endl;
	cout << "-------------------------" << endl;

	// get inputs
	cin.ignore();
	cout << "Pickup address: ";
	do
	{
		getLine(&tempBooking.startAddress);
		if (tempBooking.startAddress.size() < 5)
		{
			cout << "Address too short. Please enter a valid address." << endl;
		}

	} while (tempBooking.startAddress.size() < 5);

	cout << "Destination: ";
	do
	{
		getLine(&tempBooking.endAddress);
		if (tempBooking.endAddress.size() < 5)
		{
			cout << "Address too short. Please enter a valid address." << endl;
		}

		if (tempBooking.endAddress == tempBooking.startAddress)
		{
			cout << "Destination cannot be the same as pickup address. Please enter a different destination." << endl;
		}

	} while (tempBooking.endAddress.size() < 5 || tempBooking.endAddress == tempBooking.startAddress);

	cout << "Number of passengers: ";
	do
	{
		cin >> tempBooking.numberOfPersons;

		while (!cin)
		{
			cout << "Invalid input. Please enter a number." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> tempBooking.numberOfPersons;
		}

		if (tempBooking.numberOfPersons > 4)
		{
			cout << "Cannot have more than 4 passengers." << endl;
		}

		if (tempBooking.numberOfPersons < 1)
		{
			cout << "Must have at least 1 passenger." << endl;
		}

	} while (tempBooking.numberOfPersons > 4 || tempBooking.numberOfPersons < 1);

	cin.ignore();
	cout << "Accessibility notes (max 50 characters): ";
	do
	{
		getLine(&tempBooking.notes);
		while (tempBooking.notes.size() > 50)
		{
			cout << "Message too long. Max input is 50 characters." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			getLine(&tempBooking.notes);

		}

	} while (tempBooking.notes.size() > 50);

	cout << "Luggage weight (1: Normal, 2: Heavy): ";
	do
	{
		cin >> tempBooking.luggageType;

		while (!cin)
		{
			cout << "Please enter an integer. 1 for normal luggage or 2 for heavy luggage." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}

		if (tempBooking.luggageType != 1 && tempBooking.luggageType != 2)
		{
			cout << "Please enter 1 for normal luggage or 2 for heavy luggage." << endl;
		}
	} while (tempBooking.luggageType != 1 && tempBooking.luggageType != 2);

	cout << "-------------------------" << endl;
	cout << "  YOUR BOOKING SUMMARY   " << endl;
	cout << "-------------------------" << endl;

	tempBooking.showSummary();

	// confirmation or cancel
	{

		int x;
		cout << "Confirm booking? (1: confirm, 2: cancel) " << endl;
		do
		{
			cin >> x;

			while (!cin || to_string(x).size() != 1)
			{
				cout << "Select 1 for confirm or 2 for cancel." << endl;
				cin.clear();
				cin.ignore(100, '\n');
				cin >> x;
			}

		} while (to_string(x).size() != 1 || !cin);

		if (x == 1)
		{
			writeToFile(&tempBooking);
			cout << "New booking successful." << endl;
			loadFiles();
			Sleep(2000);
		}

		system("cls");
		dashboard(&activeUserType);
	}
}

// user sign in functions
void signInForm(int userType)
{

	while (1)
	{
		system("cls");
		bool isGood = 0;
		string username, password;

		switch (userType)
		{
		case 1:
			cout << "-------------------------" << endl;
			cout << "    PASSENGER SIGN IN    " << endl;
			cout << "-------------------------" << endl;

			cin.ignore();
			cout << "Username: ";
			getLine(&username);
			cout << "Password: ";
			getLine(&password);

			for (s_Passenger p : passengerVector)
			{
				// if user found and credentials match
				if (p.username == username && p.password == password)
				{
					isGood = 1;
					cout << "User found." << endl;
					setActiveUser(&p);
					Sleep(2000);
					system("cls");
					dashboard(&activeUserType);
					break;
				}
				isGood = 0;
			}

			// if user not found or credentials don't match
			if (!isGood)
			{
				int x;
				cout << "Your username and password credentials do not match or user does not exist." << endl;
				cout << "Try again? (1: yes, 2: no) ";
				do
				{
					cin >> x;

					while (!cin || to_string(x).size() != 1)
					{
						cout << "Select 1 for yes or 2 for no." << endl;
						cin.clear();
						cin.ignore(100, '\n');
						cin >> x;
					}

				} while (to_string(x).size() != 1 || !cin);

				if (x == 1)
				{
					break;
				}
				else if (x == 2)
				{

					system("cls");
					signInRegMenu();	// return to main menu
				}
			}

			break;
		case 2:
			cout << "-------------------------" << endl;
			cout << "      DRIVER SIGN IN     " << endl;
			cout << "-------------------------" << endl;

			cin.ignore();
			cout << "Username: ";
			getLine(&username);
			cout << "Password: ";
			getLine(&password);

			for (s_Driver p : driverVector)
			{
				// if user found and credentials match
				if (p.username == username && p.password == password)
				{
					isGood = 1;
					cout << "User found." << endl;
					setActiveUser(&p);
					Sleep(2000);
					system("cls");
					dashboard(&activeUserType);
					break;
				}
				isGood = 0;
			}

			// if user not found or credentials don't match
			if (!isGood)
			{
				int x;
				cout << "Your username and password credentials do not match or user does not exist." << endl;
				cout << "Try again? (1: yes, 2: no) ";
				do
				{
					cin >> x;

					while (!cin || to_string(x).size() != 1)
					{
						cout << "Select 1 for yes or 2 for no." << endl;
						cin.clear();
						cin.ignore(100, '\n');
						cin >> x;
					}

				} while (to_string(x).size() != 1 || !cin);

				if (x == 1)
				{
					break;
				}
				else if (x == 2)
				{
					system("cls");
					signInRegMenu();	// return to main menu
				}
			}

			break;
		case 3:
			cout << "-------------------------" << endl;
			cout << "      ADMIN SIGN IN      " << endl;
			cout << "-------------------------" << endl;

			cin.ignore();
			cout << "Username: ";
			getLine(&username);
			cout << "Password: ";
			getLine(&password);

			for (s_Admin p : adminVector)
			{
				// if user found and credentials match
				if (p.username == username && p.password == password)
				{
					isGood = 1;
					cout << "User found." << endl;
					setActiveUser(&p);
					Sleep(2000);
					system("cls");
					dashboard(&activeUserType);
					break;
				}
				isGood = 0;
			}

			// if user not found or credentials don't match
			if (!isGood)
			{
				int x;
				cout << "Your username and password credentials do not match or user does not exist." << endl;
				cout << "Try again? (1: yes, 2: no) ";
				do
				{
					cin >> x;

					while (!cin || to_string(x).size() != 1)
					{
						cout << "Select 1 for yes or 2 for no." << endl;
						cin.clear();
						cin.ignore(100, '\n');
						cin >> x;
					}

				} while (to_string(x).size() != 1 || !cin);

				if (x == 1)
				{
					break;
				}
				else if (x == 2)
				{
					system("cls");
					signInRegMenu();	// return to main menu
				}
			}

			break;
		}

	}
}

// driver dashboard functions
void bookingAcceptance()
{
	int selection;

	// reload files
	loadFiles();
	// create temp vector storage
	bookingV_t tempAvailableBookings;

	// iterate through available bookings and store in temp vector
	cout << "-------------------------" << endl;
	cout << "    AVAILABLE BOOKINGS   " << endl;
	cout << "-------------------------" << endl;
	cout << "Select the number of booking you wish to accept." << endl;
	cout << endl;
	if (bookingVector.size() == 0)
	{
		cout << "There are no available bookings." << endl;
	}
	else
	{
		for (int i = 0; i < bookingVector.size(); i++)
		{
			if (bookingVector[i].isAvailable)
			{
				tempAvailableBookings.push_back(bookingVector[i]);
			}
		}
	}

	for (int i = 0; i < tempAvailableBookings.size(); i++)
	{
		cout << i + 1 << ". " << tempAvailableBookings[i].startAddress << " --> " << tempAvailableBookings[i].endAddress << endl;
	}

	// user selection
	cout << endl;
	cout << "0. Return to dashboard." << endl;
	userSelectionInput(&selection);
	while (selection < 0 || selection > tempAvailableBookings.size())
	{
		cout << "Please select from the menu." << endl;
		userSelectionInput(&selection);
	}
	if (selection == 0)
	{
		system("cls");
		dashboard(&activeUserType);
	}
	for (int i = 0; i < tempAvailableBookings.size(); i++)
	{
		if (selection == i + 1)
		{
			// view booking in full details
			//Sleep(2000);
			system("cls");
			bookingAcceptanceSingle(&tempAvailableBookings[i]);
		}
	}

}
void bookingAcceptanceSingle(s_Booking* target_)
{
	int selection;
	(*target_).showSummary();
	cout << endl;
	cout << "Would you like to accept this booking? (1: yes, 2: no)" << endl;
	userSelectionInput(&selection);

	switch (selection)
	{
	case 1:
		system("cls");
		acceptBooking(target_);
		break;
	case 2:
		//Sleep(2000);
		system("cls");
		bookingAcceptance();
		break;
	default:
		cout << "Please select 1 to accept or 2 to cancel." << endl;
		break;
	}

}
void acceptBooking(s_Booking* target_)
{
	// store trip number
	long long tripNo = target_->tripNumber;
	vector<string> tempLine;

	// read bookings.txt and store each line in a temp vector
	string fileName = "bookings.txt";
	fstream file;

	// attempt to open file with ios method of input
	file.open(fileName, ios::in);

	if (file.is_open()) // check if file successfully opened
	{
		string line; // create a storage for each line's value read from the file
		if (file.peek() != ifstream::traits_type::eof())
		{
			while (getline(file, line))
			{
				tempLine.push_back(line);
			}
		}
	}
	else // if file fail to open
	{
		cout << "ERROR! Unable to open file " << fileName << endl;
	}

	file.close();

	// iterate and find trip number and replace
	for (int i = 0; i < tempLine.size(); i++)
	{
		if (tempLine[i].find(to_string(tripNo)) != string::npos)
		{
			// skip n-number of indeces and replace value of vector
			tempLine[i + 13] = "isAvailable: 0";
		}
	}

	// overwrite bookings.txt with temp vector values
	file.open(fileName);
	if (file.is_open())
	{
		for (int i = 0; i < tempLine.size(); i++)
		{
			file << tempLine[i] << endl;
		}
	}

	file.close();

	getTripRecords(1, target_);
}
void setTripRecord(vector<string>* tempLines, s_Booking* target_)
{

	string fileName = "tripRecords.txt";
	vector<string> tempLine;

	// import all lines
	// open file save lines to temp vector
	fstream file;
	file.open(fileName, ios::in);
	if (file.is_open()) // check if file successfully opened
	{
		string line; // create a storage for each line's value read from the file
		if (file.peek() != ifstream::traits_type::eof())
		{
			while (getline(file, line))
			{
				tempLine.push_back(line);
			}
		}
	}
	else // if file fail to open
	{
		cout << "ERROR! Unable to open file " << fileName << endl;
	}

	file.close();

	bool isUserFound = 0;
	int startingIndex = 1;

	if (tempLine.size() == 0)
	{
		tempLine.push_back("");
		tempLine.push_back(activeUserDriver.firstName + " " + activeUserDriver.lastName);
		tempLine.push_back(to_string(target_->tripNumber));
	}
	else
	{

		for (int i = 0; i < tempLine.size(); i++)
		{
			// find name
			if (tempLine[i] == activeUserDriver.firstName + " " + activeUserDriver.lastName)
			{
				cout << "Match name" << endl;
				for (int x = i; x < tempLine.size(); x++)
				{
					startingIndex = i + 1;
					if (!tempLine[x].empty())
					{

						startingIndex++;
					}
					else
					{
						break;
					}
				}

				tempLine.insert(tempLine.begin() + startingIndex, to_string(target_->tripNumber));

				break;
			}
			// if reached end of iteration and no match
			if ((i + 1) == tempLine.size() && tempLine[i] != activeUserDriver.firstName + " " + activeUserDriver.lastName)
			{
				tempLine.push_back("");
				tempLine.push_back(activeUserDriver.firstName + " " + activeUserDriver.lastName);
				tempLine.push_back(to_string(target_->tripNumber));

				break;
			}

		}

	}

	file.open(fileName, ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < tempLine.size(); i++)
		{
			file << tempLine[i] << endl;
		}
	}

	file.close();

}

void getTripRecords(bool writeToFile, s_Booking* target_, bool readOnly_)
{
	string fileName = "tripRecords.txt";
	vector<string> tempLine;

	// import all lines
	// open file save lines to temp vector
	fstream file;
	file.open(fileName, ios::in);
	if (file.is_open()) // check if file successfully opened
	{
		string line; // create a storage for each line's value read from the file
		if (file.peek() != ifstream::traits_type::eof())
		{
			while (getline(file, line))
			{
				if (line == activeUserDriver.firstName + " " + activeUserDriver.lastName)
				{
					string line2;

					while (getline(file, line2))
					{
						tempLine.push_back(line2);

						if (line2.empty() || file.peek() == EOF)
						{
							break;
						}
					}
					break;

				}
				else
				{
					continue;
				}

			}
		}
	}
	else // if file fail to open
	{
		cout << "ERROR! Unable to open file " << fileName << endl;
	}

	if (readOnly_)
	{
		cout << "---------------------" << endl;
		cout << "      TRIP ID's      " << endl;
		cout << "---------------------" << endl;
		for (int i = 0; i < tempLine.size(); i++)
		{
			cout << i + 1 << ". " << tempLine[i] << endl;
		}
		cout << "---------------------" << endl;
	}

	file.close();

	if (writeToFile) setTripRecord(&tempLine, target_);

}

void clearConsole()
{
	system("cls");
}