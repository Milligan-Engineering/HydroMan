//File Name: HydroMan.cpp
//Author: John Rutherford
//Email Adress: jmrutherford@my.milligan.edu	
//Project Milestone 5
//Description: Program to manage athletes Hydration 
//Last Changed:  Feburary 15, 2019

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

double timeConverter(int monthVal, int dayVal, int yearVal);
// Precondition: User inputs dates
// Postcondition: how many seconds from jan 1 1970 to date inputed

double baseWaterNeeded(int heightInPar, int heightFtPar, int agePar, int weightPar, char genderPar);
// Precondition: User will have variables stored in profile 
// Postcondition: User will know how much water needs to be drank in a day



int main()
{
	int age = 19;
	double weight = 210;
	int heightFt = 6;
	int heightIn = 5;
	char gender = 'M';
	int totalOzOfWater;
	int ozOfWater;
	char moreInputs;
	char waterOrWorkout;
	int daysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int yearVal;
	int monthVal;
	int dayVal;
	double wantedTime;
	double todayWaterNeeded;
	double currentTime;
	double workoutDate;
	double timeDifference;


	cout << "S - Setup Workouts. \nW - Track Water. \nP - Change Settings.";
	cin >> waterOrWorkout;

	switch (waterOrWorkout)
	{
	case 'S':
		// telling current time
		time_t(currentTime);
		currentTime = time(NULL);
		cout << currentTime << " seconds has passed since 00:00:00 GMT, Jan 1, 1970\n";
		
		//date format converter

		cout << "enter workout month, day and year.\n";
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

		cout << "you have selected " << monthVal << ", " << dayVal << ", " << yearVal << "\n";
		workoutDate = timeConverter(monthVal, dayVal, yearVal);
		

		cout << "you selected a workout date for.\n" << workoutDate;

		timeDifference = workoutDate - currentTime;
		cout << "time until workout is " << timeDifference << "\n";

		// Validation
		cout << "What would you like to do next? \n";
		cout << "S - Setup Workouts. \n";
		cout << "W - Track Water. \n";
		cout << "P - Change Settings. \n";
		cin >> waterOrWorkout;

		// Validation
		while ((waterOrWorkout != 'W') && (waterOrWorkout != 'S') && (waterOrWorkout != 'P'))
		{
			cout << "invalid input please enter W, S or P.\n";
			cin >> waterOrWorkout;
		}

	case 'W':
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

		// redirection menu
		cout << "What would you like to do next? \n";
		cout << "S - Setup Workouts. \n";
		cout << "W - Track Water. \n";
		cout << "P - Change Settings. \n";
		cin >> waterOrWorkout;

		// Validation
		while ((waterOrWorkout != 'W') && (waterOrWorkout != 'S') && (waterOrWorkout != 'P'))
		{
			cout << "invalid input please enter W, S or P.\n";
			cin >> waterOrWorkout;
		}
	

	case 'P':
		cout << "Lets set up your user profile!\n";


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

		cout << "Your current proflie settings are.\n" << "\n"
			<< age << "Years old \n"
			<< weight << "lbs \n"
			<< heightFt << "Ft " << heightIn << "In \n";
		todayWaterNeeded = baseWaterNeeded(heightIn, heightFt, age, weight, gender);
		cout << "based on your profile you need to drink " << todayWaterNeeded << " oz of water per day\n";

		// Redirection menu
		cout << "What would you like to do next? \n";
		cout << "S - Setup Workouts. \n";
		cout << "W - Track Water. \n";
		cout << "P - Change Settings. \n";
		cin >> waterOrWorkout;

		// Validation
		while ((waterOrWorkout != 'W') && (waterOrWorkout != 'S') && (waterOrWorkout != 'P'))
		{
			cout << "invalid input please enter W, S or P.\n";
			cin >> waterOrWorkout;
		}

	}




	while ((waterOrWorkout != 'W') && (waterOrWorkout != 'S') && (waterOrWorkout != 'P'))
	{
		cout << "invalid input please enter W, S or P.\n";
		cin >> waterOrWorkout;
	}
}
	double baseWaterNeeded(int heightInPar, int heightFtPar, int agePar, int weightPar, char genderPar)
	{
		const double weightConst = .5;
		double waterNeeded;
		waterNeeded = weightPar * .5;
		return(waterNeeded);
	}

	double timeConverter(int monthVal, int dayVal, int yearVal)
	{

		double timeFormat;
		int daysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		timeFormat = (yearVal - 1970) * 365;
		timeFormat += (yearVal - 1970) / 4;
		for (int i = 1; i < monthVal; i++)
		{
			timeFormat += daysOfMonth[i];
		}
		timeFormat += dayVal;
		timeFormat = timeFormat * 24 * 60 * 60;
		cout << timeFormat;
		return(timeFormat);
	}

	