#define _CRT_SECURE_NO_WARNINGS 1

#include <chrono>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <regex>
#include "Validation.h"

using namespace std;
using namespace std::chrono;

// predefined tutor list
string TutorArray[100][13] = {
	{"1", "John", "20/1/2018", "30/6/2019", "62.00", "john@gmail.com", "0123456789", "6, Jalan Cheras, Taman Cheras, 56100 Chearas, Kuala Lumpur.", "CRS2232", "eXcel Tuition Center (Cheras)", "PHY1234", "Physics", "4"},
	{"2", "May", "6/3/2018", "NA", "75.00", "may@gmail.com", "0184628592", "15, Jalan Salak, Taman Tun Razak, 57000 Chearas, Kuala Lumpur.", "CRS2232", "eXcel Tuition Center (Cheras)", "AM2280", "Additional Mathematics", "5"},
	{"3", "Brian", "3/8/2019", "NA", "68.00", "brian@gmail.com", "0118427585", "23-A, Jalan Jalil, 57000 Bukit Jalil, Kuala Lumpur.", "BKJ1001", "eXcel Tuition Center (Bukit Jalil)", "MAT3125", "Mathematics", "4"},
	{"4", "Tom", "5/4/2020", "30/5/2021", "55.80", "tom@gmail.com", "0163423143", "16, Jalan Kajang, Bandar Kajang, 43000 Kajang, Selangor.", "BKJ1001", "eXcel Tuition Center (Bukit Jalil)", "CHE5622", "Chemistry", "3"},
	{"5", "Chan", "9/20/2017", "NA", "78.00", "chan@gmail.com", "0126454328", "21, Jalan Low Ti Kok, Bandar Kajang, 43000 Kajang, Selangor.", "KAJ2015", "eXcel Tuition Center (Kajang)", "ENG5932", "English", "5"},
	{"6", "Lee", "3/1/2019", "18/3/2022", "63.50", "lee@gmail.com", "0173354598", "2-26, Jalan Bukit Mewah 1, Taman Bukit Mewah, 43000 Kajang, Selangor.", "KAJ2015", "eXcel Tuition Center (Kajang)", "SEJ8866", "Sejarah", "4"}
};

// get data row
int getRow()
{
	// calculate size
	int arraySize = sizeof(TutorArray) / sizeof(TutorArray[0]);
	int row = 0;

	while (row < arraySize && TutorArray[row][0] != "")
	{
		row++;
	}
	return row;
}


// DISPLAY
// display individual record
void displayDetails(int row) {
	cout << string(40, '-') << " [" << "Position: " << row + 1 << "] " << string(40, '-') << endl;
	cout << "Tutor ID\t\t: " << stoi(TutorArray[row][0]) << "\n" <<
		"Name\t\t\t: " << TutorArray[row][1] << "\n" <<
		"Date Joined\t\t: " << TutorArray[row][2] << "\n"
		"Date Terminated\t\t: " << TutorArray[row][3] << "\n" <<
		"Hourly Pay Rate\t\t: RM " << fixed << setprecision(2) << stod(TutorArray[row][4]) << "\n" <<
		"Email\t\t\t: " << TutorArray[row][5] << "\n" <<
		"Phone Number\t\t: " << TutorArray[row][6] << "\n" <<
		"Address\t\t\t: " << TutorArray[row][7] << "\n" <<
		"Tuition Center Code\t: " << TutorArray[row][8] << "\n" <<
		"Tution Center Name\t: " << TutorArray[row][9] << "\n" <<
		"Subject Code\t\t: " << TutorArray[row][10] << "\n" <<
		"Subject Name\t\t: " << TutorArray[row][11] << "\n" <<
		"Rating\t\t\t: " << stoi(TutorArray[row][12]) << endl << endl;
	cout << endl;
}

// display tutor for main function
void displayTutor()
{
	int row = 0;

	cout << string(40, '-') << " TUTOR RECORD LIST " << string(40, '-') << endl << endl;

	while (row < getRow())
	{

		displayDetails(row);

		row++;
	}
}


