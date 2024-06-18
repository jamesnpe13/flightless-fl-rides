// struct declaration here
#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
using namespace std;

struct Passenger
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
};

//typedef struct Driver
//{
//	// personal details
//	string firstName;
//	string lastName;
//	int gender; // 0 = male, 1 = female
//	string mobileNumber;
//	string email;
//	date_t DOB;
//	string ethnicity;
//	string bankAccountNumber;
//
//	// account details
//	string username;
//	string password;
//
//	// Licence details
//	int licenceType; // 0 = learner, 1 = restricted, 2 = full
//	int drivingYears;
//	string licenceNumber;
//	date_t licenceExpiry;
//	int endorsementNumber;
//	date_t endorsementExpiry;
//
//	// vehicle details
//	string registrationNumber;
//	date_t registrationExpiry;
//
//
//	// default constructor
//	Driver()
//	{
//		firstName = "";
//		lastName = "";
//		mobileNumber = "";
//		email = "";
//		ethnicity = "";
//		bankAccountNumber = "";
//		username = "";
//		password = "";
//		licenceNumber = "";
//		registrationNumber = "";
//		DOB = "";
//		licenceExpiry = "";
//		endorsementExpiry = "";
//		registrationExpiry = "";
//
//		gender = 0;
//
//
//	}
//} s_Driver;

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
};

#endif