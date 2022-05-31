#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include "Validation.h"

using namespace std;

int sizeofLinkedList = 0; // initialize size of linked list to 0

// structure of tutor
struct Tutor
{
	int tutorID = 1;
	string name;
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
	Tutor* nextAddress = NULL; // next pointer
	Tutor* previousAddress = NULL; // previous pointer
} *head, * tail;


// ADD
// add new tutor list to the end of linked list
void addTutorProcess(Tutor* newNode)
{
	// head is empty, assign newNode value
	if (head == NULL)
	{
		head = tail = newNode;
	}
	// 1. assign newNode value to nextAddress of tail
	// 2. assign original tail value to previousAddress of newNode
	// 3. assign newNode value and replace original tail value
	else
	{
		tail->nextAddress = newNode;
		newNode->previousAddress = tail;
		tail = newNode;
	}

	::sizeofLinkedList++;
}

// create newNode
Tutor* createNewNode(int tutorID, string name, string dateJoined, string dateTerminated, double hourlyPayRate, string email, string phoneNumber,string address, string tuitionCenterCode, string tuitionCenterName, string subjectCode, string subjectName, int rating)
{
	Tutor* newNode = new Tutor;
	newNode->tutorID = tutorID;
	newNode->name = name;
	newNode->dateJoined = dateJoined;
	newNode->dateTerminated = dateTerminated;
	newNode->hourlyPayRate = hourlyPayRate;
	newNode->email = email;
	newNode->phoneNumber = phoneNumber;
	newNode->address = address;
	newNode->tuitionCenterCode = tuitionCenterCode;
	newNode->tuitionCenterName = tuitionCenterName;
	newNode->subjectCode = subjectCode;
	newNode->subjectName = subjectName;
	newNode->rating = rating;
	newNode->nextAddress = NULL;
	newNode->previousAddress = NULL;

	return newNode;
}


// DISPLAY
//display individual record
void displayDetails(int position, Tutor* current)
{
	cout << string(40, '-') << " [" << "Position: " << position << "] " << string(40, '-') << endl;
	cout << "Tutor ID\t\t: " << current->tutorID << "\n" <<
		"Name\t\t\t: " << current->name << "\n" <<
		"Date Joined\t\t: " << current->dateJoined << "\n"
		"Date Terminated\t\t: " << current->dateTerminated << "\n" <<
		"Hourly Pay Rate\t\t: RM " << fixed << setprecision(2) << current->hourlyPayRate << "\n" <<
		"Email\t\t\t: " << current->email << "\n" <<
		"Phone Number\t\t: " << current->phoneNumber << "\n" <<
		"Address\t\t\t: " << current->address << "\n" <<
		"Tuition Center Code\t: " << current->tuitionCenterCode << "\n" <<
		"Tution Center Name\t: " << current->tuitionCenterName << "\n" <<
		"Subject Code\t\t: " << current->subjectCode << "\n" <<
		"Subject Name\t\t: " << current->subjectName << "\n" <<
		"Rating\t\t\t: " << current->rating << endl << endl << endl;
}

// display tutor list for process function and main function
void displayTutor()
{
	//while (head->previousAddress != NULL)
	//	head = head->previousAddress;
	Tutor* current = head;

	cout << string(40, '-') << " TUTOR RECORD LIST " << string(40, '-') << endl << endl;

	while (current != NULL)
	{
		for (int position = 1; position <= ::sizeofLinkedList; position++)
		{
			displayDetails(position, current);
			current = current->nextAddress;
		}
	}
}



