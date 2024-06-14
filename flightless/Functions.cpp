// function definition here
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Header.h"
#include "Structs.h"
#include <stdio.h>
#include <ctime>
using namespace std;

unsigned int getDay()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return ltm->tm_mday;
}

unsigned int getYear()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return ltm->tm_year + 1900;
}

bool isValid(int targetMonth_, int targetYear_)
{
	// checks whether a given dd/yyyy date is still valid
	time_t timeA, timeB;

	struct tm tA, tB, * tptr;
	int timeDiffDays;

	time(&timeA);
	time(&timeB);

	tptr = localtime(&timeA);
	tA = *tptr;
	tptr = localtime(&timeB);
	tB = *tptr;

	//tB.tm_mday = 10; // day input
	tB.tm_mon = targetMonth_ - 1; // month input
	tB.tm_year = targetYear_ - 1900; // year input

	timeA = mktime(&tA);
	timeB = mktime(&tB);

	timeDiffDays = (timeB - timeA) / 60 / 60 / 24; 

	return timeDiffDays > 0 ? 1 : 0;
}