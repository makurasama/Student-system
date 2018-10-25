#include <iostream>
#include <string>
#include <fstream>


#include "StudentList.h"

using namespace std;


Node::Node()
{
	Student();
	next=NULL;
}

Node::Node(Student stu)
{
	data=stu;
	next=NULL;
}

Student &Node::getStudent()
{
	return data;
}

Node *&Node::getNext()
{
	return next;
}

StudentList::StudentList()
{
	first=last=new Node;
	n=0;
}
StudentList::~StudentList()
{
	Clear();
	delete first;
	n=0;
}
	
StudentList &StudentList::Clear()
{
	Node *p = first;
	while(p!=last)
	{
		Node * next =p->next;
		delete p;
		p=next;
	}
	first = last;
	n=0;
	return (*this);
}

StudentList &StudentList::Insert(Node  &s)//向表头插入结点
{
	Node *p = first;
	first = new Node;
	*first = s;
	first->next = p;
	n++;
	return (*this);
}
	
StudentList &StudentList::Appand(Node  &x)//向表未插入结点
{
	Node *p = last;
	*p = x;
	last = new Node;
	p->next = last;
	n++;
	return (*this);
}

Node *StudentList::Search(string n, bool d)//根据名字查找
{
	if(first==last)
	{
		cout<<"this list is empty"<<endl;
		return NULL;
	}
	else
	{
		Node *pre;
		Node *p=first;
		while(p!=last)
		{
			if(p==first&&p->data.getname()==n)
			{
				if(d)
					p->data.disp();
				return p;
				break;
			}
			else if(p->data.getname()==n)
			{
				if(d)
					p->data.disp();
				return pre;
				break;
			}
			pre=p;
			p=p->next;
		}

	}
	cout<<"System can't find Node in the list"<<endl;
	return NULL;
}

Node *StudentList::Search(int n, bool d)//根据学号查找
{
	if(first==last)
	{
		cout<<"this list is empty"<<endl;
		return NULL;
	}
	else
	{
		Node *pre;
		Node *p=first;
		while(p!=last)
		{
			if(p==first&&p->data.getnumber()==n)
			{
				if(d)
					p->data.disp();
				return p;
				break;
			}
			else if(p->data.getnumber()==n)
			{
				if(d)
					p->data.disp();
				return pre;
				break;
			}
			pre=p;
			p=p->next;
		}

	}
	cout<<"System can't find Node in the list"<<endl;
	return NULL;
}


StudentList &StudentList::Delete()
{
	if(first!=last)
	{
		Node *p = first->next;
		delete first;
		first = p;
	}
	n--;
	return(*this);
}


StudentList &StudentList::Delete(string nn,bool d)//根据给定的学生姓名删除该学生节点；
{
	Node *pre=NULL;
	Node *p=Search(nn,d);
	if(p==NULL);
	else if(p->data.getname()==nn&&p==first)
		Delete();
	else
	{	
		pre=p;
		p=pre->next;
		pre->next=p->next;
		delete p;
	}
	n--;
	return(*this);
}

StudentList &StudentList::Delete(int nn, bool d)//根据给定的学生学号删除该学生节点；
{
	Node *pre=NULL;
	Node *p=Search(nn,d);
	if(p==NULL);
	else if(p->data.getnumber()==nn&&p==first)
		Delete();
	else
	{	
		pre=p;
		p=pre->next;
		pre->next=p->next;
		delete p;
	}
	n--;
	return(*this);
}

StudentList &StudentList::Remove()//删掉表未结点
{
	if(first->next==last)
		Delete();
	else if(first==last);
	else
	{
		Node *now  = first;
		Node *p;
		while(now->next!=last)
		{
			p=now;
			now=now->next;
		}
		p->next=last;
		delete now;
	}
	n--;
	return(*this);
}

void StudentList::find()
{
	Node *now=first;
	Node *max=first,*min=first;
	while(now!=last)
	{
		if(max->data.sum()<now->data.sum())
		{
			max=now;
		}
		if(min->data.sum()>now->data.sum())
		{
			min=now;
		}
		now=now->next;
	}
	cout<<"display total score highest student information"<<endl;
	max->data.disp();
	cout<<"Total score: "<<max->data.sum()<<endl;
	cout<<"display total score lowest student information"<<endl;
	min->data.disp();
	cout<<"Total score: "<<min->data.sum()<<endl;
}

int StudentList::numberoflist()
{
	return n;
}

void StudentList::print()
{
	cout<<"********list********"<<endl;
	int no=1;
	Node *p= first;
	while (p!=last)
	{
		cout<<no++<<": "<<endl;
		p->data.disp();
		cout<<endl;
		p=p->next;
	}
}

Node *StudentList::getFirstNode()
{
	return first;
}

Node *StudentList::getLastNode()

{
	return last;
}


Node* StudentList::merge_sort(Node* head) 
{
    if(head == NULL || head->next == NULL)
        return head;

    Node* head1 = head;
    Node* head2 = getMid(head);  //获取中间节点，将链表分为两段
    head1 = merge_sort(head1);   //分别对两段链表进行排序
    head2 = merge_sort(head2);
    return merge(head1, head2);  //将两段有序链表合并
}

Node* StudentList::merge(Node* head1, Node* head2) //合并两个有序链表
{
    Node* newhead = new Node;
    Node* newtail = newhead;
    while(head1 && head2)
    {
        if(head1->data.sum() <= head2->data.sum())
        {
            newtail->next = head2;
            head2 = head2->next;
        }
        else
        {
            newtail->next = head1;
            head1 = head1->next;
        }
        newtail = newtail->next;
        newtail->next = NULL;
    }
    if(head1)   newtail->next = head1;
    if(head2)   newtail->next = head2;
    return newhead->next;  //链表头节点
}

Node* StudentList::getMid(Node* head)  //获取中间节点并分段
{
    Node* fast = head->next;
    Node* slow = head->next;
    Node* prev = head;
    while(true)
    {
        if(fast == NULL) break;
        fast = fast->next;
        if(fast == NULL)    break;
        fast = fast->next;

        prev = slow;
        slow = slow->next;
    }
    prev->next = NULL;  //将链表分为两段
    return slow;
}

StudentList &StudentList::sort()
{
	Node * pre;
	Node * p;

	p=merge_sort(first);
first=p;
	first->next=p->next;
	//cout<<first->getStudent()<<endl;
	n=0;
	while(p)
	{
		//cout<<p->getStudent()<<endl;
		pre=p;
		p = p->next;
		n++;           
	}
	last=pre;
	return (*this);
}

fstream &operator << (fstream &file, StudentList &list)
{
	Node *tmp = list.getFirstNode();
	int len = list.numberoflist();
	while(tmp!=list.getLastNode())
	{
		file << tmp->getStudent();
		tmp = tmp->getNext();
	}
	return file;
}
