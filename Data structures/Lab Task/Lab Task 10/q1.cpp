// M.Hamza Shahzad
// 20i-0796
// Question 1
// Lab Task 10



#include<iostream>
using namespace std;


class queue
{
	public:
	int size;
	int arr[4];
	int front;
	int rear;
	
	
	queue()
	{
		front=-1;
		rear=-1;
	}
	

	bool isempty()
	{
		if(front == -1)
		{
			cout << "Queue is empty"<< endl;
			return true;
		}
		else 
		return false;
	}	
	
	bool isfull()
	{
		if(rear == size-1)
		{
			cout << "Queue is full" << endl;
			return true;
		}
		else 
		return false;
		
	}
	
	void enqueue(int x)
	{
		if(rear == size-1)
		{
			cout << "Queue is full" << endl;
		}
		
		else if(front == -1)
		{
			front = front + 1;
			rear= rear + 1;
			arr[rear]= x; 
		}
		else 
		{
			arr[rear]=x;
			rear ++;
		}
	}
	
	int dequeue()
	{
	
		int temp;
		
		if(front == -1)
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		else if(rear == front) 
		{
			temp = arr[rear];
			rear=rear -1;
			front = front -1;
			return temp;
		}
		else
		temp= arr[front];
		front = front + 1;
		return temp;
		
	}
	
	void peek()
	{
		if(rear == -1)
		{
			cout << "Queue is empty" << endl;
			
		}
		else 
		{
			cout << arr[front];
			cout << endl;
		}

	}
	
	void display()
	{
		for(int i =0; i < 4; i++)
		{
			cout << arr[i];
			cout << " ";
		}
	
	}

};

int main()
{

	queue q;
	q.isempty();
	q.isfull();
	q.enqueue(3);
	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(6);
	q.dequeue();
	q.peek();
	q.display();
	


	



return 0;
}
