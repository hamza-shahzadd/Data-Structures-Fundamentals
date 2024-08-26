/// M.Hamza Shahzad
/// 20i-0796
/// Data structures Lab-2
/// Task 2

#include<iostream>
using namespace std;
template <typename a, typename b, typename c>



class hint
{
 a x1;
 b x2;
 c x3;
 
 
 public:
 hint(a first, b second, c third)
 {
 	x1= first;
 	x2=second;
 	x3=third;
 
 }
 
 void display()
 {
 	cout << x1 << " " << x2 << " "<< x3 << endl;
 
 }




};


int main()
{

int l=64;
double m=3.1;
float n=4.7;
	hint <int , float, double>obj1(l, m, n);
	obj1.display();

	hint <float, int , double> obj2(20.111, 3, 2.12);
	obj2.display();
	
	hint <int,  double, float> obj3(20, 3.1, 18.71);
	obj3.display();
	return 0;
}