// ADD
// add tutor for main function
void addTutor()
{
	// variables to read from user input
	int userInput = 1;
	int tutorID;
	string name;
	int day = 1;
	int month = 1;
	int year = 2000;
	string dateJoined;
	string dateTerminated;
	double hourlyPayRate = 0.0;
	string email;
	string phoneNumber;
	string address;
	string tuitionCenterCode;
	string tuitionCenterName;
	string subjectCode;
	string subjectName;
	int rating = 0;

	while (userInput == 1)
	{
		// name
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Name: ";
			getline(cin, name);

			if (cin.fail() || !nameValidation(name))
			{
				cout << "Invalid name! Please enter a valid name!" << endl;
			}
		} while (cin.fail() || !nameValidation(name));

		// date joined
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Date Joined:-\nEnter Day (22): ";
			cin >> day;
			cout << "Enter Month (2): ";
			cin >> month;
			cout << "Enter Year (2022): ";
			cin >> year;
			cout << endl;

			dateJoined = to_string(day) + '/' + to_string(month) + '/' + to_string(year);

			if (cin.fail() || !dateValidation(day, month, year))
			{
				cout << endl << "Invalid date! Please enter a valid date!" << endl;
			}
		} while (cin.fail() || !dateValidation(day, month, year));

		// date terminated
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Is this tutor terminated?" << endl;
			cout << "(1) Yes // (0) No" << endl << endl;
			cout << "Please enter an option: ";
			cin >> userInput;
			cout << endl;

			if (cin.fail() || (userInput != 1 && userInput != 0))
			{
				cout << "Invalid option! Please enter a valid option!" << endl << endl;
			}
		} while (cin.fail() || (userInput != 1 && userInput != 0));

		do
		{
			if (userInput == 1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Date Terminated:-\nEnter Day (22): ";
				cin >> day;
				cout << "Enter Month (2): ";
				cin >> month;
				cout << "Enter Year (2022): ";
				cin >> year;
				cout << endl;

				dateTerminated = to_string(day) + '/' + to_string(month) + '/' + to_string(year);

				if (cin.fail() || !dateValidation(day, month, year))
				{
					cout << endl << "Invalid date! Please enter a valid date!" << endl;
				}
			}
			else
			{
				dateTerminated = "NA";
			}
		} while (cin.fail() || !dateValidation(day, month, year));

		// hourly pay rate
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Hourly Pay Rate (RM 40 - RM 80): RM ";
			cin >> hourlyPayRate;
			cout << endl;

			if (cin.fail() || hourlyPayRate < 40.00 || hourlyPayRate > 80.00)
			{
				cout << "Invalid hourly pay rate! Please enter a valid hourly pay rate between RM 40 to RM 80!" << endl;
			}
		} while (cin.fail() || hourlyPayRate < 40.00 || hourlyPayRate > 80.00);

		// email
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Email: ";
			cin >> email;
			cout << endl;

			if (cin.fail() || !emailValidation(email))
			{
				cout << "Invalid email! Please enter a valid email!" << endl;
			}
		} while (cin.fail() || !emailValidation(email));

		// phone number
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Phone Number: ";
			cin >> phoneNumber;
			cout << endl;

			if (cin.fail() || !phoneNumberValidation(phoneNumber) || phoneNumber.length() < 10 || phoneNumber.length() > 11)
			{
				cout << "Invalid phone number! Please enter a valid phone number in 10 or 11 numbers!" << endl;
			}
		} while (cin.fail() || !phoneNumberValidation(phoneNumber) || phoneNumber.length() < 10 || phoneNumber.length() > 11);

		// address
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Address: ";
		getline(cin, address);

		// tuition center code
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Tuition Center Code (XXXX1234): ";
			cin >> tuitionCenterCode;
			cout << endl;

			if (cin.fail() || !tuitionCenterCodeValidation(tuitionCenterCode))
			{
				cout << "Invalid tuition center code! Please enter a valid tuition center code!" << endl;
			}
		} while (cin.fail() || !tuitionCenterCodeValidation(tuitionCenterCode));

		// tuition center name
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Tuition Center Name: ";
		getline(cin, tuitionCenterName);

		// subject code
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Subject Code (XXXX1234): ";
			cin >> subjectCode;
			cout << endl;

			if (cin.fail() || !subjectCodeValidation(subjectCode))
			{
				cout << "Invalid subject code! Please enter a valid subject code!" << endl;
			}
		} while (cin.fail() || !subjectCodeValidation(subjectCode));

		// subject name
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Subject Name: ";
		getline(cin, subjectName);

		// rating
		do
		{
			cin.clear(); // remove the input operation
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Rating (1 - 5): ";
			cin >> rating;
			cout << endl;

			if (cin.fail() || rating < 1 || rating > 5)
			{
				cout << "Invalid rating! Please enter a valid rating between 1 to 5!" << endl;
			}
		} while (cin.fail() || rating < 1 || rating > 5);

		//get row size
		int row = getRow();
		tutorID = stoi(TutorArray[row - 1][0]) + 1;

		TutorArray[row][0] = to_string(tutorID);
		TutorArray[row][1] = name;
		TutorArray[row][2] = dateJoined;
		TutorArray[row][3] = dateTerminated;
		TutorArray[row][4] = to_string(hourlyPayRate);
		TutorArray[row][5] = email;
		TutorArray[row][6] = phoneNumber;
		TutorArray[row][7] = address;
		TutorArray[row][8] = tuitionCenterCode;
		TutorArray[row][9] = tuitionCenterName;
		TutorArray[row][10] = subjectCode;
		TutorArray[row][11] = subjectName;
		TutorArray[row][12] = to_string(rating);

		// ask user if they want to add additional tutor list
		cout << endl << "Do you want to add additional tutor record? 1- Yes, Others- No: ";
		cin >> userInput;
		cout << endl;
	}

	displayTutor();
}


