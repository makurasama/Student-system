#ifndef IO_H
#define IO_H

namespace A
	{
	string name, g, sub1, sub2, sub3;
	int number,year, month, day;
	float score1, score2, score3;
	Node *node;
	Sub *s1,*s2,*s3;
	Birthday *b;
	Student *student;
	}

template <class T> void inputdigit(T &i)
{
	while(!(cin>>i))
	{
		cout<<"please input digit number"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
	}
}
void ReadDataFromFileWBW(StudentList &list);
void ReadDataFromKeyboard(StudentList &list);
void Desktop();
void WBtoFile(fstream &file1,StudentList &list);


#endif