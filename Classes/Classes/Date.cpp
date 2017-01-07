#include <iostream>
#include "Date.h"
#include <string>

const int Date::days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

const string Date::monthName[] = { "","January","February","March","April"
									,"May","June","July","August","September",
									"October","November","December" };
//date constructor
Date::Date(int m, int d, int y) { setDate(m, d, y); }
//set the date
void Date::setDate(int mm, int dd, int yy)
{
	month = ( mm >= 1 && mm <= 12 ) ? mm : 1;
	year = (yy >= 1900 && yy <= 2100) ? yy : 1900;
	//test for leap year
	if (month == 2 && leapYear())
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	else
		day = (dd >= 1 && dd <= days[month]) ? dd : 1;
}
//add specfic number of days to a date
const Date&Date::operator+=(int additionalDays)
{
	for (int i = 0; i < additionalDays; i++)
		helpIncriment();

	return *this;
}
//if leap year return true, otherwise return false
bool Date::leapYear() const
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	else
		return false;
}
//see if the day is at the end of the month
bool Date::endOfMonth() const
{
	if (month == 2 && leapYear())
		return(year == 29);//last day in feb in leap year
	else
		return(year == days[month]);
}
//to help incriment the date
void Date::helpIncriment()
{
	//day is not at the end of the month
	if (!endOfMonth())
	{
		day++;
	}
		else if (month < 12)//day is at the end of the month but < 12
	{
		day = 1;
		++month;
	}
	else//last day of the year
	{
		day = 1;
		month = 1;
		++year;
	}
}
//overloaded output operator
ostream &operator<<(ostream &output, const Date &d)
{
	output << d.monthName[d.month] << ' '
		<< d.day << ", " << d.year;

	return output;//enables cascading
}
string Date::getMonthString() const
{
	return monthName[month];
}
int Date::getMonth() const
{
	return month;
}
int Date::getDay() const
{
	return day;
}
int Date::getYear() const
{
	return year;
}

