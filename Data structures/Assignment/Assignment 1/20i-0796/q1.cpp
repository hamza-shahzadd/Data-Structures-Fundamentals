// M.Hamza Shahzad
// 20i-0796
// Data Structures Assignment # 1
// Question 1



#include<iostream>
#include<cmath>
using namespace std;

class term
{
	public:
	
	int exponent;
	int coefficient;
	term *next;
	
	term()
	{
		next=NULL;
	}

};

class polynomial
{
	public:
	
	term *head;

	polynomial()
	{
		head=NULL;
	}
	
	
	void Input( term* newTerm, int e, int c)
	{
		if(head == NULL)
		{
			head= newTerm;
			head->exponent= e;
			head->coefficient=c;
		}
		else
		{
			term* temp=head;
			
			while( temp->next != NULL)
			{
				temp=temp->next;
				
			}
			temp->next=newTerm;
			newTerm->exponent=e;
			newTerm->coefficient=c;
			
			
		}	
		
		}
		
	void sorting(int size)
	{
	
	if(head== NULL)
	{
		return;
	}
	else
	{
		term *i,*j;
		i=head;
		int swap;
		for(i=head; i->next != NULL; i=i->next)
		{
			for(j=i->next;j!=NULL;j=j->next)
			{
				if(i->exponent < j->exponent)
				{
					swap=i->exponent;
					i->exponent=j->exponent;
					j->exponent= swap;
					
					swap=i->coefficient;
					i->coefficient=j->coefficient;
					j->coefficient= swap;
				}
			}
		}	
	
	
	
	}	
	}	
	void display_input()
	{
		if(head == NULL)
		{
			return;
		}	
		else
		{
			term *t=head;
			while(t->next != NULL)
			{
				cout << t->coefficient << "n^";
				cout << t->exponent;
				cout << " + ";
				t=t->next;
			}
			
			cout << t->coefficient << "n^";
			cout << t->exponent;
			
			cout << endl;
		}
	}	
	void multiply(term *x,int s1,int s2)
	{
		term *y=NULL;
		y=head;
		int diff=0;
		
		
		if(x == NULL || y == NULL)
		{
			return ;
		}
		else
		{
			
			term *mulhead = new term;
			term *mul=mulhead;
		
			{
				while(x && y )
				{
				
					mul->coefficient=x->coefficient * y->coefficient;
					mul->exponent= x->exponent * y->exponent;
					x=x->next;
					y=y->next;
				
					mul->next=new term;
					mul=mul->next;
					mul->next=NULL;
				}
			
			cout << "Resultant polynomial after multiplication:" << endl;
			term *w = mulhead;
			while(w->next->next != NULL)
			{
				cout << w->coefficient << "n^";
				cout << w->exponent;
				cout << " + ";
				w=w->next;
			}
			
			cout << w->coefficient << "n^";
			cout << w->exponent;
			
			cout << endl;
				
			}
			
		}
	
	}	
				
				
	
	
	void add( term* two)
	{
		
		term *one=NULL;
		one=head;
		
		
		
		if(one == NULL && two ==NULL)
		{
			return;
		}
		
		else
		{
			term *resulthead= new term;
			term *result=resulthead;
			while(one && two)
			{
				if(one->exponent == two->exponent)
				{
					result->coefficient= one->coefficient + two->coefficient;
					result->exponent=one->exponent;
					one=one->next;
					two=two->next;
				}
				else if(one->exponent > two->exponent)
				{
					result->coefficient= one->coefficient;
					result->exponent= one->exponent;
					one=one->next;
				}
				else if(one->exponent < two->exponent)
				{
					result->coefficient= two->coefficient;
					result->exponent= two->exponent;
					two=two->next;
				}
				result->next=new term;
				result=result->next;
				result->next=NULL;
			}
				cout << "Resultant polynomial after addition:" << endl;
				term *z=resulthead;
				
				while(z->next->next != NULL)
			{
				cout << z->coefficient << "n^";
				cout << z->exponent;
				cout << " + ";
				z=z->next;
			}
			
			cout << z->coefficient << "n^";
			cout << z->exponent;
			
			cout << endl;
	
	
			
			
		}
		
	}
	int evaulate(int num)
	{
		int result=0;
		
		if(head==NULL)
		{
			return 0;
		}
		else
		{
		term *a= head;
			while(a != NULL)
			{
				result= result + (a->coefficient *(pow(num,a->exponent)));
				a=a->next; 
			}
		}
		return result;
	}
	
};


int main()
{
	int num1,num2, expo, coe,e,evaluate,choice,a=1;
	
	while(a != 0)
	{
	
	cout << "**********WELCOME TO THE POLYNOMIAL CALCULATOR**********" << endl << endl;
	
	term t;
	polynomial p;
	
	
	cout << "Please Enter the number of terms for the first polynomial " << endl;
	cin >> num1;
	
	
	for(int i=0; i< num1; i++)
	{
		cout <<"Please Enter the coefficient for "<<i+1 << " term" << endl;
		cin >> coe;
		cout << "Please Enter the exponent for " << i+1 << " term" << endl;
		cin >> expo;
		term *newNode= new term;
		p.Input(newNode, expo,  coe);
			  
	}
	cout << "First Polynomial after sorting:"<< endl;
	p.sorting(num1);
	p.display_input();
	
	cout << "Please Enter the number of terms for the second polynomial " << endl;
	cin >> num2;
	
	polynomial p2;
	
	for(int i=0; i< num2; i++)
	{
		cout <<"Please Enter the coefficient for "<<i+1 << " term" << endl;
		cin >> coe;
		cout << "Please Enter the exponent for " << i+1 << " term" << endl;
		cin >> expo;
		term *newNode= new term;
		p2.Input(newNode, expo,  coe);
			  
	}
	cout << "second Polynomial after sorting:"<< endl;
	p2.sorting(num2);
	p2.display_input();
	
	cout << endl;
	cout << "Enter 1 for addition" << endl << "Enter 2 for multiplication" << endl << "Enter 3 for evaluation" << endl;
	cin >> choice;
	
	if(choice == 1)
	{
		p.add(p2.head);
	}
	else if(choice == 2)
	{
		p.multiply(p2.head,num1,num2);
	}
	else if(choice == 3)
	{
		cout << "Enter number to evaluate the polynomial" << endl;
		cin >> e;
		evaluate=p.evaulate(e);
		cout << "After evaluating first polynoimal = " << evaluate << endl;
	
		evaluate=p2.evaulate(e);
		cout << "After evaluating second polynoimal = " << evaluate << endl;
	}
	
	cout << "Press 0 to exit and 1 to repeat " << endl;
	cin>> a;
	}
	

	
	
	
	
	return 0;
}



