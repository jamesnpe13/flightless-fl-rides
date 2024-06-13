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

	// calculate age

	// check if card is still valid
	int cardIsValid()
	{
		time_t theTime = time(NULL);
		struct tm* aTime = localtime_s(&theTime);

		int day = aTime->tm_mday;
		int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
		int year = aTime->tm_year + 1900; // Year is # years since 1900

		return month;

	}



};

#endif