// UPDATE
// update tutor for main function
void updateTutor()
{
	int position = 0;
	int searchTutorID = 0;
	int userInput = 0;
	int day = 1;
	int month = 1;
	int year = 2000;
	string newDateTerminated, newPhoneNumber, newAddress;
	int row = getRow();
	bool found = false;

	displayTutor();

	// ask user to enter tutor ID
	cout << "Please enter Tutor ID to update: ";
	cin >> searchTutorID;
	cout << endl << endl;

	// go through the array (for id)
	while (position < row) {
		if (stoi(TutorArray[position][0]) == searchTutorID) {

			displayDetails(position); // display tutor list of this id
			found = true;

			do
			{
				// ask user which data field they would like to edit
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Which data you would like to update?" << endl;
				cout << "(1) Date Terminated // (2) Phone Number // (3) Address" << endl << endl;
				cout << "Please enter an option: ";
				cin >> userInput;
				cout << endl << endl;

				if (cin.fail() || (userInput != 1 && userInput != 2 && userInput != 3))
				{
					cout << "Invaliad option! Please enter a valid option!" << endl << endl;
				}
			} while (cin.fail() || (userInput != 1 && userInput != 2 && userInput != 3));

			switch (userInput)
			{
			case 1:
				do
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter New Date Terminated:-\nEnter Day (22): ";
					cin >> day;
					cout << "Enter Month (2): ";
					cin >> month;
					cout << "Enter Year (2022): ";
					cin >> year;
					cout << endl;

					newDateTerminated = to_string(day) + '/' + to_string(month) + '/' + to_string(year);

					TutorArray[position][3] = newDateTerminated;

					if (cin.fail() || !dateValidation(day, month, year))
					{
						cout << endl << "Invalid date! Please enter a valid date!" << endl;
					}
				} while (cin.fail() || !dateValidation(day, month, year));

				cout << "\"" << TutorArray[position][1] << "\" date terminated updated successfully!" << endl << endl << endl;

				break;
			case 2:
				do
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter New Phone Number: ";
					cin >> newPhoneNumber;
					cout << endl;

					TutorArray[position][6] = newPhoneNumber;

					if (cin.fail() || !phoneNumberValidation(newPhoneNumber) || newPhoneNumber.length() < 10 || newPhoneNumber.length() > 11)
					{
						cout << "Invalid phone number! Please enter a valid phone number in 10 or 11 numbers!" << endl;
					}
				} while (cin.fail() || !phoneNumberValidation(newPhoneNumber) || newPhoneNumber.length() < 10 || newPhoneNumber.length() > 11);

				cout << "\"" << TutorArray[position][6] << "\" phone number updated successfully!" << endl << endl << endl;

				break;
			case 3:
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter New Address: ";
				getline(cin, newAddress);
				cout << endl;

				TutorArray[position][7] = newAddress;

				cout << "\"" << TutorArray[position][7] << "\" address updated successfully!" << endl << endl << endl;

				break;
			}

			displayTutor();
		}
		
		position++; // update position
	}

	// if the program cannot find the tutor id entered by user
	if (found == false)
	{
		cout << "Unable to find Tutor ID! Please try again!" << endl << endl << endl;
	}
}


