// M.Hamza Shahzad
// 20i-0796
// Question 1
// DS lab 6


#include<iostream>
using namespace std;

class node
{
	int data;
	node *next;
	node *prev;
	public:
	
	node()
	{
		data=0;
		next=NULL;
		prev=NULL;
	}
	node( int d)
	{
		data=d;
		
	}
	
	void setData(int D)
	{
		data=D;
	}
	int getData()
	{
		return data;
	}

};

class DoublyLinkedList
{
	node *head;
	
	public:
	DoublyLinkedList()
	{
		head=NULL;	
	}
	
	void newnode()
	{
		node *nnode= new node;
	
		nnode=head;
		nnode= node->getData();
	}
	void display()
	{
		node* temp= new node;
		temp= head;
		while(temp!= node->getData() )
		{
			cout << nnode.getData();
			nnode= nnode->next;
		}
	}
	

};


int main()
{
	node n(4);
	DoublyLinkedList a;
	a.newnode();
	a.display();

	return 0;

}