// predefined tutor list
void predefinedTutorList()
{
	// empty the list
	head = tail = NULL;

	Tutor* newNode = createNewNode(1, "John", "20/1/2018", "30/6/2019", 62, "john@gmail.com", "0123456789", "6, Jalan Cheras, Taman Cheras, 56100 Chearas, Kuala Lumpur.", "CRS1001", "eXcel Tuition Center (Cheras)", "PHY1234", "Physics", 3);
	addTutorProcess(newNode);

	newNode = createNewNode(2, "May", "6/3/2018", "NA", 75.00, "may@gmail.com", "0184628592", "15, Jalan Salak, Taman Tun Razak, 57000 Chearas, Kuala Lumpur.", "CRS1001", "eXcel Tuition Center (Cheras)", "AM2280", "Additional Mathematics", 2);
	addTutorProcess(newNode);

	newNode = createNewNode(3, "Brian", "3/8/2019", "NA", 68.00, "brian@gmail.com", "0118427585", "23-A, Jalan Jalil, 57000 Bukit Jalil, Kuala Lumpur.", "BKJ1001", "eXcel Tuition Center (Bukit Jalil)", "MAT3125", "Mathematics", 1);
	addTutorProcess(newNode);
}


// ADD
// add tutor for main function
void addTutor()
{
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

		Tutor* newNode = createNewNode(tutorID, name, dateJoined, dateTerminated, hourlyPayRate, email,
			phoneNumber, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, rating);

		addTutorProcess(newNode);

		tutorID++;

		displayTutor();

		do
		{
			// ask user if they want to add additional tutor list
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Do you want to add additional tutor record?" << endl;
			cout << "(1) Yes // (0) No" << endl << endl;
			cout << "Please enter an option: ";
			cin >> userInput;
			cout << endl << endl;

			if (cin.fail() || (userInput != 1 && userInput != 0))
			{
				cout << "Invdalid option! Please enter a valid option!" << endl << endl;
			}
		} while (cin.fail() || (userInput != 1 && userInput != 0));
	}
}


// UPDATE
// update tutor phone number
void updatePhoneNumber(string newPhoneNumber, int position)
{
	Tutor* current = head;
	int count = 1;

	while (current != NULL)
	{
		if (count == position)
		{
			current->phoneNumber = newPhoneNumber;
		}

		current = current->nextAddress;
		count++;
	}
}

// update tutor address
void updateAddress(string newAddress, int position)
{
	Tutor* current = head;
	int count = 1;

	while (current != NULL)
	{
		if (count == position)
		{
			current->address = newAddress;
		}

		current = current->nextAddress;
		count++;
	}
}

// update tutor for main function
void updateTutor(Tutor* head)
{
	Tutor* current = head;

	int position = 1;
	int searchTutorID = 0;
	int userInput = 0;
	string newPhoneNumber, newAddress;
	
	displayTutor();

	// ask user to enter tutor ID
	cout << "Please enter Tutor ID to update: ";
	cin >> searchTutorID;
	cout << endl << endl;

	// traverse the linked list to get tutor id
	while (current->tutorID != searchTutorID && current->nextAddress != NULL)
	{
		position++; // update position
		current = current->nextAddress; // update current data
	}

	// the tutor id entered by user matched with tutor id in linked list
	if (current->tutorID == searchTutorID)
	{
		displayTutor();

		do
		{
			// ask user which data field they would like to edit
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Which data you would like to update?" << endl;
			cout << "(1) Phone Number // (2) Address" << endl << endl;
			cout << "Please enter an option: ";
			cin >> userInput;
			cout << endl << endl;

			if (cin.fail() || (userInput != 1 && userInput != 2))
			{
				cout << "Invaliad option! Please enter a valid option!" << endl << endl;
			}
		} while (cin.fail() || (userInput != 1 && userInput != 2));

		switch (userInput)
		{
		case 1:
			do
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter New Phone Number: ";
				cin >> newPhoneNumber;
				cout << endl;

				if (cin.fail() || !phoneNumberValidation(newPhoneNumber) || newPhoneNumber.length() < 10 || newPhoneNumber.length() > 11)
				{
					cout << "Invalid phone number! Please enter a valid phone number in 10 or 11 numbers!" << endl;
				}
			} while (cin.fail() || !phoneNumberValidation(newPhoneNumber) || newPhoneNumber.length() < 10 || newPhoneNumber.length() > 11);

			updatePhoneNumber(newPhoneNumber, position);
			cout << "\"" << current->name << "\" phone number updated successfully!" << endl << endl << endl;

			break;
		case 2:
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter New Address: ";
			getline(cin, newAddress);
			cout << endl;

			updateAddress(newAddress, position);
			cout << "\"" << current->name << "\" address updated successfully!" << endl << endl << endl;

			break;
		}

		displayTutor();
	}

	// if the program cannot find the tutor id entered by user
	if (current->tutorID != searchTutorID)
	{
		cout << "Unable to find Tutor ID! Please try again!" << endl << endl << endl;
	}
}


