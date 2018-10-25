#include "iostream"
#include "string"
#include "Birthday.h"
#include "Sub.h"
#include "Student.h"

using namespace std;

Student::Student()
{
	name='\0';
	number=0;
	g=gender(0);
	Birthday b;
	Sub s1,s2,s3;
}
	
Student::Student(string na, int n, string g1, Birthday b1, Sub s11, Sub s21, Sub s31)
{
	name = na;
	number = n;
	genderinput(g1);
	b = b1;
	s1 = s11;
	s2 = s21;
	s3 = s31;
}

float Student::sum()
{
	float s=0.0;
	s=s1.getscore()+s2.getscore()+s3.getscore();
	return s;
}

void Student::genderinput(string g1)
{
	if(g1=="male"||g1=="0")
		g=gender(0);
	else if(g1=="female"||g1=="1")
		g=gender(1);
}

string Student::genderdisp()
{
	if(g==0)
		return "male";
	else
		return "female";
}

void Student::disp()
{
	cout<<"name: "<<name<<endl;
	cout<<"number: "<<number<<endl;
	cout<<"gender: "<<genderdisp()<<endl;
	b.disp();
	s1.disp();s2.disp();s3.disp();
}

string Student::getname()
{
	return name;
}

int Student::getnumber()
{
	return number;
}

ostream &operator << (ostream &out, const Student &stu)
{
    out<<stu.name<<" "<<stu.number<<" "<<stu.g<<" "<<stu.b<<" "<<stu.s1<<" "<<stu.s2<<" "<<stu.s3<<endl;
    return out;
}

