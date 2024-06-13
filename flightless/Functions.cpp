// function definition here
#include "Header.h"
#include "Structs.h"
#include <iostream>

using namespace std;

void mainMenu()
{
	int choice;

	cout << "\n\t===============================================================================" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t|=|        ||||||||  ||                    COST EFFECTIVE                   |=|" << endl;
	cout << "\t|=|        ||        ||                    &                                |=|" << endl;
	cout << "\t|=|        ||||||||  ||                    SEAMLESS RIDE                    |=|" << endl;
	cout << "\t|=|        ||        ||                                                     |=|" << endl;
	cout << "\t|=|        ||        ||||||||              KIWI EXPERIENCE                  |=|" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t===============================================================================" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t|=|                   -------------------------------                       |=|" << endl;
	cout << "\t|=|                   ! WELCOME TO FLIGHTLESS RIDES !                       |=|" << endl;
	cout << "\t|=|                   -------------------------------                       |=|" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t|=|                               1. Rider                                  |=|" << endl;
	cout << "\t|=|                               2. Driver                                 |=|" << endl;
	cout << "\t|=|                               3. Admin                                  |=|" << endl;
	cout << "\t|=|                               Q. Quit                                   |=|" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t|=|                                                                         |=|" << endl;
	cout << "\t===============================================================================" << endl;

	cout << "\n\tPress a key to continue: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		
		break;
	case 2:
	
		break;
	case 3:
		
		break;
	case 4:
		cout << "Thank you for visiting FL RIDES!" << endl;
		break;
	}
}
