#include "dateclass.h"
#include "stdafx.h"


dateclass::dateclass()
{
}


dateclass::~dateclass()
{
}

int dateclass::getmonthVal()
{
	return(monthVal);
}
int dateclass::getdayVal()
{
	return(dayVal);
}
int dateclass::getyearVal()
{
	return(yearVal);
}
double dateclass::getsecVal()
{
	return(secVal);
}

int dateclass::setmonthVal(int value)
{
	monthVal = value;
	return(value);
}

int dateclass::setdayVal(int value)
{
	dayVal = value;
	return(value);
}


int dateclass::setyearVal(int value)
{
	yearVal = value;
	return(value);
}

double dateclass::setsecVal(double value)
{
	secVal = value;
	return(value);
}



double dateclass::dateToSeconds()
{

	double timeFormat;
	timeFormat = (yearVal - 1970) * 365;
	timeFormat += (yearVal - 1969) / 4;
	for (int i = 0; i < monthVal - 1; i++)
	{
		if (((yearVal % 4 == 0) && (yearVal % 100 != 0)) || (yearVal % 400 == 0))
		{
			int daysOfMonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			timeFormat += daysOfMonth[i];
		}
		else
		{
			int daysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			timeFormat += daysOfMonth[i];
		}
	}
	timeFormat += dayVal - 1;
	timeFormat = timeFormat * 24 * 60 * 60;

	return(timeFormat);
}

void dateclass::inputDates()
{
	cout << "enter workout month, day and year.\n";
	cout << "form of mm dd yyyy.\n";
	cin >> monthVal;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}

	if ((monthVal < 1) || (monthVal > 12))
	{
		cout << "month input must be from 1 to 12.\n";
		cin >> monthVal;
	}
	cin >> dayVal;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}

	if ((dayVal < 1) || (dayVal > 31))
	{
		cout << "day input must be from 1 to 31.\n";
		cin >> dayVal;
	}

	cin >> yearVal;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}

	if ((yearVal < 1970) || (monthVal > 2099))
	{
		cout << "year input must be from 1970 to 2099.\n";
		cin >> yearVal;
	}

	cout << "you have selected " << monthVal << ", " << dayVal << ", " << yearVal << "\n";
}