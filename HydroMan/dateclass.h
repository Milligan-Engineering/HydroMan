#pragma once
class dateclass
{
public:
	dateclass();
	~dateclass();
	class profile;

	double dateToSeconds();
	// Precondition: User inputs dates in format mm dd yyyy
	// Postcondition: Returns how many seconds from jan 1 1970 to 12:00AM on the date inputed

	void inputDates();
	// Precondition:  none
	// Postcondition: Stores dates in variables 

	friend int test(profile, dateclass);

	// Accessor Functions
	int getmonthVal();
	int getdayVal();
	int getyearVal();
	double getsecVal();

	// mutator functions
	int setmonthVal(int value);
		//Precondition: Value to set monthVal to its given in value
		//postcondition: monthVal is set to a value, value is also returned
	int setdayVal(int value);
	//Precondition: Value to set dayVal to its given in value
		//postcondition: dayVal is set to a value, value is also returned
	int setyearVal(int value);
	//Precondition: Value to set yearVal to its given in value
		//postcondition: yearVal is set to a value, value is also returned
	double setsecVal(double value);
	//Precondition: Value to set secVal to its given in value
		//postcondition: secVal is set to a value, value is also returned
private:
	int yearVal, monthVal, dayVal;
	double secVal;
};

