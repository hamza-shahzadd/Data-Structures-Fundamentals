// M.Hamza Shahzad
// 20i-0796
// Lab 04
// TAsk 01


#include <iostream>
using namespace std;

void swap(int*a , int*b);


int main()
{
	int arr[3][3]={7,5,2,1,8,4,9,2,1};

	cout << "The Matrix before sorting is="<< endl;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int a=0, min;
		for (int b = 0; b < 3-1; b++)
		{
			min = b;
			
			for (int k = a + 1; k < 3; k++)
				if (arr[a][k] < arr[a][min])
					min = k;
			swap(&arr[a][min], &arr[a][b]);
		}

		
		
		int max;
		for (int b = 0; b < 3-1; b++)
		{
			max = b;
			for (int k = b + 1; k < 3; k++)
				if (arr[1][k] > arr[1][max])
					max = k;
			swap(&arr[1][max], &arr[1][b]);
		}

		a = 3;

		a = 2;
		int key;
		for (int k = 0; k < 3; k++)
		{
			key = arr[a][k];
			int n = k - 1;
			while (n >= 0 && arr[a][n] > key)
			{
				arr[a][n + 1] = arr[a][n];
				n = n - 1;
			}
			arr[a][n + 1] = key;
		}
		cout << "The Matrix after sorting is="<<endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << arr[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
