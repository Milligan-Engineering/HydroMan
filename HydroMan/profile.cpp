#include "profile.h"
#include "stdafx.h"


profile::profile()
{
}


profile::~profile()
{
}

profile::profile(int val1, int val2, int val3, int val4, char val6)
{
	age = val1;
	weight = val2;
	heightFt = val3;
	heightIn = val4;
	gender = val6; 
	
}

int profile::getage()
{
	return(age);
}
 
int profile::getweight()
{
	return(weight);
}

int profile::getheightFt()
{
	return(heightFt);
}

int profile::getheightIn()
{
	return(heightIn);
}

char profile::setgender()
{
	return(gender);
}

int profile::setage(int value)
{
	age = value;
	return(value);
}

int profile::setweight(int value)
{
	weight = value;
	return(value);
}

int profile::setheightFt(int value)
{
	heightFt = value;
	return(value);
}

int profile::setheightIn(int value)
{
	heightIn = value;
	return(value);
}

char profile::setgender(char value)
{
	gender = value;
		return(value);
}

void profile::personalTraits()
{
	cout << "Lets set up your user profile!\n";

	cout << "age?\n";
	cin >> age;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}

	//validating age
	while ((age < 5) || (age > 100))
	{
		cout << "invalid input please enter an age 5 to 100.\n";
		cin >> age;
	}



	cout << "weight in lbs?\n";
	cin >> weight;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}

	//validating weight
	while ((weight < 80) || (weight > 500))
	{
		cout << "invalid input please enter a weight 80lbs to 500lbs.\n";
		cin >> weight;
	}

	cout << "height in Ft and In?\n";
	cin >> heightFt >> heightIn;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}

	//validating height
	while ((heightFt < 3) || (heightFt > 7))
	{
		cout << "invalid input please enter a height from 3FT and 7FT.\n";
		cin >> heightFt;
	}

	while ((heightIn < 0) || (heightIn > 11))
	{
		cout << "invalid input please enter a height from 0IN to 12IN.\n";
		cin >> heightIn;
	}

	cout << "Your current proflie settings are.\n"
		<< age << "Years old \n"
		<< weight << "lbs \n"
		<< heightFt << "Ft " << heightIn << "In \n";
	return;
}

