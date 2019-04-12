#pragma once
#include "stdafx.h"

class workouts
{
public:
	workouts();
	~workouts();
	workouts(int val1);
	class profile;
	friend double baseWaterNeeded(profile profileSetup);

	// accessor functions 
	int getrateOfPerceivedExertion();
	double getworkoutDate();
	string getexercises();

	int setrateOfPerceivedExertion(int value[20]);
	double setworkoutDate(double value[20]);
	string setexercises(string value[20]);

private:
	double workoutDate[20];
	int  rateOfPerceivedExertion[20];
	string exercises[20];
};

