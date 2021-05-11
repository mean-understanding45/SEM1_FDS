/*Queues are frequently used in computer programming, and a typical example is the creation of a job queue
by an operating system. If the operating system does not use priorities, 
then the jobs are processed in the order they enter the system. 
Write C++ program for simulating job queue.
Write functions to add job and delete job from queue. */

#include<iostream>
using namespace std;

#define size 5
class node
{
	public:
		int job_id;
		node *next;
};

class Jqueue
{
	node *rear, *front;
	public:
		Jqueue()
		{
			front = rear = NULL;
		}
		void insert();
		void ins();
		void del();
		void display();
};

void Jqueue :: insert()
{
	node *n = new node;
	cout<<"\nEnter job ID: ";
	cin>>n->job_id;
	n->next = NULL;
	if(rear == NULL)
		front = rear = n;
	else
	{
		rear->next = n;
		rear = n;
	}
}

void Jqueue :: ins()
{
	int pos, x;
	node *ptr = front;
	cout<<"Enter the position before which you want to insert: ";
	cin>>pos;
	cout<<"Enter job id: ";
	cin>>x;
	node *temp = new node;
	temp -> job_id = x;
	for(int i=0;i<pos-1;i++)
		ptr = ptr -> next;
	temp->next = ptr->next;
	ptr->next = temp;
}

void Jqueue :: del()
{
	int x;
	if(front == NULL)
		cout<<"Queue is empty.";
	else
	{
		cout<<"Enter position to be deleted: ";
		cin>>x;
		node *p=front;
		node *q=NULL;
		for(int i=0;i<x-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		int n = p->job_id;
		delete p;
	}
}
		
void Jqueue :: display()
{
	if(rear == NULL)
		cout<<"Queue is empty.";
	else
	{
		node *temp = front;
		cout<<"The queue contains: "<<endl;
		while(temp!=NULL)
		{
			cout<<temp->job_id<<"\t";
			temp = temp->next;
		}
	}
}

int main()
{
	Jqueue q;
	int ch;
	char choice = 'y';
	do
	{
		cout<<"\nMENU"<<endl;
		cout<<"1. Insert data."<<endl;
		cout<<"2. Insert before an element: "<<endl;
		cout<<"3. Delete data."<<endl;
		cout<<"4. Display data."<<endl;
		cout<<"Enter choice(1/2/3): ";
		cin>>ch;
		switch(ch)	
		{
			case 1 : q.insert();
					 break;
			case 2: q.ins();
					 break;
			case 3 : q.del();
					 break;	
			case 4 : q.display();
					 break;		
			default : cout<<"Wrong option entered.";
					  break;
		}
		
		cout<<"\nWould you like to continue(y/n): ";
		cin>>choice;
	}
	while(choice == 'y' || choice == 'Y');
	cout<<"\nEnd";
}