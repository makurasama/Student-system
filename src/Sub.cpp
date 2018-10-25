#include "iostream"
#include "fstream"
#include "string"
#include "Sub.h"

Sub::Sub()
{
	subject='\0';
	score=0.0;
}

Sub::Sub(string sub, float s)
{
	subject = sub;
	score = s;
}

void Sub::disp()
{
	cout<<"subject: "<<subject<<endl;
	cout<<"score: "<<score<<endl;
}

string Sub::getname()
{
	return subject;
}

float Sub::getscore()
{
	return score;
}

ostream &operator << (ostream &out, const Sub &s)
{
	out<<s.subject<<" "<<s.score;
	return out;
}


