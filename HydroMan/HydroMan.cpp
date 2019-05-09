//File Name: HydroMan.cpp
//Author: John Rutherford
//Email Adress: jmrutherford@my.milligan.edu	
//Final Project
//Description: Program to manage athletes Hydration and workload.
//Last Changed:  May 9, 2019

#include "stdafx.h"
#include "dateclass.h"
#include "profile.h"
#include "workouts.h"

double baseWaterNeeded(workouts, profile);
// Precondition: User will have variables stored in profile
// Postcondition: User will know how much water needs to be drank in a day 

void YearTimeFinder(int(Timepar));
//YearTimeFinder function
		//Precondition: Uses a time in seconds- prefferably time Null 
		//Postcondition: gives the current date in the format, Month, Day, Year. To call month, day, or year, use this array:	double Today[3] = { YearMonthCheck, DayOfMonth, ThisYearInt };


void listPrintDates(double dayArray[], int ArraySizeDay);
// Precondition: Must have a full array and know the size of the array
// Postcondition: Print values of array on screen

void newLine(ifstream& inWorkoutStream);
// Precondition: have a file open
// Postcondition: Goes to next line in file.


// encapsulated struct
struct water
{
	double todayWaterNeeded, waterDifference = 0;
	int totalOzOfWater = 0, ozOfWater = 0;
};


int main()
{
	char name[5] = "John";
	char moreInputs;
	char waterOrWorkout = 'S';
	double currentTime = static_cast<double>(time(NULL));
	ifstream inStream2, inWorkoutStream;
	ofstream waterStream, outWorkoutStream;
	dateclass theDates;
	profile profileSetup(19, 210, 6, 4, 'M');
	water water;
	workouts workouts(7);

	// do while satement to relay menu prompt
	
    water.todayWaterNeeded = baseWaterNeeded(workouts, profileSetup);
	cout << "welcome to HydroMan 2019.\n";
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
				std::time_t result = std::time(nullptr);
				theDates.inputDates();
				//date format converter
				double temp1 = theDates.dateToSeconds();
				workouts.setworkoutDate(temp1);
				int temp2;
				cout << "input intensity of this workout.\n";
				cin >> temp2; //temp1 and temp2 is used because variables are in private class
				workouts.setrateOfPerceivedExertion(temp2);
				//puts workout dates into file named workoutDateFile
				cout << "\n";
				//storing data in file
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
					inWorkoutStream.getline(workoutDateInFile, ',');
					inWorkoutStream.getline(intensityInFile, 2, '\n');
					//newLine(inWorkoutStream);
					bool test;
					const char stringTest[20] = "\0";
					test = strncmp(nameInFile, stringTest, 4);
					if (test == 0)
					{
						cout << "no more workouts left. \n";
						break;
					}
					else
					{
						cout << nameInFile << "\n";
						int workoutDateInSeconds = atoi("workoutDateInFile");
						YearTimeFinder(workoutDateInSeconds);
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
					cout << "based on your profile you need to drink " << water.todayWaterNeeded << 
						" oz of water per day\n";
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
		return(waterNeeded);
	}
	else
	{
		waterNeeded = (profileSetup.getweight() * .5 + (workouts.getrateOfPerceivedExertion() * 3));
		return(waterNeeded);
	}
}


void YearTimeFinder(int(Timepar))
{

	int ThisYearInt;
	double CurrentSemester;
	string CurrentMonth;
	int DayOfMonth;
	int DaysSinceNewYears;
	int LeapYear;

	double SecondsSince1970 = static_cast<double>(time(NULL)); //Uses time NULL to get the current date. 
	double DaysSince1970 = ((SecondsSince1970 / 60) / 60) / 24;//number of days
	double YearsSince1970 = DaysSince1970 / 365.25;//number of years
	double ThisYeardouble = 1970 + YearsSince1970;
	ThisYearInt = static_cast<int>(ThisYeardouble);
	int FebruaryDays = 0;

	//Find number of seconds since new years
	double SecondsSinceNewYears = SecondsSince1970 - (static_cast<float>(ThisYearInt) - 1970) * 60 * 60 * 24 * 365.25;
	DaysSinceNewYears = static_cast<int>(SecondsSinceNewYears / (60 * 60 * 24)) + 1;

	//Month Name

	//Check for leap year

	int LeapYearCheck = ThisYearInt - 1972; // First leap year since 1970: 1972

	if (LeapYearCheck % 4 == 0)
	{
		LeapYear = 0;
	}
	else
	{
		LeapYear = 29;
	}
	//Identify Month
	string CurrentMonthName[13] = { "SecretLevelMonth", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int CurrentMonthDaysSum[13] = { 9, 31, FebruaryDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int MonthDays[13][33] =


	{
		/*SecretLevelMonth*/{ 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0},
		/*January:*/{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100},
		/*February*/{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,23,24,25,26,27,28, LeapYear,0, 0, 100},
		/*March*/ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100},
		/*April*/{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 0, 0, 100 },
		/*May*/ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100 },
		/*June*/{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 0, 0, 100 },
		/*July*/{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100 },
		/*August*/{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100 },
		/*September*/{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 0, 0, 100 },
		/*October*/ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100 },
		/*November*/ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 0, 0, 100 },
		/*December*/ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100 }
	};

	int SumofMonthDays[14] = { 0, 31, 31 + FebruaryDays, 62 + FebruaryDays, 92 + FebruaryDays, 123 + FebruaryDays, 153 + FebruaryDays, 184 + FebruaryDays, 215 + FebruaryDays, 245 + FebruaryDays, 276 + FebruaryDays, 306 + FebruaryDays,337 + FebruaryDays };



	int PriorMonthsDays = 0;
	DayOfMonth = 1;
	int YearMonthCheck = 1;
	while (PriorMonthsDays < DaysSinceNewYears)
	{

		/*if (MonthDays[YearMonthCheck][DayOfMonth] == 0)
		{
			DayOfMonth++;
		}
		*/

		if (MonthDays[YearMonthCheck][DayOfMonth] == 0)

		{
			YearMonthCheck++;
			DayOfMonth = 0;

		}

		DayOfMonth++;
		PriorMonthsDays++;
	}
	DayOfMonth--;

	CurrentMonth = CurrentMonthName[YearMonthCheck];

	int Today[3] = { YearMonthCheck, DayOfMonth, ThisYearInt };



	double SecondsSinceMidnight = SecondsSinceNewYears - PriorMonthsDays * 24 * 60 * 60;
	double HoursSinceMidnight = SecondsSinceNewYears - PriorMonthsDays * 24 * 60 * 60;


	cout << CurrentMonth<< " " << DayOfMonth << " " << ThisYearInt << "\n";



	//Identify Semester
	CurrentSemester = static_cast<double>(ThisYearInt);
	return;
}