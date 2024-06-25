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
extern passengerV_t passengerVector;
extern adminV_t adminVector;
extern driverV_t driverVector;

extern s_Passenger activeUserPassenger;
extern s_Driver activeUserDriver;
extern s_Admin activeUserAdmin;

extern UserType activeUserType;

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
void showDriverMembers(const s_Driver& target_);
void showAll(const adminV_t* targetVector_);
void showAll(const passengerV_t* targetVector_);
void showAll(const driverV_t* targetVector_);
//void showAll(const driverV_t* targetVector_);
//void showAll(const bookingV_t* targetVector_);

// input validatidation functions
void inputValidation(int* target_);
bool isNumber(const string& s);
void getLine(string* target_);

// file htatandling functions
void loadFiles();
void writeToFile(s_Passenger* tempUser_);
void writeToFile(s_Admin* tempUser_);
void writeToFile(s_Driver* tempUser);
void setActiveUser(const s_Passenger* target_);
void setActiveUser(const s_Driver* target_);
void setActiveUser(const s_Admin* target_);
void loadUserData();
void loadPassengerFile(passengerV_t* passengerVector_);
void loadAdminFile(adminV_t* adminVector);
void loadDriverFile(driverV_t* driverVector_);

// user registration functions
void registerNewPassenger();
void registerNewAdmin();
void registerNewDriver();

// user sign in functions
void signInForm(int userType);

// booking functions
//void registerNewBooking();

// menu functions
int userSelectionInput(int* target_);
void displayTC();
void welcomeScreen();
void signInRegMenu();
void userTypeMenu(bool isRegister_ = 0);
//void dashboard();		

#endif
