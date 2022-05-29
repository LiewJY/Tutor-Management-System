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
	double rating = 0;
	Tutor* nextAddress = NULL; // next pointer
	Tutor* previousAddress = NULL; // previous pointer
} *head, * tail;




// add new tutor list to the end
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
Tutor* createNewNode(int tutorID, string name, string dateJoined, string dateTerminated, double hourlyPayRate, string email, string phoneNumber,
	string address, string tuitionCenterCode, string tuitionCenterName, string subjectCode, string subjectName, double rating)
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

// display tutor list for process function and main function
void displayTutor()
{
	Tutor* current = head;

	cout << string(40, '-') << " TUTOR RECORD LIST " << string(40, '-') << endl << endl;

	while (current != NULL)
	{
		for (int position = 1; position <= ::sizeofLinkedList; position++)
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
				"Rating\t\t\t: " << fixed << setprecision(1) << current->rating << endl << endl;
			current = current->nextAddress;
		}
	}
}

// add tutor for main function
void addTutor()
{
	// empty the list
	head = tail = NULL;

	// predefined tutor list
	Tutor* newNode = createNewNode(1, "John", "20/1/2018", "30/6/2019", 15.00, "john@gmail.com", "0123456789", "6, Jalan Cheras, Taman Cheras, 56100 Chearas, Kuala Lumpur.", "CRS1001", "eXcel Tuition Center (Cheras)", "PHY1234", "Physics", 4.5);
	addTutorProcess(newNode);

	newNode = createNewNode(2, "May", "6/3/2018", "NA", 18.00, "may@gmail.com", "0184628592", "6, Jalan Cheras, Taman Cheras, 57000 Chearas, Kuala Lumpur.", "CRS1001", "eXcel Tuition Center (Cheras)", "AM2280", "Additional Mathematics", 4.8);
	addTutorProcess(newNode);

	newNode = createNewNode(3, "Brian", "3/8/2019", "NA", 17.00, "brian@gmail.com", "0118427585", "23-A, Jalan Jalil, 57000 Bukit Jalil, Kuala Lumpur.", "BKJ1001", "eXcel Tuition Center (Bukit Jalil)", "MAT3125", "Mathematics", 4.6);
	addTutorProcess(newNode);

	displayTutor();

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

			Tutor* newNode = createNewNode(tutorID, name, dateJoined, dateTerminated, hourlyPayRate, email,
				phoneNumber, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, rating);

			addTutorProcess(newNode);

			tutorID++;

			// ask user if they want to add additional tutor list
			cout << endl << "Do you want to add additional tutor record? 1- Yes, Others- No: ";
			cin >> userInput;
			cout << endl;
		}
	}

	displayTutor();
}

// update tutor list from specific location
void updateTutorProcess();

// update tutor for main function
void updateTutor();

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

		// if the program cannot find any position entered by user
		cout << "Failed to find the position from the tutor record! Please try again!" << endl << endl << endl;
	}
}

// delete tutor for main function
void deleteTutor()
{
	int userInput = 1;

	displayTutor();

	// ask user if they want to start deleting tutor list
	cout << "Enter: 1- Start Deleting Tutor, Others- Exit Delete Tutor: ";
	cin >> userInput;
	cout << endl;

	while (userInput == 1)
	{
		do
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter the position of tutor record that you want to delete: ";
			cin >> userInput;
			cout << endl;
		} while (cin.fail() || userInput < 1 || userInput > ::sizeofLinkedList);

		deleteTutorProcess(userInput);
		displayTutor();

		// if head is empty, display error message and stop delete process
		if (head == NULL)
		{
			break;
		}

		// ask user if they want to delete additional tutor list
		cout << "Do you want to delete additional tutor record? 1- Yes, Others- No: ";
		cin >> userInput;
		cout << endl;
	}
}

