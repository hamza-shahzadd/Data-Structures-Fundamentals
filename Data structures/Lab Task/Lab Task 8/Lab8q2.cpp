// 20i-0796
// M.Hamza Shahzad
// q2


#include<iostream>
using namespace std;
class stack
{
    public:
    int *array;
    int top;
    int size;
    stack(int s)
    {
        top=-1;
        size=s;
        array=new int[size];

    }
    bool isempty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        return false;
    }
     bool isfull()
    {
        if(top==size)
        {
            return true;
        }
        else
        return false;
    }
    void push(int data)
    {
        if(isfull())
        {
            return ;
        }
        else
        {
            top++;
            array[top]=data;

        }
    }
    int pop()
    {
        int x=0;
        if(isempty())
        {
            return 1;
        }
        else
        {
            x=array[top];
            top--;
            return x;
            
        }
    }
    int peek()
    {
        return array[top];
    }
    void display()
    {
        int i=0;
        while(i<=top)
        {
            cout<<array[i]<<" ";
            i++;
        }
    }


};
int main()
{
    int a,b;
    cout<<" \nDisplaying elements of the stack ";
    stack s(4);
    s.push(5);
    s.push(9);
    s.push(7);
    s.push(8);
    s.display();
    cout<<"\n\n Peeking first element:  ";
    a=s.peek();
    cout<<a<<endl;
    cout<<" \nPopping all the elements: ";
    cout<<s.pop()<<" "<<s.pop()<<" "<<s.pop()<<" "<<s.pop();




}
