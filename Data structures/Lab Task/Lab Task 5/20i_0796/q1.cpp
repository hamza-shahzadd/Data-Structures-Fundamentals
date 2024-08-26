// M.Hamza Shahzad
// 20i-0796
// Data structures lab 5
// task 01




#include<iostream>
using namespace std;



class node
{
	int data;
	node *next;
	
	
	public:
	
	node(int d)
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

class linkedlist
{
	node *head;
	
	public:
	
	linkedlist()
	{
		head=NULL;
	}
	
	

};

int main()
{
	linkedlist a;


	return 0;
}