// login
int login() {

	//variables to authenticate and determine user type
	int userType;
	int userInput = 1;
	int status = 0;
	string username, password;

	if (userInput == 1)
	{
		while (userInput == 1) 
		{
			// ask user to select user type and enter username and password
			cout << "Please Select User type: " << endl << "1-HR, Others-Admin: ";
			cin >> userType;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter Username: ";
			getline(cin, username);
			cout << "Enter Password: ";
			getline(cin, password);

			// check user type and validate username and password
			if (userType == 1)
			{
				if (username == "hr" && password == "123") {
					cout << "Welcome HR " << endl << endl;
					//set the status to success (HR menu) & stop this loop
					status = 101;
					userInput = 2;
				}
			}
			else
			{
				if (username == "admin" && password == "123") {
					cout << "Welcome Admin" << endl << endl;
					//set the status to success (Admin menu) & stop this loop
					status = 102;
					userInput = 2;
				}
			}
			// incorrect credentials ask user do they want to retry
			if (status == 0)
			{
				cout << endl << "Incorrrect username and/or password. 1-Try Again, Others- No (Exit): ";
				cin >> userInput;
			}
		}
	}

	//return this value to determine what menu to show the user in main()
	return status;
}

//		merge sort code for linked list
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

	//variables to authenticate and determine user type

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
//		merge sort code for linked list end here


//		linear serach code
bool linearSearch(Tutor* head)
{
	// Stores head Node
	Tutor* temp = head;

	// store position 
	int position = 0;

	// if search term exist
	bool found = false;


	// todo complete this add the loop and error thing when input is incorrect
// linearSearch(head, int searchType, int SearchId, double searchRating)
	int searchType = 0;
	int searchId = 0;
	double searchRating = 0;

	// ask user to select field to search from
	cout << "Please Select search type: " << endl << "1-Tutor ID, 2-Rating: ";
	cin >> searchType;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (searchType == 1)
	{
		cout << "Please enter Id: ";
		cin >> searchId;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// go throgh the linked list (for id)
		while (temp->tutorID != searchId && temp->nextAddress != NULL) {

			// Update position
			position++;

			// Update temp data
			temp = temp->nextAddress;
		}
		// print print out the index
		if (temp->tutorID == searchId) {

			// todo add printing the details
			cout << "Found id at :" << position + 1 << endl;

			//item found
			found = true;
		}

	}

	else if (searchType == 2)
	{
		cout << "Please enter rating: ";
		cin >> searchRating;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// go throgh the whole linked list (for rating)
		while (temp->nextAddress != NULL) {

			// print print out the index
			if (temp->rating == searchRating) {

				// todo add printing the details
				cout << "Found at :" << position + 1 << endl;

				//item found
				found = true;
			}

			// Update position
			position++;

			// Update temp data
			temp = temp->nextAddress;

		}

	}
	else
	{
		cout << "Invalid input ";

	}


	// return T = found element, F = element not found
	return found;
}
//		linear search code end here

// main function
int main()
{
	// program menu should be here, when a user select an option, it will execute specific function
	// can use switch case

	addTutor();
	deleteTutor();

	// searching
	if (linearSearch(head) == false)
	{
		cout << "Cannot find data ";
	} 



	// todo menu for sort add the loop and error thing here the invalid input
	int sortField = 0;
	// ask user to select field to sort with MUST PUT HERE BECASUE THE FUNCTION ABOVE ALL ARE RECURSUE
	cout << "Please Select Field to sort: " << endl << "1-Tutor ID, 2-Hourly Pay Rate, 3-Rating: ";
	cin >> sortField;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	mergeSort(head, sortField);
	displayTutor();





	int status = login();
	// show HR or admin menu
	if (status == 101)
	{
		cout << "Show HR menu and loop this menu" << endl;
		mergeSort(head, sortField);
		displayTutor();
	}
	else if(status == 102)
	{
		cout << "Show Admin menu and loop this menu" << endl;
		addTutor();
	}



	return 0;
}




