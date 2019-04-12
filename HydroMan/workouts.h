#pragma once
#include "stdafx.h"

class workouts
{
public:
	workouts();
	~workouts();
	workouts(int val1);
	class profile;
	
	friend double baseWaterNeeded(workouts, profile);
	
	// accessor functions 
	int getrateOfPerceivedExertion();
	double getworkoutDate();
	string getexercises();

	// mutator functions 
	int setrateOfPerceivedExertion(int value);
	double setworkoutDate(double value);
	string setexercises(string value);

private:
	double workoutDate;
	int  rateOfPerceivedExertion;
	string exercises;
};

