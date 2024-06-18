// struct declaration here
#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
using namespace std;

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

struct Admin
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

#endif