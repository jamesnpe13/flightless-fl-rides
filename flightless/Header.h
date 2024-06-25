// function and variable declarations here
#ifndef HEADER_H
#define HEADER_H
#include "Structs.h"
#include <vector>

// custom type definitions
typedef vector<Passenger> passengerV_t;
typedef vector<Admin> adminV_t;
typedef vector<Driver> driverV_t;
//typedef vector<Driver> driverV_t;
//typedef vector<Booking> bookingV_t;

// enum types
enum UserType
{
	admin,
	driver,
	passenger
};

// create data container vectors
static passengerV_t passengerVector;
static adminV_t adminVector;
static driverV_t driverVector;

static s_Passenger activeUserPassenger;
static s_Driver activeUserDriver;
static s_Admin activeUserAdmin;

//vector<Driver> driverVector;
//vector<Booking> bookingVector;

// date handling functions
unsigned int getDay();
unsigned int getMonth();
unsigned int getYear();
bool dateIsValid(int targetMonth_, int targetYear_, int targetDay_ = NULL);
//tm calcTimeDifference(int month, int day, int year, bool reverse = 0);
time_t dateToTimeT(int month, int day, int year);
time_t now();

// print struct members functions
void showPassengerMembers(const s_Passenger& target_);
void showAdminMembers(const s_Admin& target_);
void showAll(const adminV_t* targetVector_);
void showAll(const passengerV_t* targetVector_);
void showAll(const driverV_t* targetVector_);
//void showAll(const driverV_t* targetVector_);
//void showAll(const bookingV_t* targetVector_);

// input validatidation functions
void inputValidation(int* target_);
bool isNumber(const string& s);
void getLine(string* target_);

// file handling functions
void loadFiles();
void writeToFile(s_Passenger* tempUser_);
void writeToFile(s_Admin* tempUser_);
void writeToFile(s_Driver* tempUser);
void loadUserData();
void loadPassengerFile(passengerV_t* passengerVector_);
void loadAdminFile(adminV_t* adminVector);
void loadDriverFile(driverV_t* driverVector_);

// user registration functions
void registerNewPassenger();
void registerNewAdmin();
void registerNewDriver();

// user sign in functions
void signInPassenger();
void signInAdmin();
void signInDriver();

// booking functions
//void registerNewBooking();

#endif
