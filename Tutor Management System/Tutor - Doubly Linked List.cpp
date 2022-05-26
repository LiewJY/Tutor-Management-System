#include <iostream>
#include <string>

using namespace std;

// structure of tutor
struct Tutor
{
	int tutorID;
	string name;
	string dateJoined;
	string dateTerminated;
	double hourlyPayRate;
	string email;
	string phoneNumber;
	string address;
	string tuitionCenterCode;
	string tuitionCenterName;
	string subjectCode;
	string subjectName;
	double rating;
	Tutor* nextAddress; // next pointer
	Tutor* previousAddress; // previous pointer
} *head, * tail;

// structure of human resource manager
struct HumanResourceManager
{
	int humanResourceID;
	string name;
	string email;
	string phoneNumber;
	string password;
};

// structure of admin manager
struct AdminManager
{
	int adminID;
	string name;
	string email;
	string phoneNumber;
	string password;
};




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

	cout << "Tutor List:" << endl << endl;
	cout << "Tutor ID | Name | Date Joined | Date Terminated | Hourly Pay Rate | Email | Phone Number | Address | Tuition Center Code | Tuition Center Name | Subject Code | Subject Name | Rating" << endl << endl;

	while (current != NULL)
	{
		cout << current->tutorID << " | " << current->name << " | " << current->dateJoined << " | " << current->dateTerminated << " | " <<
			current->hourlyPayRate << " | " << current->email << " | " << current->phoneNumber << " | " << current->address << " | " <<
			current->tuitionCenterCode << " | " << current->tuitionCenterName << " | " << current->subjectCode << " | " <<
			current->subjectName << " | " << current->rating << endl << endl;
		current = current->nextAddress;
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

	// display tutor list
	displayTutor();

	// variables to read from user input
	int userInput = 1;
	int tutorID = 4;
	string name;
	string dateJoined;
	string dateTerminated;
	double hourlyPayRate;
	string email;
	string phoneNumber;
	string address;
	string tuitionCenterCode;
	string tuitionCenterName;
	string subjectCode;
	string subjectName;
	double rating;

	// ask user if they want to add tutor list
	cout << "Do you want to add tutor list? 1- Yes, Others- No: ";
	cin >> userInput;

	if (userInput == 1)
	{
		while (userInput == 1)
		{
			cout << "Enter Name: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			cout << "Enter Date Joined (In DD/MM/YYYY): ";
			getline(cin, dateJoined);
			cout << "Enter Date Terminated (In DD/MM/YYYY). Enter 'NA' if tutor is active: ";
			getline(cin, dateTerminated);
			cout << "Enter Hourly Pay Rate: ";
			cin >> hourlyPayRate;
			cout << "Enter Email: ";
			cin >> email;
			cout << "Enter Phone Number: ";
			cin >> phoneNumber;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Address: ";
			getline(cin, address);
			cout << "Enter Tuition Center Code: ";
			cin >> tuitionCenterCode;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Tuition Center Name: ";
			getline(cin, tuitionCenterName);
			cout << "Enter Subject Code: ";
			cin >> subjectCode;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter Subject Name: ";
			getline(cin, subjectName);
			cout << "Enter Rating: ";
			cin >> rating;
			Tutor* newNode = createNewNode(tutorID, name, dateJoined, dateTerminated, hourlyPayRate, email,
				phoneNumber, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, rating);

			addTutorProcess(newNode);

			tutorID++;

			// ask user if they want to add additional tutor list
			cout << endl << "Do you want to add more tutor list? 1-Yes, Others- No: ";
			cin >> userInput;
		}
	}

	// display tutor list
	displayTutor();
}

// update tutor list from specific location
void updateTutorProcess();

// update tutor for main function
void updateTutor();

// delete tutor list from specific location
void deleteTutorProcess();

// delete tutor for main function
void deleteTutor();

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






// main function
int main()
{
	// program menu should be here, when a user select an option, it will execute specific function
	int status = login();
	// show HR or admin menu
	if (status == 101)
	{
		cout << "Show HR menu and loop this menu" << endl;
		addTutor();
	}
	else if(status == 102)
	{
		cout << "Show Admin menu and loop this menu" << endl;
		addTutor();
	}


	return 0;
}