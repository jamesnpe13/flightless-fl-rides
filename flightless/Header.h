// function and variable declarations here
#ifndef HEADER_H
#define HEADER_H
#include "Structs.h"
#include <vector>


typedef vector<Passenger> passengerV_t;
typedef vector<Admin> adminV_t;
//typedef vector<Driver> driverV_t;
//typedef vector<Booking> bookingV_t;

unsigned int getDay();
unsigned int getYear();
bool dateIsValid(int targetMonth_, int targetYear_);
void showPassengerMembers(const s_Passenger& target_);
void showAdminMembers(const s_Admin& target_);
void showAll(const adminV_t* targetVector_);
void showAll(const passengerV_t* targetVector_);
//void showAll(const driverV_t* targetVector_);
//void showAll(const bookingV_t* targetVector_);
void inputValidation(int* target_);
bool isNumber(const std::string& s);

enum UserType
{
	admin,
	driver,
	passenger
};

void writeToFile(s_Passenger* tempUser_);
//void writeToFile(vector<Admin>* tempUser_);

void registerNewPassenger();
void registerNewAdmin();
//void registerNewDriver();

//void registerNewBooking();

#endif