// DELETE
// delete tutor list from specific location
void deleteTutorProcess(int position)
{
	// case 1: list is empty and no list to delete
	if (head == NULL)
	{
		cout << "There is no tutor record to delete!" << endl << endl << endl;
		return;
	}
	// case 2: first position
	else if (position == 1)
	{
		Tutor* current = head; // set current to first position
		head = head->nextAddress; // set head to next position

		// if head is not empty, set the previous address of head to empty
		if (head != NULL)
		{
			head->previousAddress = NULL;
		}
		// if head is empty, set the tail to empty as well
		else
		{
			tail = NULL;
		}

		cout << "\"" << current->name << "\" record is deleted successfully!" << endl << endl << endl;
		delete current;
		sizeofLinkedList--;
	}
	// case 3: last position
	else if (position == ::sizeofLinkedList)
	{
		Tutor* current = tail; // set current to last position
		tail = tail->previousAddress; // set tail to previous address

		// if tail is not empty, set the next address of tail to empty
		if (tail != NULL)
		{
			tail->nextAddress = NULL;
		}
		// if tail is empty, set the head to empty as well
		else
		{
			head = NULL;
		}

		cout << "\"" << current->name << "\" record is deleted successfully!" << endl << endl << endl;
		delete current;
		sizeofLinkedList--;
	}
	// case 4: middle position
	else
	{
		Tutor* current = head->nextAddress; // set current to next position
		int currentPosition = 2; // set position to 2 = in the middle position

		while (current != NULL)
		{
			if (currentPosition == position)
			{
				// set current previous address's next address to current next address
				current->previousAddress->nextAddress = current->nextAddress;
				// set current next address's previous address to current previous address
				current->nextAddress->previousAddress = current->previousAddress;

				cout << "\"" << current->name << "\" record is deleted successfully!" << endl << endl << endl;
				delete current;
				sizeofLinkedList--;
				return;
			}

			current = current->nextAddress;
			currentPosition++;
		}
	}
}

// delete tutor for main function
void deleteTutor()
{
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

			if (cin.fail() || userInput < 1 || userInput > ::sizeofLinkedList)
			{
				cout << "Invalid position! Please enter a valid position!" << endl << endl;
			}
		} while (cin.fail() || userInput < 1 || userInput > ::sizeofLinkedList);

		deleteTutorProcess(userInput);
		displayTutor();

		// if head is empty, display error message and stop delete process
		if (head == NULL)
		{
			break;
		}

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


