// 20i-0796
// M.Hamza Shahzad
// q1

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

};
int main()
{
    stack s(4);

}
