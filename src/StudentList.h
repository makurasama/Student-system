#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"
#include <iostream>
#include <fstream>

	class Node
	{
		Student data;
		Node *next;
		friend class StudentList;
	public:
		Node();
		Node(Student);
		Student &getStudent();
		Node *&getNext();
	};

	class StudentList
	{
	protected:
		Node *first ;
		Node *last;
		int n;
	public:
		StudentList();
		~StudentList();
		
		StudentList &Insert(Node &s);//向表头插入结点
		StudentList &Appand(Node &s);//向表未插入结点

		Node *Search(string n, bool d);//根据名字查找
		Node *Search(int n, bool d);//根据学号查找
		void find();//查找并显示总成绩最高和最低的学生信息

		StudentList &Clear();//删除所有结点
		StudentList &Delete();//删掉表头结点
		StudentList &Delete(string nn, bool d);
		StudentList &Delete(int nn, bool d);
		StudentList &Remove();//删掉表未结点
		
		int numberoflist();//统计链表中的学生人数
		void print();//输出这个链表
		Node * getFirstNode();//获取第一个结点
		Node * getLastNode();//获取最后一个结点
		Node * getMid(Node *);//获得中间结点
		Node * merge(Node *, Node *);//合并两个链表
		Node * merge_sort(Node *);
		StudentList &sort();

		friend fstream &operator << (fstream &file, StudentList &list);
		
	};


#endif