//File Name: HydroMan.cpp
//Author: John Rutherford
//Email Adress: jmrutherford@my.milligan.edu	
//Project Milestone 4
//Description: Program to manage athletes Hydration 
//Last Changed:  Feburary 4, 2019

#include <iostream>
#include <string>

/*PM04 Checklist
+ If Statement
+ Multi If or While
+ Indentation
+ Header
+ Comments - Be a bit more generous
+ Named Constant
+ Arrary
*/
using namespace std;

// String and calculation OK
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
	int daysInMonth[31] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };
	int monthsInYear[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int currentMonth;
	int d;
	int workoutDate[32];
	char anyKey;

	//profile setup 

	cout << "welcome to Hydration Managment 2019!\n";

	cout << "First, lets set up your user profile!\n";

	cout << "Name?\n";
	cin >> name;

	cout << "age?\n";
	cin >> age;

	cout << "weight in lbs?\n";
	cin >> weight;

	cout << "height in Ft and In?\n";
	cin >> heightFt >> heightIn;

	cout << "Your current proflie settings are.\n" << name << "\n"
		<< age << "Years old\n"
		<< weight << "lbs \n"
		<< heightFt << "Ft " << heightIn << "In \n";

	waterNeeded = weight * waterFactor;

	cout << "based on your profile you need to drink " << waterNeeded << " oz of water per day\n";

	cout << "would you like to track your water for the day or setup some workouts?\n";
	cout << "Press S to setup workouts or Press W to track water\n";
	cin >> waterOrWorkout;
	cout << "You choose " << waterOrWorkout << "\n";
	if (waterOrWorkout == 'W')
	{
		cout << "We are now ready to track water for the day!\n";

		// do while loop to track water

		totalOzOfWater = 0;

		do
		{
			cout << "Enter oz of water\n";
			cin >> ozOfWater;
			totalOzOfWater = ozOfWater + totalOzOfWater;
			cout << "You have currently drank " << totalOzOfWater << " oz. of water\n";
			cout << "do you want to continue? Y/N?";
			cin >> moreInputs;
		} while (moreInputs == 'Y');

		cout << "total water for the day is " << totalOzOfWater;
	}

	if (waterOrWorkout == 'S')
	{
		cout << "choose current month 1-12\n"; 
		cin >> currentMonth;
		cout << "You choose month " << currentMonth << "\n";
		d = 0;

		// january display loop
		if (currentMonth == 1)
		{
			cout << "      ";
			while (d <= 4)
			{
				cout << daysInMonth[d] << "  ";
				d++;
			}
			cout << "\n";
			while ((d > 4) && (d <= 8))
			{
				cout << daysInMonth[d] << "  ";
				d++;
			}
			while ((d > 8) && (d <= 11))
			{
				cout << daysInMonth[d] << " ";
				d++;
			}
			cout << "\n";
			while ((d > 11) && (d <= 18))
			{
				cout << daysInMonth[d] << " ";
				d++;
			}
			cout << "\n";
			while ((d > 18) && (d <= 25))
			{
				cout << daysInMonth[d] << " ";
				d++;
			}
			cout << "\n";
			while ((d > 25) && (d < 31))
			{
				cout << daysInMonth[d] << " ";
				d++;
			}
			cout << "\n";
		}

		cout << "hit any key to continue \n";
		cin >> anyKey;
			
			

	}
	return 0;
}