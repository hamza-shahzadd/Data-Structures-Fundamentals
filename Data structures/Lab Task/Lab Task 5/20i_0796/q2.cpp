// M.Hamza Shahzad
// 20i-0796
// Data structures lab 5
// task 02




#include<iostream>
using namespace std;


class Node
{
public:
	int data;
	Node* next;


};


class List
{
public:

	Node* head;

	List()
	{
		head = NULL;
	}
	void InsertAfter(int current_data, int insert_data)
	{
		Node* temp = new Node;
		temp->data = insert_data;
		temp->next = NULL;

		Node* p1 = head;

		Node* q1 = head->next;
		while (p1 != NULL && p1->data != current_data)
		{
			p1 = p1->next;
		}
		q1= p1->next;
		p1->next = temp;
		temp->next = q1;

		temp = NULL;
		delete temp;
	}
	void mainInsertion(int val)
	{
		Node * temp = new Node;
		temp->data = val;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			Node* p1 = head;
			while (p1->next != NULL)
			{
				p1 = p1->next;
			}
			p1->next = temp;
		}
		temp = NULL;
		delete temp;
	}
	void printList()
	{
		Node* temp = head;
		for (int i = 0; temp != NULL; i++)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	void deletion()
	{
		Node* temp = head;
			head = head->next;
		delete temp;
	}
	void deletionafter()
	{
		Node* before = head, * pres = head;
		while (pres->next != NULL)
		{
			before = pres;
				pres = pres->next;
		}
		before->next = NULL;
		delete pres;
			pres = NULL;
	}
	void valueDeletion(int val)
	{
	
	
		Node* before = head;
		Node* pres = head;
		
		pres= pres->next;
		
			while (pres->data != val && pres->next != NULL)
			{
				before = pres;
				pres = pres->next;

			}
		before->next = pres->next;
		pres = NULL;
		delete pres;

		

	}
	
	
};


int main()
{
	List a;
	int term=3;
	
	cout << "Press enter to stop taking values" << endl;
	while (term !=  1)
	{
		
		cin >> term;
		
		a.mainInsertion(term);

	}
	
	cout << "Deletion from the start" << endl;
	a.deletion();
	a.printList();
	cout << "Deletion from the end" << endl;
	a.deletionafter();
	a.printList();
	
	cout << "Deletion value" << endl;
	a.valueDeletion(6);
	a.printList();
	
	
}