// DELETE
// delete tutor for main function
void deleteTutor() {
	string tempName;
	int userInput = 1;

	while (userInput == 1)
	{
		displayTutor();

		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter the position of tutor record that you want to delete: ";
			cin >> userInput;
			cout << endl;

			if (cin.fail() || userInput < 1 || userInput > getRow())
			{
				cout << "Invalid position! Please enter a valid position!" << endl << endl;
			}
		} while (cin.fail() || userInput < 1 || userInput > getRow());

		// DELETE CODE
		for (int i = 0; i < getRow(); i++)
		{
			//delete record form selected position
			if (i == userInput - 1)
			{
				tempName = TutorArray[i][1];
				//shift foward
				for (int move = i; move < (getRow() - 1); move++)
				{
					for (int col = 0; col < 12; col++)
					{
						TutorArray[move][col] = TutorArray[move + 1][col];
					}
				}
				//exit for loop
				break;

			}
		}
		// clear last row
		int lastRow = getRow() - 1;
		for (int clearRow = 0; clearRow < 12; clearRow++)
		{
			TutorArray[lastRow][clearRow] = "";
		}

		cout <<  "\"" << tempName << "\" record is deleted successfully!" << endl << endl << endl;


		displayTutor();

		do
		{
			// ask user if they want to delete additional tutor list
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Do you want to delete additional tutor record?" << endl;
			cout << "(1) Yes // (0) No" << endl << endl;
			cout << "Please enter an option: ";
			cin >> userInput;
			cout << endl << endl;

			if (cin.fail() || (userInput != 1 && userInput != 0))
			{
				cout << "Invalid option! Please enter a valid option!" << endl << endl;
			}
		} while (cin.fail() || (userInput != 1 && userInput != 0));
	}
}


// SORT
// quick sort code
int partition(string TutorArray[][13], int start, int end, int sortField)
{
	if (sortField == 1) 
	{
		// tutor Id
		int pivot = stoi(TutorArray[start][0]);

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (stoi(TutorArray[i][0]) <= pivot)
				count++;
		}

		// giving pivot element correct position
		int pivotIndex = start + count;
		swap(TutorArray[pivotIndex], TutorArray[start]);

		// sorting left and right pivot elements
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (stoi(TutorArray[i][0]) <= pivot) {
				i++;
			}

			while (stoi(TutorArray[j][0]) > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(TutorArray[i++], TutorArray[j--]);
			}
		}

		return pivotIndex;
	}
	else if (sortField == 2)
	{
		// hourly pay rate
		double pivot = stod(TutorArray[start][4]);

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (stod(TutorArray[i][4]) <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		int pivotIndex = start + count;
		swap(TutorArray[pivotIndex], TutorArray[start]);

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (stod(TutorArray[i][4]) <= pivot) {
				i++;
			}

			while (stod(TutorArray[j][4]) > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(TutorArray[i++], TutorArray[j--]);
			}
		}

		return pivotIndex;
	}
	else if (sortField == 3)
	{
		// rating
		double pivot = stod(TutorArray[start][12]);

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (stod(TutorArray[i][12]) <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		int pivotIndex = start + count;
		swap(TutorArray[pivotIndex], TutorArray[start]);

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (stod(TutorArray[i][12]) <= pivot) {
				i++;
			}

			while (stod(TutorArray[j][12]) > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(TutorArray[i++], TutorArray[j--]);
			}
		}

		return pivotIndex;
	}
}

void quickSort(string  TutorArray[][13], int start, int end, int sortField)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(TutorArray, start, end, sortField);

	// Sorting the left part
	quickSort(TutorArray, start, p - 1,  sortField);

	// Sorting the right part
	quickSort(TutorArray, p + 1, end, sortField);
}
// quick sort code end here


