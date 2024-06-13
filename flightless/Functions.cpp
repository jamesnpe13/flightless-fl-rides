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

unsigned long getMonth()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return ltm->tm_mon + 1;
}

unsigned long getYear()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return ltm->tm_year + 1900;
}