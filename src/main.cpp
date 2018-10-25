#include <iostream>
#include <string>
#include  <fstream>
#include "climits"

#include "Student.h"
#include "StudentList.h"
#include "Sub.h"
#include "Birthday.h"
#include "io.h"

using namespace std;

void  ReadDataFromFileWBW(StudentList &list)
{ 
	using namespace A;
	list.Clear();
	ifstream fin( "file.txt" ); 
	fin.seekg(0, ios_base::beg);

	while ( 1 ) 
	    {	
	    	number=year=month=day=0;score1=score2=score3=0.0;
			name.clear(); g.clear(); sub1.clear(); sub2.clear(); sub3.clear();
	    	fin>>name>>number>>g>>year>>month>>day>>sub1>>score1>>sub2>>score2>>sub3>>score3;
	    	b = new Birthday(year,month,day);
			s1 = new Sub(sub1,score1);
			s2 = new Sub(sub2,score2);
			s3 = new Sub(sub3,score3);
			student = new Student(name,number,g,*b,*s1,*s2,*s3);
			node = new Node(*student);
			list.Appand(*node);
	    	if(fin.eof())
	    	{
	    		break;
	    	}
	    }
	    list.Delete(0,false);
	    fin.close();
}

void ReadDataFromKeyboard(StudentList &list)
{
	using namespace A;
	
	cout<<"input student's name: "<<endl;
	cin>>name;	
	cout<<"input student's number: "<<endl;
	inputdigit(number);
	cout<<"input student's gender: (male/female)"<<endl;
	cin>>g;
	cout<<"input student's year: "<<endl;
	inputdigit(year);
	cout<<"input student's month: "<<endl;
	inputdigit(month);
	cout<<"input student's day: "<<endl;
	inputdigit(day);
	cout<<"input subject name: "<<endl;
	cin>>sub1;
	cout<<"input score: "<<endl;
	inputdigit(score1);
	cout<<"input subject name: "<<endl;
	cin>>sub2;
	cout<<"input score: "<<endl;
	inputdigit(score2);
	cout<<"input subject name: "<<endl;
	cin>>sub3;
	cout<<"input score: "<<endl;
	inputdigit(score3);
	b = new Birthday(year,month,day);
	s1 = new Sub(sub1,score1);
	s2 = new Sub(sub2,score2);
	s3 = new Sub(sub3,score3);
	student = new Student(name,number,g,*b,*s1,*s2,*s3);
	node = new Node(*student);
	list.Insert(*node);
	
}

void Desktop()
{
	cout<<"******* Welcome to our student system*******"<<endl;
	cout<<"***************Function List****************"<<endl;
	cout<<"1. Insert student information"<<endl;
	cout<<"2. Delete student information using name"<<endl;
	cout<<"3. Delete student information using name"<<endl;
	cout<<"4. Find student information using name"<<endl;
	cout<<"5. Find student information using number"<<endl;
	cout<<"6. Find highest and lowest score's student information"<<endl;
	cout<<"7. Output the number of students in the list"<<endl;
	cout<<"8. Display all student information"<<endl;
	cout<<"9. Sort the list from high to low total score"<<endl;
	cout<<"10. Close the system"<<endl;
	cout<<"*********************************************"<<endl;
	cout<<"Please input the function number you need"<<endl;
}

void WBtoFile(fstream &file1,StudentList &list)
{	
    file1.open("file.txt", fstream::out | ios_base::trunc);
    file1<<list;
    file1.close();
}
	
int main()
{
	using namespace A;

	StudentList list;

	ReadDataFromFileWBW(list);
	Desktop();

	int func=0;
	cin>>func;
	string name1;		
	int number1;
	fstream file1;
	while(func>0&&func<=10)
	{
		switch(func)
		{
			
			case 1:
			ReadDataFromKeyboard(list);
			WBtoFile(file1,list);
			break;
			
			case 2:
			cout<<"input student's name"<<endl;
			cin>>name1;
			cout<<"Deleted "<<name1<<"'s student information"<<endl;
			list.Delete(name1,true);
			WBtoFile(file1,list);
			break;

			case 3:
			cout<<"input student's number"<<endl;
			cin>>number1;
			cout<<"Deleted "<<number1<<"'s student information"<<endl;
			list.Delete(number1,true);
			WBtoFile(file1,list);
			break;

			case 4:
			cout<<"input student's name"<<endl;
			cin>>name1;
			list.Search(name1,true);
			break;

			case 5:
			cout<<"input student's number"<<endl;
			cin>>number1;
			list.Search(number1,true);
			break;

			case 6:
			list.find();
			break;

			case 7:
			cout<<list.numberoflist()<<"students"<<endl;
			break;

			case 8:
			//ReadDataFromFileWBW(list);
			list.print();
			break;

			case 9:
			list.sort();
			WBtoFile(file1,list);
			list.print();
			break;

			default:
			goto L1;

		}
		Desktop();
		cin>>func;
	}
	L1: cout<<"Thank you for using this system"<<endl;

}