// SEARCH
// linear search code
bool linearSearch()
{
	// store position 
	int position = 0;
	// if search term exist
	bool found = false;

	int searchType = 0;
	int searchId = 0;
	double searchRating = 0;
	int row = getRow();

	do
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please select search type." << endl;
		cout << "(1) Tutor ID // (2) Rating" << endl << endl;
		cout << "Please enter an option: ";
		cin >> searchType;
		cout << endl;

		if (cin.fail() || (searchType != 1 && searchType != 2))
		{
			cout << "Invalid option! Please enter a valid option!" << endl << endl;
		}
	} while (cin.fail() || (searchType != 1 && searchType != 2));

	if (searchType == 1)
	{
		cout << "Please enter Tutor ID: ";
		cin >> searchId;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// go through the array (for id)
		while (position < row) {
			if (stoi(TutorArray[position][0]) == searchId) {

				// printing the details
				displayDetails(position);
				// item found
				found = true;
			}
			// Update position
			position++;
		}
	}
	else if (searchType == 2)
	{
		cout << "Please enter rating: ";
		cin >> searchRating;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// go through the whole array (for rating)
		while (position < row) {

			// print print out the index
			if (stod(TutorArray[position][12]) == searchRating) {

				// printing the details
				displayDetails(position);
				// item found
				found = true;
			}
			// Update position
			position++;
		}
	}
	else
	{
		cout << "Invalid input ";
	}

	// return T = found element, F = element not found
	return found;
}
// linear search code end here


// LOGIN
int login() {
	// variables to authenticate and determine user type
	int userType;
	int userInput = 1;
	int status = 0;
	string username, password;

	while (userInput == 1) 
	{
		// ask user to select user type and enter username and password
		cout << "Please select a user type to login." << endl;
		cout << "(1) HR // (Others) Admin" << endl << endl;
		cout << "Please enter an option: ";
		cin >> userType;
		cout << endl;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Username: ";
		cin >> username;
		cout << "Enter Password: ";
		cin >> password;
		cout << endl;

		// check user type and validate username and password
		if (userType == 1)
		{
			if (username == "hr" && password == "123") {
				cout << "Logged in successfully! Welcome HR!" << endl << endl << endl;
				// set the status to success (HR menu) & stop this loop
				status = 101;
				userInput = 2;
			}
		}
		else
		{
			if (username == "admin" && password == "123") {
				cout << "Logged in successfully! Welcome Admin!" << endl << endl << endl;
				// set the status to success (Admin menu) & stop this loop
				status = 102;
				userInput = 2;
			}
		}

		// incorrect credentials ask user do they want to retry
		if (status == 0)
		{
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Incorrect username and password!" << endl;
				cout << "(1) Login Again // (0) Exit Tutor Management System" << endl << endl;
				cout << "Please enter an option: ";
				cin >> userInput;
				cout << endl << endl;

				if (cin.fail() || (userInput != 1 && userInput != 0))
				{
					cout << "Invalid option! Please enter a valid option!" << endl << endl;
				}
			} while (cin.fail() || (userInput != 1 && userInput != 0));
		}
	}

	//return this value to determine what menu to show the user in main()
	return status;
}




