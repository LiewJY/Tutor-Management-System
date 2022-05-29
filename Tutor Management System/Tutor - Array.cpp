#include <iostream>

#include <string>
#include <iomanip>
#include "Validation.h"

using namespace std;
string TutorArray[100][13] = { { "1", "John", "20/1/2018", "30/6/2019", "15.00", "john@gmail.com", "0123456789", "6, Jalan Cheras, Taman Cheras, 56100 Chearas, Kuala Lumpur.", "CRS1001", "eXcel Tuition Center (Cheras)", "PHY1234", "Physics", "4.5"},
	{"2", "May", "6/3/2018", "NA", "18.00", "may@gmail.com", "0184628592", "6, Jalan Cheras, Taman Cheras, 57000 Chearas, Kuala Lumpur.", "CRS1001", "eXcel Tuition Center (Cheras)", "AM2280", "Additional Mathematics", "4.8"},
	{"3", "Brian", "3/8/2019", "NA", "17.00", "brian@gmail.com", "0118427585", "23-A, Jalan Jalil, 57000 Bukit Jalil, Kuala Lumpur.", "BKJ1001", "eXcel Tuition Center (Bukit Jalil)", "MAT3125", "Mathematics", "4.6"}

};

void displayTutor() {

	//calculate size
	int arraySize = sizeof(TutorArray) / sizeof(TutorArray[0]);

	cout << string(40, '-') << " TUTOR RECORD LIST " << string(40, '-') << endl << endl;

	int row = 0;
	while (row < arraySize && TutorArray[row][0] != "")
	{
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
			"Rating\t\t\t: " << fixed << setprecision(1) << stod(TutorArray[row][12]) << endl << endl;
		cout << endl;

		row++;
	}
}


void addTutor() {

	// variables to read from user input
	int userInput = 1;
	int tutorID = 4;
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
	double rating = 0;


	displayTutor();

	// ask user if they want to start adding tutor list
	cout << "Enter: 1- Start Adding Tutor, Others- Exit Add Tutor: ";
	cin >> userInput;
	cout << endl;

	if (userInput == 1)
	{
		while (userInput == 1)
		{
			// name
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Name: ";
				getline(cin, name);
			} while (cin.fail() || !nameValidation(name));

			// date joined
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Date Joined:-\nEnter Day: ";
				cin >> day;
				cout << "Enter Month: ";
				cin >> month;
				cout << "Enter Year: ";
				cin >> year;

				dateJoined = to_string(day) + '/' + to_string(month) + '/' + to_string(year);
			} while (cin.fail() || !dateValidation(day, month, year));

			// date terminated
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Is this tutor terminated? 1- Yes, Others- No: ";
			cin >> userInput;

			do
			{
				if (userInput == 1)
				{
					cout << "Enter Date Terminated:-\nEnter Day: ";
					cin >> day;
					cout << "Enter Month: ";
					cin >> month;
					cout << "Enter Year: ";
					cin >> year;

					dateTerminated = to_string(day) + '/' + to_string(month) + '/' + to_string(year);
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
				cout << "Enter Hourly Pay Rate: ";
				cin >> hourlyPayRate;
			} while (cin.fail());

			// email
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Email: ";
				cin >> email;
			} while (cin.fail() || !emailValidation(email));

			// phone number
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Phone Number: ";
				cin >> phoneNumber;
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
				cout << "Enter Tuition Center Code: ";
				cin >> tuitionCenterCode;
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
				cout << "Enter Subject Code: ";
				cin >> subjectCode;
			} while (cin.fail() || !subjectCodeValidation(subjectCode));

			// subject name
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Subject Name: ";
			getline(cin, subjectName);;

			// rating
			do
			{
				cin.clear(); // remove the input operation
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Rating: ";
				cin >> rating;
			} while (cin.fail() || rating < 0 || rating > 5);

			// add to array

			//calculate size
			int row = 0;
			int arraySize = sizeof(TutorArray) / sizeof(TutorArray[0]);
			while (row < arraySize && TutorArray[row][0] != "")
			{
				row++;
			}

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


			tutorID++;

			// ask user if they want to add additional tutor list
			cout << endl << "Do you want to add additional tutor record? 1- Yes, Others- No: ";
			cin >> userInput;
			cout << endl;
		}
	}

	displayTutor();
}

void editTutor();
void deleteTutor();




int main() {
	addTutor();

	return 0;
}