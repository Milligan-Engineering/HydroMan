#include "workouts.h"



workouts::workouts()
{
}


workouts::~workouts()
{
}
workouts::workouts(int val1)
{
	rateOfPerceivedExertion = val1;
}

int workouts::getrateOfPerceivedExertion()
{
	return(rateOfPerceivedExertion);
}

double workouts::getworkoutDate()
{
	return(workoutDate);
}

string workouts::getexercises()
{
	return(exercises);
}

int workouts::setrateOfPerceivedExertion(int value)
{
	
	rateOfPerceivedExertion = value;
	return(value);
}

double workouts::setworkoutDate(double value)
{

	workoutDate = value;
	return(value);
}

string workouts::setexercises(string value)
{

	exercises = value;
	return(value);
}
