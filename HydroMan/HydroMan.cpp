//File Name: HydroMan.cpp
//Author: John Rutherford
//Email Adress: jmrutherford@my.milligan.edu	
//Project Milestone 9
//Description: Program to manage athletes Hydration 
//Last Changed:  April 1, 2019

#include "stdafx.h"
#include "dateclass.h"
#include "profile.h"

void listPrintDates(double dayArray[], int ArraySizeDay);
// Precondition: Must have a full array and know the size of the array
// Postcondition: Print values of array on screen

struct water
{
	double todayWaterNeeded, waterDifference;
	int totalOzOfWater, ozOfWater;
};


int numberOfWorkouts = 3;

int main()
{
	string name = "John";
	char gender = 'M';
	char moreInputs;
	char waterOrWorkout = 'S';
	double currentTime;
	double workoutDate[20];
	int  rateOfPerceivedExertion[20];
	ifstream inStream, inStream2;
	ofstream outStream, waterStream;

	dateclass theDates;
	profile profileSetup;
	water water;

	// do while satement to relay menu prompt
	


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
			
				theDates.inputDates(); 
				workoutDate[numberOfWorkouts] = theDates.dateToSeconds();
				double timediff;
				timediff = workoutDate[numberOfWorkouts] - currentTime;

				//puts workout dates into file named workoutDateFile
				listPrintDates(workoutDate, 3);
				cout << "\n";
				outStream.open("workoutDateFile");
				outStream << "You have a workout on " << workoutDate[numberOfWorkouts];
				outStream.close();

				break;
			}
			case 'D':
			{
				// pulls workout dates from workout date file and displays on the screen.
				string line;
				inStream.open("workoutDateFile");
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
					water.todayWaterNeeded = profileSetup.baseWaterNeeded();
					cout << "based on your profile you need to drink " << water.todayWaterNeeded << " oz of water per day\n";
					water.waterDifference = water.todayWaterNeeded - water.totalOzOfWater;
					cout << "you still need " << water.waterDifference << " oz of water today.";
					cout << "do you want to continue? Y/N?";
					cin >> moreInputs;
				} while (moreInputs == 'Y');


				cout << " total water for the day is " << water.totalOzOfWater << "\n";
				waterStream.open("performance_data.csv");
				waterStream << name << "," << workoutDate[numberOfWorkouts] << "," << rateOfPerceivedExertion[numberOfWorkouts] << ","  << water.totalOzOfWater << "," << water.todayWaterNeeded;
				waterStream.close();
			}	break;
		
			case 'P':
			{
				// function to imput characteristics 
				profileSetup.personalTraits();
				// puts profile setting into file named profileSettingsFile.
							
				water.todayWaterNeeded = profileSetup.baseWaterNeeded();
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



int test(profile profileSetup, dateclass theDate)
{
	return(profileSetup.getage() + theDate.getmonthVal());
}