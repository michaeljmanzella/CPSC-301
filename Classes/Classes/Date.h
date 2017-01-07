#ifndef DATE1_H
#define DATE1_H
#include <iostream>
#include <string>

using namespace std;

class Date {
	friend ostream &operator<<(ostream &, const Date &);

public:
	Date(int m = 1, int d = 1, int y = 1900);
	void setDate(int, int, int);
	const Date &operator+=(int);
	bool leapYear() const;
	bool endOfMonth() const;
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	string getMonthString() const;
private:
	int month;
	int day;
	int year;

	static const int days[];
	static const string monthName[];
	void helpIncriment();

};

#endif


