// M.Hamza Shahzad
// 20i-0796
// Lab 03
// Question 1





#include<iostream>
using namespace std;




int main()
{

char arr[6]={'a','B', 'c','Y','y','z'};
int small=0;
int cap=5;

	
	for(int i=0; i<6; i++)
	{
		if(arr[i] >= 'a' && arr[i] <='z')
		{
			arr[small]=arr[i];
			small = small + 1;	
		}
	
		else if(arr[i] >= 'A' && arr[i] <='Z')
		{
			arr[cap]=arr[i];
			cap = cap - 1;
		}
	}


	for(int i=0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << endl;
//	cout << cap << endl;
//	cout << small << endl;

return 0;
}
