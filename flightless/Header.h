// function and variable declarations here
#ifndef HEADER_H
#define HEADER_H
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// time functions
tm calcTimeDifference(int month, int day, int year, bool reverse = 0);
unsigned int getDay();
unsigned int getMonth();
unsigned int getYear();
typedef string date_t;

extern bool isSignedIn;

// structs
typedef struct Passenger
{
	// personal details
	string firstName;
	string lastName;
	int gender; // 0 = male, 1 = female
	string mobileNumber;
	string email;
	string address;

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
		firstName = lastName = mobileNumber = email = username = password = cardNumber = address = "";
		gender = paymentMethod = cardExpiryM = cardExpiryY = 0;
	}
} s_Passenger;
typedef struct Admin
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
typedef struct Driver
{
	// personal details
	string firstName;
	string lastName;
	int gender; // 0 = male, 1 = female
	string mobileNumber;
	string email;
	string address;
	date_t DOB;
	int age;
	string ethnicity;
	string bankAccountNumber;

	// account details
	string username;
	string password;
	string bankName;

	// Licence details
	int licenceType; // 0 = learner, 1 = restricted, 2 = full
	int drivingYears;
	string licenceNumber;
	date_t licenceExpiry;
	string endorsementNumber;
	date_t endorsementExpiry;

	// vehicle details
	string vehicleMakeModel;
	int vehicleModelYear;
	string registrationNumber;
	date_t registrationExpiry;
	date_t wofExpiry;

	bool isEligible()
	{
		// full licence?
		if (licenceType != 2) return 0;

		// >= 2 years driving years?
		if (drivingYears < 2) return 0;

		// taxi model <= 10 years?
		if ((getYear() - vehicleModelYear) > 10) return 0;

		// Age >= 20 years old?
		if (age < 20) return 0;

		return 1;
	}

	bool isDatePositive(date_t* target_)
	{
		int day = stoi((*target_).substr(0, 2));
		int month = stoi((*target_).substr(3, 2));
		int year = stoi((*target_).substr(6, 4));

		return (calcTimeDifference(month, day, year).tm_wday > 0);
	}

	string generateEndorsementNumber()
	{
		srand(time(NULL));
		int numLength = 12;
		char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
		string tempNum;

		for (int i = 0; i < numLength; i++)
		{
			bool letOrNum = rand() % 2;
			int ranNum = rand() % 10;
			string s = to_string(ranNum);

			//tempChar = letOrNum ? (letters[rand() % 26]) : (rand() % 10);
			letOrNum ? (tempNum += s) : (tempNum += letters[rand() % 26]);
		}

		return tempNum;
	}

	string generateEndorsementExpiry()
	{
		int day, month, year, period = 2;
		day = getDay();
		month = getMonth();
		year = getYear() + period;

		return to_string(day) + "-" + to_string(month) + "-" + to_string(year);

	}
	void getAge(int day, int month, int year)
	{
		age = calcTimeDifference(month, day, year, 1).tm_year - 70;
	}

	// default constructor
	Driver()
	{
		firstName = "";
		lastName = "";
		mobileNumber = "";
		email = "";
		address = "";
		ethnicity = "";
		bankAccountNumber = "";
		username = "";
		password = "";
		licenceNumber = "";
		registrationNumber = "";
		DOB = "";
		licenceExpiry = "";
		endorsementExpiry = "";
		registrationExpiry = "";
		bankName = "";
		vehicleMakeModel = "";
		wofExpiry = "";
		vehicleModelYear = 0;
		age = 0;
		gender = 0;
		licenceType = 0;
		drivingYears = 0;
		endorsementNumber = generateEndorsementNumber();
		endorsementExpiry = generateEndorsementExpiry();
	}
} s_Driver;
extern s_Passenger activeUserPassenger;
typedef struct Booking
{
	unsigned long long tripNumber;
	string customerName;
	string customerMobileNumber;
	string startAddress;
	string endAddress;
	string bookingDate;
	string bookingTime;
	int numberOfPersons;
	string notes;
	int luggageType;
	string cardNumber;
	string cardExpiry;
	bool isPaid;
	bool isAvailable;

	void generateTripNumber()
	{
		srand(time(NULL));
		int numLength = 12;
		string temp;
		unsigned long long tempInt;

		for (int i = 0; i < numLength; i++)
		{
			int randNum = rand() % 10;

			temp += to_string(randNum);
		}
		tempInt = stoll(temp);
		tripNumber = tempInt;
	}

	void attachUserData()
	{
		s_Passenger user = activeUserPassenger;
		customerName = user.firstName + " " + user.lastName;
		customerMobileNumber = user.mobileNumber;
		if (user.paymentMethod == 1)
		{
			cardNumber = user.cardNumber;
			cardExpiry = user.cardExpiryM + " " + user.cardExpiryY;
			isPaid = 1;
		}
		else if (user.paymentMethod == 0)
		{
			cardNumber = "N/A";
			cardExpiry = "N/A";
			isPaid = 0;
		}
	}

	void attachDateAndTime()
	{
		time_t now = time(0);
		struct tm nowTM;
		localtime_s(&nowTM, &now);
		string temp = to_string(nowTM.tm_hour) + ":" + to_string(nowTM.tm_min);

		bookingDate = to_string(getDay()) + "/" + to_string(getMonth()) + "/" + to_string(getYear());
		bookingTime = temp;
	}

	void showSummary()
	{
		cout << "Trip number: " << tripNumber << endl;
		cout << "Customer name: " << customerName << endl;
		cout << "Mobile number: " << customerMobileNumber << endl;
		cout << "Pickup address: " << startAddress << endl;
		cout << "Destination: " << endAddress << endl;
		cout << "Date: " << bookingDate << endl;
		cout << "Time: " << bookingTime << endl;
		cout << "Number of passengers: " << numberOfPersons << endl;
		cout << "Notes: " << notes << endl;
		cout << "Luggage weight: " << luggageType << endl;
		cout << "Card number: " << cardNumber << endl;
		cout << "Card expiry: " << cardExpiry << endl;
		cout << "Payment status: " << (isPaid ? "Paid" : "Pending payment") << endl;
		cout << "Booking availability: " << (isAvailable ? "Available" : "Unavailable") << endl;
	}

	Booking()
	{
		customerName = "";
		customerMobileNumber = "";
		startAddress = "";
		endAddress = "";
		bookingDate = "";
		bookingTime = "";
		notes = "";
		cardNumber = "";
		cardExpiry = "";
		tripNumber = 0;
		numberOfPersons = 0;
		luggageType = 0;
		isAvailable = 1;

		generateTripNumber();
		attachUserData();
		attachDateAndTime();
	}

} s_Booking;

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
//void showAll(const bookingV_t* targetVector_);

// input validatidation functions
void inputValidation(int* target_);
bool isNumber(const string& s);
void getLine(string* target_);

// file handling functions
void loadFiles();
void writeToFile(const s_Passenger* tempUser_);
void writeToFile(const s_Admin* tempUser_);
void writeToFile(const s_Driver* tempUser);
void setActiveUser(const s_Passenger* target_);
void setActiveUser(const s_Driver* target_);
void setActiveUser(const s_Admin* target_);
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
void dashboard(const UserType* activeUserType_);

#endif
