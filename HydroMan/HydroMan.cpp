//File Name: HydroMan.cpp
//Author: John Rutherford
//Email Adress: jmrutherford@my.milligan.edu	
//Project Milestone 5
//Description: Program to manage athletes Hydration 
//Last Changed:  Feburary 15, 2019

#include <iostream>
#include <string>

using namespace std;
// Not taking valid inputs - line 91

int main()
{
	string name;
	int age;
	double weight;
	int heightFt;
	int heightIn;
	const double waterFactor = .5;
	double waterNeeded;
	int totalOzOfWater;
	int ozOfWater;
	char moreInputs;
	char waterOrWorkout;
	char anyKey;
	int daysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int yearVal;
	int monthVal;
	int dayVal;
	double time;

	//profile setup 

	cout << "welcome to Hydration Managment 2019!\n";

	cout << "First, lets set up your user profile!\n";

	cout << "Name?\n";
	cin >> name;

	cout << "age?\n";
	cin >> age;
	//validating age
	while ((age < 5) || (age > 100))
	{
		cout << "invalid input please enter an age 5 to 100.\n";
		cin >> age;
	}

	cout << "weight in lbs?\n";
	cin >> weight;
	//validating weight
	while ((weight < 80) || (weight > 500))
	{
		cout << "invalid input please enter a weight 80lbs to 500lbs.\n";
		cin >> weight;
	}

	cout << "height in Ft and In?\n";
	cin >> heightFt >> heightIn;
	//validating height
	while ((heightFt < 3) || (heightFt > 7))
	{
		cout << "invalid input please enter a height from 3FT and 7FT.\n";
		cin >> heightFt;

	}

	while ((heightIn < 1) || (heightIn > 11))
	{
		cout << "invalid input please enter a height from 0IN to 12IN.\n";
		cin >> heightIn;

	}

	cout << "Your current proflie settings are.\n" << name << "\n"
		<< age << "Years old \n"
		<< weight << "lbs \n"
		<< heightFt << "Ft " << heightIn << "In \n";

	waterNeeded = weight * waterFactor;

	cout << "based on your profile you need to drink " << waterNeeded << " oz of water per day\n";

	cout << "would you like to track your water for the day or setup some workouts?\n";
	cout << "Press S to setup workouts or Press W to track water\n";
	cin >> waterOrWorkout;

	while ((waterOrWorkout != 'W') && (waterOrWorkout != 'S'))
	{
		cout << "invalid input please enter W or S.\n";
		cin >> waterOrWorkout;
	}
	cout << "You chose " << waterOrWorkout << "\n";
	if (waterOrWorkout == 'W')
	{
		cout << "We are now ready to track water for the day!\n";

		// do while loop to track water

		totalOzOfWater = 0;

		do
		{
			cout << "Enter oz of water\n";
			cin >> ozOfWater;

			while ((ozOfWater < 0) || (ozOfWater > 33))
			{
				cout << "Please enter a valid water input from 1 to 32 oz.\n";
				cin >> ozOfWater;
			}
			
			totalOzOfWater = ozOfWater + totalOzOfWater;
			cout << "You have currently drank " << totalOzOfWater << " oz. of water\n";
			cout << "do you want to continue? Y/N?";
			cin >> moreInputs;
		} while (moreInputs == 'Y');

		cout << "total water for the day is " << totalOzOfWater;
	}

	//Workout Setup
	if (waterOrWorkout == 'S')
	{
		//date format converter
		cout << "enter current month, day and year.\n";
		cin >> monthVal;

		while ((monthVal < 1) || (monthVal > 12))
		{
			cout << "month input must be from 1 to 12.\n";
			cin >> monthVal;
		}

		cin >> dayVal;

		while ((dayVal < 1) || (dayVal > 31))
		{
			cout << "day input must be from 1 to 31.\n";
			cin >> dayVal;
		}

		cin >> yearVal;

		while ((yearVal < 2019) || (monthVal > 2099))
		{
			cout << "year input must be from 2019 to 2099.\n";
			cin >> yearVal;
		}
		cout << "you have selected" << monthVal << ", " << dayVal << ", " << yearVal << "\n";
		time = (yearVal - 1970) * 365;
		time += (yearVal - 1970) / 4;
		for (int i = 1; i < monthVal; i++)
		{
			time += daysOfMonth[i];
		}
		time += dayVal;
		time = time * 24 * 60 * 60;
		cout << time;


		cout << "hit any key to continue \n";
		cin >> anyKey;
			
			

	}
	return 0;
}