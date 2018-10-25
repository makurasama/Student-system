#include "iostream"
#include "Birthday.h"

using namespace std;

Birthday::Birthday()
{
	year=0;
	month=0;
	day=0;
}
Birthday::Birthday(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

void Birthday::disp()
{
	cout<<"Birthday: "<<year<<"."<<month<<"."<<day<<endl;
}

int Birthday::getyear()
{
	return year;
}
int Birthday::getmonth()
{
	return month;
}
int Birthday::getday()
{
	return day;
}

ostream &operator << (ostream &out, const Birthday &b)
{
	out<<b.year<<" "<<b.month<<" "<<b.day;
	return out;
}

