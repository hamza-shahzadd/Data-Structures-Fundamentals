// M.Hamza shahzad
// 20i-0796
// Lab 9
// Question 1


#include<iostream>
using namespace std;




class node
{
	public:
	
	int data;
	node *next;

	node()
	{
		data=0;
		next= NULL;
	}
};


class stack
{
	public:
	node *head;
	
	stack()
	{
		head= NULL;
	}
	
/*	void stack()
	{
		node *nnode= new node;
		if(head == NULL)
		{
			
			head== nnode;
		}
		else
		node *temp= head;
		while(temp->next != head)
		{
			temp=temp->next;
		}
		
		temp->next = nnode;
		
		
	}
*/	
	bool is_empty()
	{
		if(head == NULL)
		{
			cout << "Stack is empty" << endl;
			return false;
		}
		else 
		return true;
	}
	void push(int val)
	{
		node *nnode= new node;
		nnode->data= val;
		
		if(head == NULL)
		{
			head=nnode;	
		}
		else
		{
			nnode->next =head;
			head=nnode;
			
		}
	}
	
	int pop()
	{
		node* temp= head;
		if( temp == NULL)
		{
			return -1;
		}
		else
		{
			head=head->next;
			return temp->data;
			
	
		}	
			
		
	}
	int peek()
	{
		
		return head->data;
		
	}
	
	void display()
	{
		node *temp= head;
		while(temp != NULL)
		{
			cout << " " << temp->data;
			temp=temp->next;
		}
		cout << endl;
		
	}
	
	void sort(int data)
	{
		int temp=0;
		
		if(head == NULL)
		{
			push(data);
		}
		else if( data < head->data)
		{
			temp=pop();
			sort(data);
			push (temp);
		}
		else
		{
		 push(data);
		}
	}
	
};








int main()
{
	int b,c;
	
	
	
	stack s;
	s.is_empty();
	s.push(3);
	s.push(5);
	s.push(7);
	s.push(8);
	cout <<"Value inserted are 3,5,7,8 " << endl;
	s.display();
	b=s.pop();	
	cout << "The popped value is = " << b << endl;
	c=s.peek();
	cout << "The value on top of the stack is = " << c << endl;
	s.sort(4);
	s.sort(2);
	s.sort(9);
	s.display();
	


	return 0;

}












