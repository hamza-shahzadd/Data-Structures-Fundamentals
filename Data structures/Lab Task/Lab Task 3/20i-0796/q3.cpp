// M.Hamza Shahzad
// 20i-0796
// Lab 03
// question 3



#include<iostream>
using namespace std;


int main()
{

int golden =0;
float answer;


	float arr[3][2]={1.2,0.8, 4.8,1.55,6.1,6.9};
	
	for(int i=0;i<3; i++)
	{
		for(int j=0; j<2; j++)
		{
			cout << arr[i][j] << "    ";
			
		}
		
		cout << endl;
		
	}
	
	for(int i=0; i<3; i++)
	{
		cout << arr[i][0] << " " <<  arr[i][1] << endl;
		answer= (arr[i][0] + arr[i][1]) / arr[i][0];
		if(answer >= 1.6 && answer <=1.7)
		{
			golden= golden +1;
		}
	}
	
	
	cout << "The number of golden rectangles are = " << golden << endl;
	
	
	



	return 0;
}