// LOGIN
int login() {
	//variables to authenticate and determine user type
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


// SORT
// merge sort code for linked list
// split the double linked list into half
Tutor* split(Tutor* head)
{
	Tutor* fast = head, * slow = head;
	while (fast->nextAddress && fast->nextAddress->nextAddress)
	{
		fast = fast->nextAddress->nextAddress;
		slow = slow->nextAddress;
	}
	Tutor* temp = slow->nextAddress;
	slow->nextAddress = NULL;
	return temp;
}

// function to merge the splitted linked list
Tutor* merge(Tutor* first, Tutor* second, int sortField)
{
	// check if 1st linked list is empty if yes then return the 2nd
	if (!first) {
		return second;
	}
	// check if 2nd linked list is empty if yes then return the 1st
	if (!second) {
		return first;
	}

	if (sortField == 1)
	{
		//tutor Id
		// pick the smaller value and put to left hand side
		if (first->tutorID < second->tutorID)
		{
			first->nextAddress = merge(first->nextAddress, second, sortField);
			first->nextAddress->previousAddress = first;
			first->previousAddress = NULL;
			return first;
		}
		else
		{
			second->nextAddress = merge(first, second->nextAddress, sortField);
			second->nextAddress->previousAddress = second;
			second->previousAddress = NULL;
			return second;
		}
	}
	else if (sortField == 2)
	{
		//hourly pay rate
		// pick the smaller value and put to left hand side
		if (first->hourlyPayRate < second->hourlyPayRate)
		{
			first->nextAddress = merge(first->nextAddress, second, sortField);
			first->nextAddress->previousAddress = first;
			first->previousAddress = NULL;
			return first;
		}
		else
		{
			second->nextAddress = merge(first, second->nextAddress, sortField);
			second->nextAddress->previousAddress = second;
			second->previousAddress = NULL;
			return second;
		}
	}
	else if (sortField == 3)
	{
		//rating
		// pick the smaller value and put to left hand side
		if (first->rating < second->rating)
		{
			first->nextAddress = merge(first->nextAddress, second, sortField);
			first->nextAddress->previousAddress = first;
			first->previousAddress = NULL;
			return first;
		}
		else
		{
			second->nextAddress = merge(first, second->nextAddress, sortField);
			second->nextAddress->previousAddress = second;
			second->previousAddress = NULL;
			return second;
		}
	}
	
}

// merge sort function 
Tutor* mergeSort(Tutor* head, int sortField)
{
	if (!head || !head->nextAddress)
		return head;
	Tutor* second = split(head);
	//do merge sort recursively for left half and right half
	head = mergeSort(head, sortField);
	second = mergeSort(second, sortField);

	// merge the left and right sorted linked list
	return merge(head, second, sortField);
}
// merge sort code for linked list end here


// SEARCH
// linear serach code
bool linearSearch(Tutor* head)
{
	// Stores head Node
	Tutor* temp = head;

	// store position 
	int position = 0;

	// if search term exist
	bool found = false;

	int searchType = 0;
	int searchId = 0;
	double searchRating = 0;

	// ask user to select field to search from
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
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter Tutor ID: ";
		cin >> searchId;
		cout << endl;

		// go throgh the linked list (for id)
		while (temp->tutorID != searchId && temp->nextAddress != NULL) {
			// Update position
			position++;

			// Update temp data
			temp = temp->nextAddress;
		}
		// print print out the index
		if (temp->tutorID == searchId) {

			// print details
			displayDetails(position + 1, temp);

			//item found
			found = true;
		}
	}
	else if (searchType == 2)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter rating (1 - 5): ";
		cin >> searchRating;
		cout << endl;

		// go throgh the whole linked list (for rating)
		while (temp->nextAddress != NULL) {
			// print print out the index
			if (temp->rating == searchRating) {

				// print details
				displayDetails(position + 1, temp);
				//item found
				found = true;
			}

			// Update position
			position++;

			// Update temp data
			temp = temp->nextAddress;
		}

		// print print out the index
		if (temp->rating == searchRating) {

			// print details
			displayDetails(position + 1, temp);

			//item found
			found = true;
		}
	}

	// return T = found element, F = element not found
	return found;
}
// linear search code end here




// MAIN FUNCTION
int main()
{
	int userInput = 0;
	int option = 0;
	// todo menu for sort add the loop and error thing here the invalid input
	int sortField = 0;
	int status = login();

	// HR menu
	if (status == 101)
	{
		userInput = 1;

		// display predefined tutor list
		predefinedTutorList();

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
				if (linearSearch(head) == false)
				{
					cout << "Unable to find tutor record!" << endl << endl << endl;
				}
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

					mergeSort(head, sortField);

					while (head->previousAddress != NULL)
						head = head->previousAddress;

					displayTutor();

					mergeSort(head, 1);

				} while (cin.fail() || (sortField != 1 && sortField != 2 && sortField != 3));
				continue;
			case 5:
				cout << endl << endl;
				updateTutor(head);
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

		// display predefined tutor list
		predefinedTutorList();

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
				if (linearSearch(head) == false)
				{
					cout << "Unable to find tutor record!" << endl << endl << endl;
				}
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

					mergeSort(head, sortField);

					while (head->previousAddress != NULL)
						head = head->previousAddress;

					displayTutor();

					mergeSort(head, 1);

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