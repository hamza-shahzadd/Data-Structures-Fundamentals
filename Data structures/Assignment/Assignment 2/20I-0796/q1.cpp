// M.Hamza Shahzad
// 20i-0796
// Data Structures 
// Assignment 2




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


class stack2
{
	public:
	node *head;
	
	stack2()
	{
		head= NULL;
	}
	
	
	bool is_empty()
	{
		if(head == NULL)
		{
			return true;
		}
		else 
		return false;
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
	int peak()
	{
		
		return head->data;
		
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
	
	
	bool is_empty()
	{
		if(head == NULL)
		{
			return true;
		}
		else 
		return false;
	}
	void push(char val)
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
	
	char pop()
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
	char peak()
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
	
	
	bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'|| c == '%' || c=='^' )
	{
		return true;
	}
	else
	{
		return false;
	}
}
	
	int prescedence(char x)
	{
		if(x == '%')
		{
			return 3;
		}
		else if(x == '*' || x == '/' || x == '^')
		{
			return 2;
		}
		else if(x == '+' || x == '-')
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	
	
	char* infix_to_postfix(char *expression,int size,int t)
	{
		int j=0;
		int s= size-t;
		int a=0;
		char *postfix= new char[s];
		
		int count =0;
		
		for(int i=0; i<size;i++)
		{
			if(expression[i] >='0' && expression[i] <='9')
			{
				postfix[j]=expression[i];
				j++;
			}
			else if(expression[i] == '(')
			{
				push(expression[i]);	
			}
			else if(expression[i] == ')')
			{
				while((peak()!='(') && (! is_empty()))
			{
				char temp=peak();
				
				postfix[j]=' ';
				j++;
				a++;
				
				postfix[j]=temp;
				pop();
				j++;
				
				// (120-(65+7-8))
			}
				if(peak()=='(')
			{
				pop();
				
			}
			}
			
			else if(isOperator(expression[i]))
		{
			if(is_empty())
			{
				push(expression[i]);
				postfix[j]=' ';
				j++;
				a++;
				
				
			}
			else
			{
				postfix[j]=' ';
				j++;
				a++;
				
				
				if(prescedence(expression[i])>prescedence(peak()))
				{
					push(expression[i]);
				}	
				else if((prescedence(expression[i])==prescedence(peak()))&&(expression[i]=='^'))
				{
					push(expression[i]);
				}
				else
				{	
					
					
					while((!is_empty())&&( prescedence(expression[i])<=prescedence(peak())))
					{
						
						postfix[j]=peak();
						pop();
						j++;
						
						postfix[j]=' ';
						j++;
						a++;
						
						
					}
					push(expression[i]);
		
				}
			}
		}
	}
	while(! is_empty())
	{
		postfix[j] = ' ';
		j++;
		a++;
		postfix[j]= peak();
		pop();
		j++;
		
		
		
	}
	
	
	
	cout << "Infix expression is = " << expression << endl;
	cout<< "The postfix expression is = " ; 
	
	
	s=s+a;
	
	
	for(int w=0;w<s; w++)
	{
		cout << postfix[w];
	}
		cout << endl;	
		return postfix;
	}


	void infix_to_prefix(char *infix,int s,int tt)
	{
	
		char reverse[s];
		int k= s-1;
		int j=0;
		int a=0;
		
		for(int i=0; i < s; i++)
		{
			reverse[i]= infix[k];
			
			k--;
			
		}
		
		
		for(int b=0; b<s; b++)
		{
			if(reverse[b] == '(')
			{
				reverse[b]= ')';
			}
			
			else if(reverse[b] ==')')
			{
				reverse[b]= '(';
			}
		}
		
		
		
		
		char prefix[s];
		////////////
		
		for(int i=0; i<s;i++)
		{
			if(reverse[i] >='0' && reverse[i] <='9')
			{
				prefix[j]=reverse[i];
				j++;
			}
			else if(reverse[i] == '(')
			{
				push(reverse[i]);	
			}
			else if(reverse[i] == ')')
			{
				while((peak()!='(') && (! is_empty()))
			{
				char temp=peak();
				
				prefix[j]=' ';
				j++;
				a++;
				
				prefix[j]=temp;
				pop();
				j++;
				
				// (120-(65+7-8))
			}
				if(peak()=='(')
			{
				pop();
				
			}
			}
			
			else if(isOperator(reverse[i]))
		{
			if(is_empty())
			{
				push(reverse[i]);
				prefix[j]=' ';
				j++;
				a++;
				
				
			}
			else
			{
				prefix[j]=' ';
				j++;
				a++;
				
				
				if(prescedence(reverse[i])>prescedence(peak()))
				{
					push(reverse[i]);
				}	
				else if((prescedence(reverse[i])==prescedence(peak()))&&(reverse[i]=='^'))
				{
					push(reverse[i]);
				}
				else
				{	
					
					
					while((!is_empty())&&( prescedence(reverse[i])<=prescedence(peak())))
					{
						
						prefix[j]=peak();
						pop();
						j++;
						
						prefix[j]=' ';
						j++;
						a++;
						
						
					}
					push(reverse[i]);
		
				}
			}
		}
	}
	while(! is_empty())
	{
		prefix[j] = ' ';
		j++;
		a++;
		prefix[j]= peak();
		pop();
		j++;
		
		
		
	}
	
	
	
	cout << "Infix expression is = " << infix << endl;
	cout<< "The prefix expression is = " ; 
	s=s+a;
	s=s-tt;
	
	char tem[s];
	int y=s-1;
	
	
	for(int b=0; b < s; b++)
	{
		tem[b]= prefix[y];
		y--; 
	}
	
	for(int i=0; i< s ; i++)
	{
		cout << tem[i];
	}

		cout << endl;
		
		
	}
	
	////////////////////////////////////////////////////////////////////////////////////
		
	
};


//////////////////////////////////////////////////////////

int Solving_PostfixExpression(string expression, stack2 *values)
{
	int value = 0;
	int op1, op2;
	stack2 post;
	int index = 0;
	
	while (expression[index] != '\0')
		{
		
		if(expression[index] != ' ')
		{
			if (expression[index] != '+' && expression[index] != '-' && expression[index] != '*' && expression[index] != '/' && expression[index] != '%' && expression[index] != '^' )
			{
				post.push(values->pop());
				while (expression[index] != ' ')
					index++;
					
			}
			else
			{
				switch (expression[index])
				{	
						case '+':
						op1 = post.pop();
						op2 = post.pop();
						post.push(op2 + op1);
						break;
						case '-':
						op1 = post.pop();
						op2 = post.pop();
						post.push(op1 - op2);
						break;
						case '*':
						op1 = post.pop();
						op2 = post.pop();
						post.push(op2 * op1);
						break;
						case '/':
						op1 = post.pop();
						op2 = post.pop();
						post.push(op2 / op1);
						break;
						case '%':
						op1 = post.peak();
						post.pop();
						op2 = post.peak();
						post.pop();
						post.push(op2 % op1);
						break;
						case '^':
						op1 = post.peak();
						post.pop();
						op2 = post.peak();
						post.pop();
						for(int i=1; i< op2; i++)
						{
							op1*=op1;
						}
						post.push(op1);
						break;
					}
			}		
	}
index++;
}
value = post.pop();
cout << "Answer after Evaluation = " << value << endl;
return value;
}


///////////////////////////////////////////////////////





int main()
{

	
	char arr[100];
	bool status= true;
	bool empty;
	int count=0;
	//int tb= 0;
	int total=0;
	int open=0;
	int close=0;
	int bracket=0;
	int j=0;
	
	
	stack v;
	
	cout << "Enter any expression. " << endl;
	cin >> arr;
	
	for(int i=0; arr[i] != '\0'; i++)                           // to find length of the expression;
	{
		count++;
	}
	
	
	
	for( int i=0; arr[i] != '\0'; i++)
	{
		if(arr[i] == '(' || arr[i] == ')' || arr[i] == '+' || arr[i] == '-' || arr[i] == '*'|| arr[i] == '/' || arr[i] == '^'|| arr[i] == '%' || arr[i] > '0' && arr[i] <='9' )
		{
		 	status = true;
		}
	/*	else
		{
			status=false;
			break;
		}
	*/	
		if(arr[i] == '+' && arr[i+1] == '+' || arr[i] == '+' && arr[i+1] == '-' || arr[i] == '+' && arr[i+1] == '*' || arr[i] == '+' && arr[i+1] == '/' || arr[i] == '+' && arr[i+1] == 			'^' || arr[i] == '+' && arr[i+1] == '%' )
		{
			status=false;
			break;
		}
		if(arr[i] == '-' && arr[i+1] == '+' || arr[i] == '-' && arr[i+1] == '-' || arr[i] == '-' && arr[i+1] == '*' || arr[i] == '-' && arr[i+1] == '/' || arr[i] == '-' && arr[i+1] == 			'^' || arr[i] == '-' && arr[i+1] == '%' )
		{
			status = false;
			break;
		}
		if(arr[i] == '*' && arr[i+1] == '+' || arr[i] == '*' && arr[i+1] == '-' || arr[i] == '*' && arr[i+1] == '*' || arr[i] == '*' && arr[i+1] == '/' || arr[i] == '*' && arr[i+1] == 			'^' || arr[i] == '*' && arr[i+1] == '%' )
		{
			status = false;
			break;
		}
		if(arr[i] == '/' && arr[i+1] == '+' || arr[i] == '/' && arr[i+1] == '-' || arr[i] == '/' && arr[i+1] == '*' || arr[i] == '/' && arr[i+1] == '/' || arr[i] == '/' && arr[i+1] == 			'^' || arr[i] == '/' && arr[i+1] == '%' )
		{
			status = false;
			break;
		}
		if(arr[i] == '%' && arr[i+1] == '+' || arr[i] == '%' && arr[i+1] == '-' || arr[i] == '%' && arr[i+1] == '*' || arr[i] == '%' && arr[i+1] == '/' || arr[i] == '%' && arr[i+1] == 			'^' || arr[i] == '%' && arr[i+1] == '%' )
		{
			status = false;
			break;
		}
		if(arr[i] == '^' && arr[i+1] == '+' || arr[i] == '^' && arr[i+1] == '-' || arr[i] == '^' && arr[i+1] == '*' || arr[i] == '^' && arr[i+1] == '/' || arr[i] == '^' && arr[i+1] == 			'^' || arr[i] == '^' && arr[i+1] == '%' )
		{
			status = false;
			break;
		}
		if(arr[count - 1] == '+' || arr[count - 1] == '-' || arr[count - 1] == '*' || arr[count - 1] == '/' || arr[count - 1] == '%' || arr[count - 1] == '^')
		{
			status=false;
			break;
		}
		
	}
	
		if(arr[0]== '*' || arr[0] == '/' || arr[0] == '%' || arr[0] == '^')
			{
				status=false;
		
			}
		
		// Condition for the ordering of brackets
		
		while(arr[j] != '\0')
		{
			if(arr[j] == '(')
			{
				bracket++;
				open++;
				
			}
			else if(arr[j] == ')')
			{
				bracket--;
				close++;
			}
			
			if(j<0)
			{
				status=false;
				
				break;
			}
			j++;
			
		}
		
		total=open+close;
		
		
		if(bracket != 0)
		{
			status=false;
			
		}
		
		
		// Condition of ) in the beginning????
		
		
		
		//cout << status << endl;
		if(status == 1)
		{
			cout << "Valid expression" << endl;
			
			// Infix to postfix call	

		stack post;
		
		char * pfix;
		pfix= post.infix_to_postfix(arr,count,total);
		
		
		
// Infix to prefix call

        	stack pre;
        	
        	pre.infix_to_prefix(arr,count,total);

// evaluate postfix expression
int q=0;
stack temp;
stack2 values;
int tempresult = 0;
	while(pfix[q] != '\0')
	{
		if(pfix[q] >= '0' && pfix[q] <= '9')
		{
			temp.push(pfix[q] - 48);
		}
		else
		{
			
			if (!temp.is_empty())
			{
				int i = 1;
				tempresult = 0;
				while(!temp.is_empty())
				{
					tempresult += i * temp.pop();
					i *= 10;
				}
				//cout << "HI" << tempresult <<endl;
				values.push(tempresult);
			}
		}
		
		if(pfix[q] != '\0')
		q++;
	
	}
	
	stack eval;
	int tempans = Solving_PostfixExpression(pfix, &values);
	//cout << pfix <<endl;
	
			
		}
		else
		{
			cout << "Invalid expression" << endl;
		}
		
		
		
////////////////////////////////////////////////////////////////////////


	return 0;

}






