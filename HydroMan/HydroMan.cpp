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

void newLine(ifstream& inWorkoutStream);

// encapsulated struct
struct water
{
	double todayWaterNeeded, waterDifference = 0;
	int totalOzOfWater = 0, ozOfWater = 0;
};


int main()
{
	char name[15] = "John"; //move to class
	char gender = 'M'; //move to class
	char moreInputs;
	char waterOrWorkout = 'S';
	double currentTime = static_cast<double>(time(NULL));
	ifstream inStream2, inWorkoutStream;
	ofstream waterStream, outWorkoutStream;
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
				//date format converter
				theDates.inputDates();
				double temp1 = theDates.dateToSeconds();
				workouts.setworkoutDate(temp1);
				int temp2;
				cout << "input intensity of this workout.\n";
				cin >> temp2;
				workouts.setrateOfPerceivedExertion(temp2);
				double timediff;
				timediff = workouts.getworkoutDate() - currentTime;
				//puts workout dates into file named workoutDateFile
				cout << "\n";
				outWorkoutStream.open("workoutDateFile.csv", std::ofstream::app);
				outWorkoutStream << name << "," << workouts.getworkoutDate() << ","<< workouts.getrateOfPerceivedExertion() << "\n";
				outWorkoutStream.close();
				break;
			}
			case 'D':
			{
				// pulls workout dates from workout date file and displays on the screen.
				char nameInFile[5];
				char workoutDateInFile[20];
				char intensityInFile[2];
				inWorkoutStream.open("workoutDateFile.csv");
				char ans;
				do
				{
					inWorkoutStream.getline(nameInFile, 5, ',');
					inWorkoutStream.getline(workoutDateInFile, 20, ',');
					inWorkoutStream.getline(intensityInFile, 2, '\n');
					//newLine(inWorkoutStream);
					int test;
					char stringTest[20] = "\0";
					test = strncmp(nameInFile, stringTest, 4);
					if (test == 0)
					{
						cout << "no more workouts left. \n";
						break;
					}
					else
					{
						cout << nameInFile << "\n";
						cout << workoutDateInFile << "\n";
						cout << intensityInFile << "\n";
						cout << "do you want to see the next workout? \n";
						cin >> ans;
					}

				} while (ans == 'y' || ans == 'Y');
				
				inWorkoutStream.close();
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
				waterStream.open("performance_data.csv", std::ofstream::app);
				if (waterStream.fail())
				{
					cout << "Input file opening failed.\n";
					exit(1);
				}
				waterStream << name << "," << currentTime << ","  << water.totalOzOfWater << "," << water.todayWaterNeeded << "\n";
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

void newLine(ifstream& inWorkoutStream)
{
	char symbol;
	do
	{
	inWorkoutStream.get(symbol);
	} while (symbol != '\n');
}


double baseWaterNeeded(workouts workouts, profile profileSetup)
{
	double waterNeeded;
	if (workouts.getrateOfPerceivedExertion() < 1 || workouts.getrateOfPerceivedExertion() > 10)
	{
		waterNeeded = (profileSetup.getweight() * .5);
	}
	else
	{
		waterNeeded = (profileSetup.getweight() * .5 + (workouts.getrateOfPerceivedExertion() * 3));
		return(waterNeeded);
	}
}
/*
void secondsToDate(double seconds)
{
	double numberOfDays = ((seconds/60)/(60))/24;
	double yearSince = (numberOfDays / 365);
	double yearVal = yearSince + 1970;
	double secSinceNewYears = seconds - (yearSince * 365 *60 *60 *24)
	for (int i = 0; i < monthVal - 1; i++)
	{
		if (((yearVal % 4 == 0) && (yearVal % 100 != 0)) || (yearVal % 400 == 0))
		{
			int daysOfMonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			timeFormat += daysOfMonth[i];
		}
		else
		{
			int daysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			timeFormat += daysOfMonth[i];
		}
	}
	 = timeFormat * 24 * 60 * 60;

}
*/