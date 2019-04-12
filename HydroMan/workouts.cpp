#include "workouts.h"



workouts::workouts()
{
}


workouts::~workouts()
{
}
workouts::workouts(int val1)
{
	rateOfPerceivedExertion[0] = 1;
}

int workouts::getrateOfPerceivedExertion()
{
	return(rateOfPerceivedExertion[1]);
}

double workouts::getworkoutDate()
{
	return(workoutDate[1]);
}

string workouts::getexercises()
{
	return(exercises[1]);
}

int workouts::setrateOfPerceivedExertion(int value[20])
{
	
	rateOfPerceivedExertion[1] = value[1];
	return(value[1]);
}

double workouts::setworkoutDate(double value[20])
{

	workoutDate[1] = value[1];
	return(value[1]);
}

string workouts::setexercises(string value[20])
{

	exercises[1] = value[1];
	return(value[1]);
}
