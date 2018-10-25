#ifndef SUB_H
#define SUB_H

#include "string"
#include "iostream"
using namespace std;

class Sub
{
	string subject;
	float score;
public:
	Sub();
	Sub(string , float );

	void disp();
	string getname();
	float getscore();
	friend ostream & operator << (ostream &out, const Sub &s);
};

#endif