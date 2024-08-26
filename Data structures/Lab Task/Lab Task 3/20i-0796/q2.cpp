// M.Hamza Shahzad
// 20i-0796
// Lab Task 3
// Question 2




#include<iostream>
using namespace std;

int main()
{

 int temp;
 
	int arr[6]= {7,12,69,34,22,1};
	
	cout << "Array:" << endl;
	
	for (int i =0 ; i< 6; i++)
	{
		cout << arr[i] << "  ";
	}
	
	cout << endl;
	
	
	for(int j=0; j < 6  ; j++)
	{
		for(int i=0; i < 6; i++)
		{
			if(arr[i] > arr[i+1])
			{
				temp =arr[i+1];
				arr[i+1] = arr[i];
				arr[i]= temp;
			}	
			else if(arr[i] > arr[i+1])
			{
				arr[i]=arr[i];
				arr[i+1]=arr[i+1];
			}
		
		}
	}

	cout << "Array after sorting in ascending order:" << endl;
	for (int i =0 ; i< 6; i++)
	{
		cout << arr[i] << "  ";
	}
	
	cout << endl;
	

	return 0;
}
