// M.Hamza Shahzad
// 20i-0796
// Data Structure Lab 1




#include<iostream>
#include<cstring>
using namespace std;


class Patient
{
	public:
	
	string name;
	
	
	Patient()
	{
		name="";
	}
	Patient(string n)
	{
		name=n;
	}
};


class Hospital: public Patient 
{


public:
	int medication_charges;
	//Patient obpatient;
	
	
	Hospital(int x)
	//: obpatient(a)
	{
		medication_charges=x;
	}
	
	
	void display()
	{
		cout << "Name " << name << endl;
	}
	
	void display1()
	{
		cout << "Medication charges = " << medication_charges << endl;

	}


};





























int main()
{
	//Patient p1("ABC");
	Hospital h1(1200);
	
	
	


return 0;
}

