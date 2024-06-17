// function and variable declarations here
#ifndef HEADER_H
#define HEADER_H
#include "Structs.h"
#include <vector>

unsigned int getDay();
unsigned int getYear();
bool dateIsValid(int targetMonth_, int targetYear_);
void showPassengerMembers(const Passenger& target_);
void showAdminMembers(const Admin& target_);
void inputValidation(int* target_);
bool isNumber(const std::string& s);

enum UserType
{
	admin,
	driver,
	passenger
};

void writeToFile(Passenger * tempUser_);
//void writeToFile(vector<Admin>* tempUser_);

void registerNewPassenger();
void registerNewAdmin();
//void registerNewDriver();

//void registerNewBooking();

#endif
