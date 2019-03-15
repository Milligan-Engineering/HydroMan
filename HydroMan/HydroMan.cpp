//File Name: HydroMan.cpp
//Author: John Rutherford
//Email Adress: jmrutherford@my.milligan.edu	
//Project Milestone 5
//Description: Program to manage athletes Hydration 
//Last Changed:  Feburary 15, 2019

#include <iostream>
#include <string>
#include <ctime>
#include <fstream> 

using namespace std;

void inputDates(int& monthVal, int& dayVal, int& yearVal);

void personalTraits(int age, int weight, int heightFt, int heightIn);

double dateToSeconds(int monthVal, int dayVal, int yearVal);
// Precondition: User inputs dates in format mm dd yyyy
// Postcondition: Returns how many seconds from jan 1 1970 to 12:00AM on the date inputed

double baseWaterNeeded(int heightInPar, int heightFtPar, int agePar, int weightPar, char genderPar);
// Precondition: User will have variables stored in profile 
// Postcondition: User will know how much water needs to be drank in a day

void listPrintDates(double dayArray[], int ArraySizeDay);


int numberOfWorkouts = 3;

int main()
{
	int age = 19;
	int weight = 210;
	int heightFt = 6;
	int heightIn = 5;
	char gender = 'M';
	int totalOzOfWater = 0;
	int ozOfWater;
	char moreInputs;
	char waterOrWorkout;
	int daysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int yearVal;
	int monthVal;
	int dayVal;
	double todayWaterNeeded;
	double currentTime;
	double workoutDate[20];
	double waterDifference;
	ifstream inStream, instream2;
	ofstream outStream, outStream2;

	// do while satement to relay menu prompt
	do
	{
		// menu for switch
		cout << "S - Setup Workouts. \nD - Display upcoming workouts.\nW - Track Water. \nP - Change Settings.\nE - Exit Program.";
		cin >> waterOrWorkout;



		switch (waterOrWorkout)
		{
			// workout branch
			case 'S':
			{
				// telling current time
				currentTime = time(NULL);
				cout << currentTime << " seconds has passed since 00:00:00 GMT, Jan 1, 1970\n";
				//date format converter
			
				inputDates(monthVal, dayVal, yearVal);
				workoutDate[numberOfWorkouts] = dateToSeconds(monthVal, dayVal, yearVal);
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

					while ((ozOfWater < 0) || (ozOfWater > 33))
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
			}	break;
		
			case 'P':
			{
				// function to imput characteristics 
				personalTraits(age, weight, heightFt, heightIn);
				// puts profile setting into file named profileSettingsFile.
				instream2.open("profileSettingsFile");
				outStream2.open("profileSettingsFile");
				outStream2 << "age " << age << "\n" << "weight " << weight << "\n" << "height in Ft " << heightFt << "\n" << "height in In " << heightIn;
				instream2 >> age >> weight >> heightFt >> heightIn;
				todayWaterNeeded = baseWaterNeeded(heightIn, heightFt, age, weight, gender);
				cout << "based on your profile you need to drink " << todayWaterNeeded << " oz of water per day\n";

				instream2.close();
				outStream2.close();
				break;
			}
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

double dateToSeconds(int monthVal, int dayVal, int yearVal)
{
	
	double timeFormat;
	timeFormat = (yearVal - 1970) * 365;
	timeFormat += (yearVal - 1969) / 4;
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
	timeFormat += dayVal - 1;
	timeFormat = timeFormat * 24 * 60 * 60;
	
	cout << timeFormat;
	return(timeFormat);
}



void listPrintDates(double dayArray[], int ArraySizeDay)
{
	for (int i = 0; i < ArraySizeDay; i++)
	{
		if (dayArray[i] > 0)
		{
			cout << "you have a workout on " << dayArray[i] << " of this month" << "\n";
		}
	}
	return;
}

void personalTraits(int age,int weight,int heightFt,int heightIn)
{
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
	return;
}

void inputDates(int& monthVal, int& dayVal, int& yearVal)
{
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

	while ((yearVal < 1970) || (monthVal > 2099))
	{
		cout << "year input must be from 1970 to 2099.\n";
		cin >> yearVal;
	}

	cout << "you have selected " << monthVal << ", " << dayVal << ", " << yearVal << "\n";
}