// MAIN FUNCTION
int main()
{
	int userInput = 0;
	int option = 0;
	int sortField = 0;
	int status = login();

	// timmer
	auto sttar = high_resolution_clock::now();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - sttar);

	// HR menu
	if (status == 101)
	{
		userInput = 1;

		while (userInput == 1)
		{
			do
			{
				cout << string(30, '-') << " Welcome to Tutor Management System, HR! " << string(30, '-') << endl;
				cout << "(1) Add Tutor Record" << endl;
				cout << "(2) Display Tutor Record" << endl;
				cout << "(3) Search Tutor Record" << endl;
				cout << "(4) Sort Tutor Record" << endl;
				cout << "(5) Update Tutor Record" << endl;
				cout << "(6) Delete Tutor Record" << endl;
				cout << "(0) Exit Tutor Management System" << endl << endl;
				cout << "Please enter an option: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> option;

				if (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 0))
				{
					cout << endl << endl << "Invalid option! Please enter a valid option!" << endl << endl << endl;
				}
			} while (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 0));

			switch (option)
			{
			case 1:
				cout << endl << endl;
				addTutor();
				continue;
			case 2:
				cout << endl << endl;
				displayTutor();
				continue;
			case 3:
				cout << endl << endl;
				sttar = high_resolution_clock::now();

				if (linearSearch() == false)
				{
					cout << "Unable to find tutor record!" << endl << endl << endl;
				}
				stop = high_resolution_clock::now();

				//display time
				auto duration = duration_cast<microseconds>(stop - sttar);
				cout << string(40, '-');
				cout << " TIME TAKEN: " << fixed << setprecision(20) << duration.count();
				cout << " microseconds " << string(40, '-') << endl << endl;

				continue;
			case 4:
				cout << endl << endl;
				do {
					// ask user to select field to sort with 
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please select a field to sort tutor record." << endl;
					cout << "(1) Tutor ID // (2) Hourly Pay Rate // (3) Rating" << endl << endl;
					cout << "Please enter an option: ";
					cin >> sortField;
					cout << endl << endl;

					if (cin.fail() || (sortField != 1 && sortField != 2 && sortField != 3))
					{
						cout << "Invalid option! Please enter a valid option!" << endl << endl;
					}
					else
					{
						sttar = high_resolution_clock::now();
						quickSort(TutorArray, 0, getRow() - 1, sortField);
						stop = high_resolution_clock::now();

						displayTutor();

						//display time
						auto duration = duration_cast<microseconds>(stop - sttar);
						cout << string(40, '-');
						cout << " TIME TAKEN: " << fixed << setprecision(20) << duration.count();
						cout << " microseconds " << string(40, '-') << endl << endl;

						quickSort(TutorArray, 0, getRow() - 1, 1);
					}
				} while (cin.fail() || (sortField != 1 && sortField != 2 && sortField != 3));
				continue;
			case 5:
				cout << endl << endl;
				updateTutor();
				continue;
			case 6:
				cout << endl << endl;
				deleteTutor();
				continue;
			case 0:
				exit(0);
				break;
			default:
				cout << endl << endl << "Invalid option! Please enter a valid option!" << endl << endl << endl;
				continue;
			}
		}
	}
	// admin menu
	else if (status == 102)
	{
		userInput = 1;

		while (userInput == 1)
		{
			do
			{
				cout << string(30, '-') << " Welcome to Tutor Management System, Admin! " << string(30, '-') << endl;
				cout << "(1) Add Tutor Record" << endl;
				cout << "(2) Display Tutor Record" << endl;
				cout << "(3) Search Tutor Record" << endl;
				cout << "(4) Sort Tutor Record" << endl;
				cout << "(0) Exit Tutor Management System" << endl << endl;
				cout << "Please enter an option: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> option;

				if (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 && option != 0))
				{
					cout << endl << endl << "Invalid option! Please enter a valid option!" << endl << endl << endl;
				}
			} while (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 && option != 0));

			switch (option)
			{
			case 1:
				cout << endl << endl;
				addTutor();
				continue;
			case 2:
				cout << endl << endl;
				displayTutor();
				continue;
			case 3:
				cout << endl << endl;
				sttar = high_resolution_clock::now();

				if (linearSearch() == false)
				{
					cout << "Unable to find tutor record!" << endl << endl << endl;
				}
				stop = high_resolution_clock::now();

				//display time
				auto duration = duration_cast<microseconds>(stop - sttar);
				cout << string(40, '-');
				cout << " TIME TAKEN: " << fixed << setprecision(20) << duration.count();
				cout << " microseconds " << string(40, '-') << endl << endl;

				continue;
			case 4:
				cout << endl << endl;
				do {
					// ask user to select field to sort with MUST PUT HERE BECASUE THE FUNCTION ABOVE ALL ARE RECURSUE
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please select a field to sort tutor record." << endl;
					cout << "(1) Tutor ID // (2) Hourly Pay Rate // (3) Rating" << endl << endl;
					cout << "Please enter an option: ";
					cin >> sortField;
					cout << endl << endl;

					if (cin.fail() || (sortField != 1 && sortField != 2 && sortField != 3))
					{
						cout << "Invalid option! Please enter a valid option!" << endl << endl;
					}
					else
					{
						sttar = high_resolution_clock::now();
						quickSort(TutorArray, 0, getRow() - 1, sortField);
						stop = high_resolution_clock::now();

						displayTutor();

						//display time
						auto duration = duration_cast<microseconds>(stop - sttar);
						cout << string(40, '-');
						cout << " TIME TAKEN: " << fixed << setprecision(20) << duration.count();
						cout << " microseconds " << string(40, '-') << endl << endl;

						quickSort(TutorArray, 0, getRow() - 1, 1);
					}
				} while (cin.fail() || (sortField != 1 && sortField != 2 && sortField != 3));
				continue;
			case 0:
				exit(0);
				break;
			default:
				cout << endl << endl << "Invalid option! Please enter a valid option!" << endl << endl << endl;
				continue;
			}
		}
	}

	return 0;
}