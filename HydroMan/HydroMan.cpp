//File Name: HydroMan.cpp
//Author: John Rutherford
//Email Adress: jmrutherford@my.milligan.edu	
//Project Milestone 4
//Description: Program to manage athletes Hydration 
//Last Changed:  Feburary 4, 2019





#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name;
	int age;
	double weight;
	int heightFt;
	int heightIn;
	double WaterNeeded;
	int TotalOzOfWater;
	int OzOfWater;
	char MoreInputs;

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

	WaterNeeded = weight * .5;

	cout << "based on your profile you need to drink " << WaterNeeded << " oz of water per day\n";

	cout << "We are now ready to track water for the day!\n";

	TotalOzOfWater = 0;

	do
	{
		cout << "Enter oz of water\n";
		cin >> OzOfWater;
		TotalOzOfWater = OzOfWater + TotalOzOfWater;
		cout << "You have currently drank " << TotalOzOfWater << " oz. of water\n";
		cout << "do you want to continue? Y/N?";
		cin >> MoreInputs;
	} while (MoreInputs == 'Y' );

	cout << "total water for the day is " << TotalOzOfWater;
	return 0;
}