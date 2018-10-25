#ifndef BIRTHDAY_H
#define BIRTHDAY_H

using namespace std;

class Birthday
{
	int year;
	int month;
	int day;

public:
	Birthday();
	Birthday(int , int , int );

	void disp();
	int getyear();
	int getmonth();
	int getday();
	friend ostream &operator << (ostream &out, const Birthday &b);
};
#endif