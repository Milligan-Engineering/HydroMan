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

	cout << "Enter oz of water\n";
	cin >> OzOfWater;
	TotalOzOfWater = OzOfWater;
	cout << "You have currently drank " << TotalOzOfWater << " oz. of water\n";

	cout << "Enter oz of water\n";
	cin >> OzOfWater;
	TotalOzOfWater = OzOfWater + TotalOzOfWater;
	cout << "You have currently drank " << TotalOzOfWater << " oz. of water\n";

	cout << "Enter oz of water\n";
	cin >> OzOfWater;
	TotalOzOfWater = OzOfWater + TotalOzOfWater;
	cout << "You have currently drank " << TotalOzOfWater << " oz. of water\n";

	cout << "Enter oz of water\n";
	cin >> OzOfWater;
	TotalOzOfWater = OzOfWater + TotalOzOfWater;
	cout << "You have currently drank " << TotalOzOfWater << " oz. of water\n";

	cout << "Enter oz of water\n";
	cin >> OzOfWater;
	TotalOzOfWater = OzOfWater + TotalOzOfWater;
	cout << "You have currently drank " << TotalOzOfWater << " oz. of water\n";

	cout << "Enter oz of water\n";
	cin >> OzOfWater;
	TotalOzOfWater = OzOfWater + TotalOzOfWater;
	cout << "You have currently drank " << TotalOzOfWater << " oz. of water\n";

	cout << "Enter oz of water\n";
	cin >> OzOfWater;
	TotalOzOfWater = OzOfWater + TotalOzOfWater;
	cout << "You have currently drank " << TotalOzOfWater << " oz. of water\n"; 

	return 0;
}