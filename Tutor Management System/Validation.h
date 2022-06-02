#include <regex>

using namespace std;

// name validation
bool nameValidation(string name)
{
	return std::none_of(name.begin(), name.end(), [](const char& input)
		{
			return !(std::isalpha(input) || input == ' ' || input == '-' || input == '\'');
		});
}

// date validation
bool dateValidation(int day, int month, int year)
{
	if (!(2000 <= year && year <= 2100))
		return false;
	if (!(1 <= month && month <= 12))
		return false;
	if (!(1 <= day && day <= 31))
		return false;
	if ((day == 31) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		return false;
	if ((day == 30) && (month == 2))
		return false;
	if ((month == 2) && (day == 29) && (year % 4 != 0))
		return false;
	if ((month == 2) && (day == 29) && (year % 400 == 0))
		return true;
	if ((month == 2) && (day == 29) && (year % 100 == 0))
		return false;
	if ((month == 2) && (day == 29) && (year % 4 == 0))
		return true;

	return true;
}

// email validation
bool emailValidation(string email)
{
	if (regex_match(email, regex("([a-z0-9]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)")))
		return true;

	return false;
}

// phone number validation
bool phoneNumberValidation(string phoneNumber)
{
	if (regex_match(phoneNumber, regex("([0-9]+)")))
		return true;

	return false;
}

// tuition center code validation
bool tuitionCenterCodeValidation(string tuitionCenterCode)
{
	return std::none_of(tuitionCenterCode.begin(), tuitionCenterCode.end(), [](const char& input)
		{
			return !(std::isalnum(input) || input == ' ' || input == '-');
		});
}

// subject code validation
bool subjectCodeValidation(string subjectCode)
{
	return std::none_of(subjectCode.begin(), subjectCode.end(), [](const char& input)
		{
			return !(std::isalnum(input) || input == ' ' || input == '-');
		});
}