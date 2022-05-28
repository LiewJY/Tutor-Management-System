#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <array>
#include "Validation.h"

using namespace std;

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
};


// add tutor for main function
void addTutor()
{
	Tutor* dynamicArray = NULL; // initialize dynamic array to empty
	dynamicArray = new Tutor[3]; // allocate 3 new dynamic array size

	// predefined tutor list
	dynamicArray[0].tutorID = 1;
	dynamicArray[0].name = "John";
	dynamicArray[0].dateJoined = "20/1/2018";
	dynamicArray[0].dateTerminated = "30/6/2019";
	dynamicArray[0].hourlyPayRate = 15.00;
	dynamicArray[0].email = "john@gmail.com";
	dynamicArray[0].phoneNumber = "0123456789";
	dynamicArray[0].address = "6, Jalan Cheras, Taman Cheras, 56100 Chearas, Kuala Lumpur.";
	dynamicArray[0].tuitionCenterCode = "CRS1001";
	dynamicArray[0].tuitionCenterName = "eXcel Tuition Center (Cheras)";
	dynamicArray[0].subjectCode = "PHY1234";
	dynamicArray[0].subjectName = "Physics";
	dynamicArray[0].rating = 4.5;

	dynamicArray[1].tutorID = 2;
	dynamicArray[1].name = "May";
	dynamicArray[1].dateJoined = "6/3/2018";
	dynamicArray[1].dateTerminated = "NA";
	dynamicArray[1].hourlyPayRate = 18.00;
	dynamicArray[1].email = "may@gmail.com";
	dynamicArray[1].phoneNumber = "0184628592";
	dynamicArray[1].address = "13A, Jalan Barat, Taman Mutiara, 57000 Chearas, Kuala Lumpur.";
	dynamicArray[1].tuitionCenterCode = "CRS1001";
	dynamicArray[1].tuitionCenterName = "eXcel Tuition Center (Cheras)";
	dynamicArray[1].subjectCode = "AM2280";
	dynamicArray[1].subjectName = "Additional Mathematics";
	dynamicArray[1].rating = 4.8;

	dynamicArray[2].tutorID = 3;
	dynamicArray[2].name = "Brian";
	dynamicArray[2].dateJoined = "3/8/2019";
	dynamicArray[2].dateTerminated = "NA";
	dynamicArray[2].hourlyPayRate = 17.00;
	dynamicArray[2].email = "brian@gmail.com";
	dynamicArray[2].phoneNumber = "0118427585";
	dynamicArray[2].address = "23-B, Jalan Jalil, 57000 Bukit Jalil, Kuala Lumpur.";
	dynamicArray[2].tuitionCenterCode = "BKJ1001";
	dynamicArray[2].tuitionCenterName = "eXcel Tuition Center (Bukit Jalil)";
	dynamicArray[2].subjectCode = "MAT3125";
	dynamicArray[2].subjectName = "Mathematics";
	dynamicArray[2].rating = 4.6;


	//dynamicArray[0]->tutorID = 1;
	//dynamicArray[0]->name = "John";
	//dynamicArray[0]->dateJoined = "20/1/2018";
	//dynamicArray[0]->dateTerminated = "30/6/2019";
	//dynamicArray[0]->hourlyPayRate = 15.00;
	//dynamicArray[0]->email = "john@gmail.com";
	//dynamicArray[0]->phoneNumber = "0123456789";
	//dynamicArray[0]->address = "6, Jalan Cheras, Taman Cheras, 56100 Chearas, Kuala Lumpur.";
	//dynamicArray[0]->tuitionCenterCode = "CRS1001";
	//dynamicArray[0]->tuitionCenterName = "eXcel Tuition Center (Cheras)";
	//dynamicArray[0]->subjectCode = "PHY1234";
	//dynamicArray[0]->subjectName = "Physics";
	//dynamicArray[0]->rating = 4.5;

	//dynamicArray[1]->tutorID = 2;
	//dynamicArray[1]->name = "May";
	//dynamicArray[1]->dateJoined = "6/3/2018";
	//dynamicArray[1]->dateTerminated = "NA";
	//dynamicArray[1]->hourlyPayRate = 18.00;
	//dynamicArray[1]->email = "may@gmail.com";
	//dynamicArray[1]->phoneNumber = "0184628592";
	//dynamicArray[1]->address = "13A, Jalan Barat, Taman Mutiara, 57000 Chearas, Kuala Lumpur.";
	//dynamicArray[1]->tuitionCenterCode = "CRS1001";
	//dynamicArray[1]->tuitionCenterName = "eXcel Tuition Center (Cheras)";
	//dynamicArray[1]->subjectCode = "AM2280";
	//dynamicArray[1]->subjectName = "Additional Mathematics";
	//dynamicArray[1]->rating = 4.8;

	//dynamicArray[2]->tutorID = 3;
	//dynamicArray[2]->name = "Brian";
	//dynamicArray[2]->dateJoined = "3/8/2019";
	//dynamicArray[2]->dateTerminated = "NA";
	//dynamicArray[2]->hourlyPayRate = 17.00;
	//dynamicArray[2]->email = "brian@gmail.com";
	//dynamicArray[2]->phoneNumber = "0118427585";
	//dynamicArray[2]->address = "23-B, Jalan Jalil, 57000 Bukit Jalil, Kuala Lumpur.";
	//dynamicArray[2]->tuitionCenterCode = "BKJ1001";
	//dynamicArray[2]->tuitionCenterName = "eXcel Tuition Center (Bukit Jalil)";
	//dynamicArray[2]->subjectCode = "MAT3125";
	//dynamicArray[2]->subjectName = "Mathematics";
	//dynamicArray[2]->rating = 4.6;


	// variables to read from user input
	int userInput = 1;
	int tutorID = 4;
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


	// ask user if they want to start adding tutor list
	cout << "Enter: 1- Start Adding Tutor, Others- Exit Add Tutor: ";
	cin >> userInput;
	cout << endl;

	if (userInput == 1)
	{
		while (userInput == 1)
		{
			int number = 1;

			Tutor* dynamicArray = new Tutor[number]; // allocate 1 new dynamic array size

			for (int i = 0; i < number; i++)
			{
				// name
				cout << "Enter Name: ";
				getline(cin, name);

				// date joined
				cout << "Enter Date Joined: ";
				cin >> dateJoined;
				
				// date terminated
				cout << "Enter Date Terminated: ";
				cin >> dateTerminated;

				// hourly pay rate
				cout << "Enter Hourly Pay Rate: ";
				cin >> hourlyPayRate;

				// email
				cout << "Enter Email: ";
				cin >> email;
				
				// phone number
				cout << "Enter Phone Number: ";
				cin >> phoneNumber;

				// address
				cout << "Enter Address: ";
				getline(cin, address);

				// tuition center code
				cout << "Enter Tuition Center Code: ";
				cin >> tuitionCenterCode;

				// tuition center name
				cout << "Enter Tuition Center Name: ";
				getline(cin, tuitionCenterName);

				// subject code
				cout << "Enter Subject Code: ";
				cin >> subjectCode;

				// subject name
				cout << "Enter Subject Name: ";
				getline(cin, subjectName);

				// rating
				cout << "Enter Rating: ";
				cin >> rating;

				dynamicArray[number].name = name;
				dynamicArray[number].dateJoined = dateJoined;
				dynamicArray[number].dateTerminated = dateTerminated;
				dynamicArray[number].hourlyPayRate = hourlyPayRate;
				dynamicArray[number].email = email;
				dynamicArray[number].phoneNumber = phoneNumber;
				dynamicArray[number].address = address;
				dynamicArray[number].tuitionCenterCode = tuitionCenterCode;
				dynamicArray[number].tuitionCenterName = tuitionCenterName;
				dynamicArray[number].subjectCode = subjectCode;
				dynamicArray[number].subjectName = subjectName;
				dynamicArray[number].rating = rating;
			}

			tutorID++;

			// ask user if they want to add additional tutor list
			cout << endl << "Do you want to add additional tutor record? 1- Yes, Others- No: ";
			cin >> userInput;
			cout << endl;
		}
	}


	// display tutor record list (temporary, will move to display function later)
	cout << "Tutor Record List:" << endl << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Tutor ID: " << dynamicArray[i].tutorID << "\nName: " << dynamicArray[i].name << "\nAddress: " << dynamicArray[i].address << endl << endl;
	}


	// free up memory when the process is done
	delete[] dynamicArray;
	dynamicArray = NULL;

}

// display tutor
//void displayTutor();

// update tutor for main function
//void updateTutor();

// delete tutor for main function
//void deleteTutor();




// main function
int main()
{
	// menu goes here
	addTutor();

	return 0;
}