//File Name: HydroMan.cpp
//Author: John Rutherford
//Email Adress: jmrutherford@my.milligan.edu	
//Project Milestone 9
//Description: Program to manage athletes Hydration 
//Last Changed:  April 1, 2019

#include "stdafx.h"
#include "dateclass.h"

void personalTraits(int& age, int& weight, int& heightFt, int& heightIn);  
// Precondition: User inputs age, weight, heightFt, and heightIN
// Postcondition: Funciton stores inputs in varibles

double baseWaterNeeded(int heightInPar, int heightFtPar, int agePar, int weightPar, char genderPar);
// Precondition: User will have variables stored in profile 
// Postcondition: User will know how much water needs to be drank in a day 

void listPrintDates(double dayArray[], int ArraySizeDay);
// Precondition: Must have a full array and know the size of the array
// Postcondition: Print values of array on screen


int numberOfWorkouts = 3;

int main()
{
	string name = "John";
	int age = 19;
	int weight = 210;
	int heightFt = 6;
	int heightIn = 5;
	char gender = 'M';
	int totalOzOfWater = 0;
	int ozOfWater;
	char moreInputs;
	char waterOrWorkout = 'S';
	int daysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	double todayWaterNeeded;
	double currentTime;
	double workoutDate[20];
	double waterDifference;
	int  rateOfPerceivedExertion[20];
	ifstream inStream, inStream2;
	ofstream outStream, outStream2, waterStream;

	dateclass theDates;

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
					cin >> ozOfWater;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits <streamsize>::max(), '\n');
					}

					while ((ozOfWater < 1) || (ozOfWater > 32))
					{
						cout << "Please enter a valid water input from 1 to 32 oz.\n";
						cin >> ozOfWater;
					}

					totalOzOfWater = ozOfWater + totalOzOfWater;
					cout << "You have currently drank " << totalOzOfWater << " oz. of water\n";
					todayWaterNeeded = baseWaterNeeded(heightIn, heightFt, age, weight, gender);
					cout << "based on your profile you need to drink " << todayWaterNeeded << " oz of water per day\n";
					waterDifference = todayWaterNeeded - totalOzOfWater;
					cout << "you still need " << waterDifference << " oz of water today.";
					cout << "do you want to continue? Y/N?";
					cin >> moreInputs;
				} while (moreInputs == 'Y');


				cout << " total water for the day is " << totalOzOfWater << "\n";
				waterStream.open("performance_data.csv");
				waterStream << name << "," << workoutDate[numberOfWorkouts] << "," << rateOfPerceivedExertion[numberOfWorkouts] << ","  << totalOzOfWater << "," << baseWaterNeeded;
				waterStream.close();
			}	break;
		
			case 'P':
			{
				// function to imput characteristics 
				personalTraits(age, weight, heightFt, heightIn);
				// puts profile setting into file named profileSettingsFile.
			
				outStream2.open("profileSettingsFile.csv");
				outStream2 << "age " << age << "\n" << "weight " << weight << "\n" << "height in Ft " << heightFt << "\n" << "height in In " << heightIn;
				todayWaterNeeded = baseWaterNeeded(heightIn, heightFt, age, weight, gender);
				cout << "based on your profile you need to drink " << todayWaterNeeded << " oz of water per day\n";

				outStream2.close();
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




double baseWaterNeeded(int heightInPar, int heightFtPar, int agePar, int weightPar, char genderPar)
{
	
	const double weightConst = .5;
	double waterNeeded;
	waterNeeded = weightPar * .5;
	return(waterNeeded);
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

void personalTraits(int& age,int& weight,int& heightFt,int& heightIn)
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

	while ((heightIn < 1) || (heightIn > 11))
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

