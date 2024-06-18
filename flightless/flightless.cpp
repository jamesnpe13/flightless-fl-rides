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

void loadUserData();
// function declaration
void loadPassengerFile(passengerV_t* passengerVector_);
//void loadDriverFile(vector<Driver>* driverVector);
void loadAdminFile(adminV_t* adminVector);
//void loadPassengerFile(vector<Booking>* bookingVector);

void menuA();

void menuB();


int main()
{
	// create data container vectors
	passengerV_t passengerVector;
	//vector<Driver> driverVector;
	adminV_t adminVector;
	//vector<Booking> bookingVector;

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

// load passenger file
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

// load admin file
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




