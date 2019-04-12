//File Name: HydroMan.cpp
//Author: John Rutherford
//Email Adress: jmrutherford@my.milligan.edu	
//Project Milestone 11
//Description: Program to manage athletes Hydration and workload.
//Last Changed:  April 10, 2019

#include "stdafx.h"
#include "dateclass.h"
#include "profile.h"
#include "workouts.h"

double baseWaterNeeded(workouts, profile);

void listPrintDates(double dayArray[], int ArraySizeDay);
// Precondition: Must have a full array and know the size of the array
// Postcondition: Print values of array on screen

// encapsulated struct
struct water
{
	double todayWaterNeeded, waterDifference = 0;
	int totalOzOfWater = 0, ozOfWater = 0;
};




int main()
{
	string name = "John";
	char gender = 'M';
	char moreInputs;
	char waterOrWorkout = 'S';
	double currentTime;
	ifstream inStream, inStream2, inWorkoutStream;
	ofstream outStream, waterStream, outWorkoutStream;

	dateclass theDates;
	profile profileSetup(19, 210, 6, 4);
	water water;
	workouts workouts(7);

	// do while satement to relay menu prompt
	
    water.todayWaterNeeded = baseWaterNeeded(workouts, profileSetup);

	do 
	{
		
		// menu for switch
		cout << "S - Setup Workouts. \nD - Display upcoming workouts.\nW - Track Water. \nP - Change Settings.\nE - Exit Program.";
		cin >> waterOrWorkout; 
		waterOrWorkout = toupper(waterOrWorkout);

		switch (waterOrWorkout)
		{
			// workout branch
			case 'S' :
			{
				// telling current time
				currentTime = static_cast<double>(time(NULL));
				//date format converter
				double i[20] = { 7 };
				theDates.inputDates();
				double temp = theDates.dateToSeconds();
				workouts.setworkoutDate(temp);
				double timediff;
				timediff = workouts.getworkoutDate() - currentTime;
				//puts workout dates into file named workoutDateFile
				cout << "\n";
				outStream.open("workoutDateFile.csv");
				outStream << name << "," << " has a workout on " << "," << workouts.getworkoutDate() << "," << " with a RPE of " << ","<< workouts.getrateOfPerceivedExertion();
				outStream.close();
				break;
			}
			case 'D':
			{
				// pulls workout dates from workout date file and displays on the screen.
				string line;
				inStream.open("workoutDateFile.csv");
				getline(inStream, line);
				cout << line << endl;
				inStream.close();
				break;
			}
			case 'W':
			{
				cout << "We are now ready to track water for the day!\n";

				// do while loop to track water

				do
				{
					cout << "Enter oz of water\n";
					cin >> water.ozOfWater;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits <streamsize>::max(), '\n');
					}

					while ((water.ozOfWater < 1) || (water.ozOfWater > 32))
					{
						cout << "Please enter a valid water input from 1 to 32 oz.\n";
						cin >> water.ozOfWater;
					}

					water.totalOzOfWater = water.ozOfWater + water.totalOzOfWater;
					cout << "You have currently drank " << water.totalOzOfWater << " oz. of water\n";
					water.todayWaterNeeded = baseWaterNeeded(workouts, profileSetup);
					cout << "based on your profile you need to drink " << water.todayWaterNeeded << " oz of water per day\n";
					water.waterDifference = water.todayWaterNeeded - water.totalOzOfWater;
					cout << "you still need " << water.waterDifference << " oz of water today.";

					cout << "do you want to continue? Y/N?";
					cin >> moreInputs;
					moreInputs = toupper(moreInputs);

				} while (moreInputs == 'Y');


				cout << " total water for the day is " << water.totalOzOfWater << "\n";
				currentTime = static_cast<double>(time(NULL));
				waterStream.open("performance_data.csv");
				waterStream << name << "," << name << "," << currentTime << ","  << water.totalOzOfWater << "," << water.todayWaterNeeded;
				waterStream.close();
			}	break;
		
			case 'P':
			{
				// function to imput characteristics 
				profileSetup.personalTraits();
				// puts profile setting into file named profileSettingsFile.
							
				water.todayWaterNeeded = baseWaterNeeded(workouts, profileSetup);
				cout << "based on your profile you need to drink " << water.todayWaterNeeded << " oz of water per day\n";

				break;
			}
		}
		if ((waterOrWorkout != 'E') && (waterOrWorkout != 'S') && (waterOrWorkout != 'D') && (waterOrWorkout != 'W') && (waterOrWorkout != 'P'))
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
			}
			cout << "invalid input please enter a character E, S, D, W, P.\n";
		}
	} while (waterOrWorkout != 'E');
}

void listPrintDates(double dayArray[], int ArraySizeDay)
{
	for (int i = 0; i <= ArraySizeDay; i++)
	{
		if (dayArray[i] > 0)
		{
			cout << "you have a workout on " << dayArray[i] << " of this month";
		}
	}
	return;
}




double baseWaterNeeded(workouts workouts, profile profileSetup)
{

	double waterNeeded;
	waterNeeded = (profileSetup.getweight() * .5 + (workouts.getrateOfPerceivedExertion() * 3));
	return(waterNeeded);
}