// function and variable declarations here
#ifndef HEADER_H
#define HEADER_H
#include "Structs.h"

unsigned int getDay();
unsigned int getYear();
bool dateIsValid(int targetMonth_, int targetYear_);
void showPassengeMembers(const Passenger& target_);
void inputValidation(int* target_);
bool isNumber(const std::string& s);

void registerNewPassenger();
void registerNewAdmin();
//void registerNewDriver();

//void registerNewBooking();

// test fstream file handling
void fstreamTest();

#endif
