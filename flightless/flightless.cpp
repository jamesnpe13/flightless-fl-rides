
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Header.h"
#include <stdio.h>
#include <ctime>
#include <fstream>
#include<windows.h>

using namespace std;

int main()
{
	loadFiles();
	displayTC();
	while (1)
	{
		int menuLoc = 3;

		switch (menuLoc)
		{
		case 1:
			displayTC();
			break;
		case 2:
			welcomeScreen();
			break;
		case 3:
			signInRegMenu();
			break;
		default:
			cout << "Please select from the menu options." << endl;
			break;
		}
	}

	return 0;
}

int userSelectionInput(int* target_)
{
	do
	{
		cin >> *target_;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (!cin);

	return *target_;
}
void displayTC()
{
	int selection;
	cout << "---------------------" << endl;
	cout << "  TERMS & CONDITIONS " << endl;
	cout << "---------------------" << endl;
	cout << "1. Introduction" << endl;
	cout << "Welcome to Flightless rides Taxi Booking App.By using our taxi booking system console application, you agree to these Terms and Conditions.If you do not agree, do not use the App." << endl;

	cout << "2. Eligibility" << endl;
	cout << "You must be at least 18 years old to use the App.By using it, you confirm that you meet this requirement." << endl;

	cout << "3. User Accounts" << endl;
	cout << "Create an account with accurate information. Keep your account details confidential. You are responsible for all activities under your account." << endl;

	cout << "4. Booking and Payment" << endl;
	cout << "Bookings are subject to availability. Payment must be made through the App. You agree to pay all applicable fees." << endl;

	cout << "5. Cancellation and Refunds" << endl;
	cout << "Cancel bookings according to the App's cancellation policy.	Refunds, if applicable, will follow the App's refund policy." << endl;

	cout << "6. Conduct	Use the App lawfully" << endl;
	cout << "Do not damage, disable, or impair the App.Do not attempt unauthorized access." << endl;

	cout << "7. Limitation of Liability" << endl;
	cout << "The App is provided 'as is' without warranties. We are not liable for any damages arising from your use of the App." << endl;

	cout << "8. Indemnification" << endl;
	cout << "You agree to indemnify Flightless Rides against any claims or expenses arising from your use of the App or violation of these Terms." << endl;

	cout << "9. Modifications" << endl;
	cout << "We may update these Terms at any time.Continued use of the App means you accept the new Terms." << endl;

	cout << "10. Governing Law" << endl;
	cout << "These Terms are governed by the laws of New Zealand.Disputes will be resolved in the courts of New Zealand." << endl;

	cout << "11. Contact Us" << endl;
	cout << "For questions, contact us at 111222333." << endl;
	cout << endl;
	cout << "------------------------------------" << endl;
	cout << "Do you agree? (1: yes, 0: no) " << endl;

	do
	{
		cin >> selection;
		while (!cin)
		{
			cout << "Please select 1: agree or 0: to exit the app." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> selection;
		}
		if (selection != 1 && selection != 0)
		{
			cout << "Please choose one of the options." << endl;
		}

	} while (selection != 1 && selection != 0);

	if (selection == 1)
	{
		welcomeScreen();
	}
	else if (selection == 0)
	{
		exit(1);
	}
}
void welcomeScreen()
{
	system("cls");
	cout << "\n\t===============================================================================" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t|=|          ||||||||  ||         |||||||        COST EFFECTIVE             |=|" << endl;
	cout << "\t|=|          ||        ||         ||    ||                                  |=|" << endl;
	cout << "\t|=|          ||||||||  ||         |||||||        SEAMLESS RIDE              |=|" << endl;
	cout << "\t|=|          ||        ||         ||  ||                                    |=|" << endl;
	cout << "\t|=|          ||        ||||||||   ||    ||       KIWI EXPERIENCE            |=|" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t===============================================================================" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t|=|                   -------------------------------                       |=|" << endl;
	cout << "\t|=|                   ! WELCOME TO FLIGHTLESS RIDES !                       |=|" << endl;
	cout << "\t|=|                   -------------------------------                       |=|" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t===============================================================================" << endl;
	Sleep(4000);
	signInRegMenu();
}
void signInRegMenu()
{
	while (1)
	{
		system("cls");
		cout << "---------------------" << endl;
		cout << " SIGN IN or REGISTER " << endl;
		cout << "---------------------" << endl;

		cout << "1. Sign in" << endl;
		cout << "2. Register new user" << endl;

		int menuLoc;

		userSelectionInput(&menuLoc);
		switch (menuLoc)
		{
		case 1:
			userTypeMenu();
			break;
		case 2:
			userTypeMenu(1);
			break;
		case 0:
			return;
			break;
		default:
			cout << "Please select from the menu options." << endl;
			break;
		}
	}
}
void userTypeMenu(bool isRegister_)
{
	while (1)
	{
		system("cls");
		if (isRegister_)
		{
			cout << "---------------------" << endl;
			cout << "     REGISTER AS     " << endl;
			cout << "---------------------" << endl;
		}
		else
		{
			cout << "---------------------" << endl;
			cout << "      SIGN IN AS     " << endl;
			cout << "---------------------" << endl;
		}

		cout << "1. Passenger" << endl;
		cout << "2. Driver" << endl;
		cout << "3. Admin" << endl;
		cout << "0. Return to menu" << endl;

		int menuLoc;

		userSelectionInput(&menuLoc);
		switch (menuLoc)
		{
		case 1:
			system("cls");
			isRegister_ ? registerNewPassenger() : signInForm(1);
			break;
		case 2:
			system("cls");
			isRegister_ ? registerNewDriver() : signInForm(2);
			break;
		case 3:
			system("cls");
			isRegister_ ? registerNewAdmin() : signInForm(3);
			break;
		case 0:
			return;
			break;
		default:
			cout << "Please select from the menu options." << endl;
			break;
		}
	}
}
void dashboard(const UserType* activeUserType_)
{

	int menuLoc;

	switch (*activeUserType_)
	{
	case passenger:
		while (1)
		{
			cout << "---------------------" << endl;
			cout << " PASSENGER DASHBOARD " << endl;
			cout << "---------------------" << endl;

			cout << "1. View my active bookings" << endl;
			cout << "2. Create a new booking" << endl;
			cout << "3. See booking history" << endl;
			cout << "0. Sign out" << endl;

			userSelectionInput(&menuLoc);

			switch (menuLoc)
			{
			case 1:// view active bookings		
				system("cls");
				listItems(&bookingVector, 1, 1);
				break;
			case 2: // create new booking
				system("cls");
				createNewBooking();
				break;
			case 3: // see booking history
				system("cls");
				listItems(&bookingVector, 0, 1);
				break;
			case 0:
				signInRegMenu();
				break;
			default:
				cout << "Please select from the menu options." << endl;
				break;
			}
		}
		break;
	case driver:
		while (1)
		{
			cout << "---------------------" << endl;
			cout << "   DRIVER DASHBOARD  " << endl;
			cout << "---------------------" << endl;

			cout << "1. View all available bookings" << endl;
			// list all bookings and choose to accept trip			
			cout << "2. Trip reports" << endl;
			// shows todays trips and search by date
			cout << "3. My payment details" << endl;
			// show payment details			
			cout << "0. Sign out" << endl;

			userSelectionInput(&menuLoc);

			switch (menuLoc)
			{
			case 1:
				system("cls");
				bookingAcceptance();
				break;
			case 2:
				system("cls");
				getTripRecords(0, NULL, 1);
				break;
			case 3:
				system("cls");
				cout << "Bank account number: " << activeUserDriver.bankAccountNumber << endl;
				break;
			case 0:
				system("cls");
				signInRegMenu();
				break;
			default:
				cout << "Please select from the menu options." << endl;
				break;
			}
		}
		break;
	case admin:
		while (1)
		{
			cout << "---------------------" << endl;
			cout << "   ADMIN DASHBOARD   " << endl;
			cout << "---------------------" << endl;

			cout << "1. Trip reports" << endl;
			cout << "2. Trip cancellation report" << endl;
			cout << "3. View all drivers" << endl;
			cout << "4. View all passengers" << endl;
			cout << "0. Sign out" << endl;

			userSelectionInput(&menuLoc);

			switch (menuLoc)
			{
			case 1:
				system("cls");
				cout << "---------------------" << endl;
				cout << "     TRIP REPORTS    " << endl;
				cout << "---------------------" << endl;
				for (int i = 0; i < bookingVector.size(); i++)
				{
					bookingVector[i].showSummary();
				}
				break;
			case 2:
				system("cls");
				cout << "** FEATURE UNAVAILABLE **" << endl;
				break;
			case 3:
				system("cls");
				cout << "---------------------" << endl;
				cout << "     ALL DRIVERS     " << endl;
				cout << "---------------------" << endl;
				for (int i = 0; i < driverVector.size(); i++)
				{
					driverVector[i].showSummary();
				}
				break;
			case 4:
				system("cls");
				cout << "---------------------" << endl;
				cout << "    ALL PASSENGERS   " << endl;
				cout << "---------------------" << endl;
				for (int i = 0; i < passengerVector.size(); i++)
				{
					passengerVector[i].showSummary();
				}
				break;
			case 0:
				signInRegMenu();
				break;
			default:
				cout << "Please select from the menu options." << endl;
				break;
			}
		}
		break;
	}

}
