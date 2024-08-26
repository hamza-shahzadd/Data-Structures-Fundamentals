/// M.Hamza Shahzad
/// 20i-0796
/// Data structures Lab-2
/// Task 1

#include<iostream>
using namespace std;
template <typename a, typename b>


b add(a para1, a para2, b para3, b para4)
{
	b result;
	result= para1+ para2+ para3 + para4;
	return result;

}




int  main()
{
	
	cout << add(2, 3, 6.3, 12.12) << endl;
	cout << add(3.14, 2.31, 4, 6) << endl;
	cout << add(3.11, 4.2, 9,6) << endl;
	cout << add(2.11, 4.31, 6, 9) << endl;


	
	return 0;
}

