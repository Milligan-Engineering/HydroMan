#pragma once

class profile
{
public:
	profile();
	~profile();

	profile(int val1, int val2, int val3, int val4);

	class workouts;
	
	// Precondition: User will have variables stored in profile 
	// Postcondition: User will know how much water needs to be drank in a day 

	void personalTraits();
	// Precondition: User inputs age, weight, heightFt, and heightIN
	// Postcondition: Funciton stores inputs in varibles

	friend double baseWaterNeeded(workouts, profile);
	// Precondition: User will have variables stored in profile 
	// Postcondition: User will know how much water needs to be drank in a day 



	// acessor function
	int getage();
	int getweight();
	int getheightFt();
	int getheightIn();

	// mutator function
	int setage(int value);
	//Precondition: Value to set age to its given in value
	//postcondition: age is set to a value, value is also returned

	int setweight(int value);
	//Precondition: Value to set weight to its given in value
	//postcondition: weight is set to a value, value is also returned

	int setheightFt(int value);
	//Precondition: Value to set heightFt to its given in value
	//postcondition: heightFt is set to a value, value is also returned

	int setheightIn(int value);
	//Precondition: Value to set heightIn to its given in value
	//postcondition: heightIn is set to a value, value is also returned

private:
	int age, weight, heightFt, heightIn;
};

