// M.Hamza Shahzad
// 20i-0796
// Question 2
// DS lab 6


#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *next;
	node *prev;
	
	
	node()
	{
		data=0;
		next=NULL;
		prev=NULL;
	}
	
	
};

class doublyLinkedList
{
	
	public:
	
	node *head;
	
	doublyLinkedList()
	{
		head=NULL;
	}
	
	void insertAtfirst(int val)
	{
		node *nnode= NULL;
		nnode = new node;
		
		head=nnode;
		head->data= val;
		head->prev= NULL;
		head->next= NULL;
		
		node *nenode= new node;
		nenode->prev= NULL;
		nenode->next=head;
		head->prev= nenode->next;
		head= nenode;

	}
	
	void insertAtLast(int val)
	{
		node *last= head;
		while(last->next != NULL)
		{
			last=last->next;
		}
		node *mnode= new node;
		mnode->data= val;
		last->next= mnode;
		mnode->next=NULL;
		mnode->prev= last;
		
		
	}
	void display()
	{
		node *temp= new node;
		temp=head;
		while(temp->next != NULL)
		{
			cout << temp->data;
			temp= temp->next;
		}

	}
	
};


int main()
{
	doublyLinkedList a;
	a.insertAtLast(3);
	a.insertAtLast(2);
	a.display();
	
	
	return 0;



}
