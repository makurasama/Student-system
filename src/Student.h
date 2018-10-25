#ifndef STUDENT_H
#define STUDENT_H

#include "Birthday.h"
#include "Sub.h"

using namespace std;

enum gender{male, female};

class Student
{
private:
	string name;
	int number;
	gender g;
	Birthday b;
	Sub s1,s2,s3;
public:
	Student();
	Student(string , int , string , Birthday , Sub , Sub , Sub );

	float sum();
	void genderinput(string );
	string genderdisp();
	void disp();
	string getname();
	int getnumber();
	friend ostream &operator <<(ostream &out, const Student &stu);
};
#endif