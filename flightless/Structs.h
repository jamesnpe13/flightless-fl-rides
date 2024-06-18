// struct declaration here
#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <cstdlib>

using namespace std;

typedef string date_t;
typedef struct Passenger
{
	// personal details
	string firstName;
	string lastName;
	int gender; // 0 = male, 1 = female
	string mobileNumber;
	string email;

	// account details
	string username;
	string password;

	// payment details
	int paymentMethod; // 0 = cash, 1 = card
	string cardNumber;
	int cardExpiryM;
	int cardExpiryY;

	// default constructor
	Passenger()
	{
		firstName = lastName = mobileNumber = email = username = password = cardNumber = "";
		gender = paymentMethod = cardExpiryM = cardExpiryY = 0;
	}
} s_Passenger;
typedef struct Admin
{
	// personal details
	string firstName;
	string lastName;
	string username;
	string password;

	// default constructor
	Admin()
	{
		firstName = lastName = username = password = "";
	}
} s_Admin;
typedef struct Driver
{
	// personal details
	string firstName;
	string lastName;
	int gender; // 0 = male, 1 = female
	string mobileNumber;
	string email;
	date_t DOB;
	string ethnicity;
	string bankAccountNumber;

	// account details
	string username;
	string password;

	// Licence details
	int licenceType; // 0 = learner, 1 = restricted, 2 = full
	int drivingYears;
	string licenceNumber;
	date_t licenceExpiry;
	string endorsementNumber;
	date_t endorsementExpiry;

	// vehicle details
	string registrationNumber;
	date_t registrationExpiry;

	bool isEligible()
	{
		// check eligibility
	}

	string generateEndorsementNumber()
	{
		srand(time(NULL));
		int numLength = 12;
		char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
		string tempNum;

		for (int i = 0; i < numLength; i++)
		{
			bool letOrNum = rand() % 2;
			int ranNum = rand() % 10;
			string s = to_string(ranNum);

			//tempChar = letOrNum ? (letters[rand() % 26]) : (rand() % 10);
			letOrNum ? (tempNum += s) : (tempNum += letters[rand() % 26]);
		}

		return tempNum;
	}

	string generateEndorsementExpiry()
	{

	}



	// default constructor
	Driver()
	{
		firstName = "";
		lastName = "";
		mobileNumber = "";
		email = "";
		ethnicity = "";
		bankAccountNumber = "";
		username = "";
		password = "";
		licenceNumber = "";
		registrationNumber = "";
		DOB = "";
		licenceExpiry = "";
		endorsementExpiry = "";
		registrationExpiry = "";

		gender = 0;
		licenceType = 0;
		drivingYears = 0;
		endorsementNumber = generateEndorsementNumber();
	}
} s_Driver;

#endif