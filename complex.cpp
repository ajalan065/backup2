#include<iostream>
#include<math.h>
using namespace std;
class complex
{
	
	public:
int a, b;
	void add(complex ob1, complex ob2);
	void tangent(complex ob);
};

void complex::add(complex a, complex b)
{
	int c, d;
	c=a.a+b.a;
	d=a.b+b.b;
	cout<<"\nThe number is:"<<c<<"+"<<d<<"i"<<endl;
}

void complex::tangent(complex ob)
{
	float d;
	float c=sqrt(pow(ob.a,2)+pow(ob.b,2));
	cout<<c;
	d=(ob.b/ob.a);
	cout<<"\nThe value of tan(b/a) is :"<<d;
}
int main(void)
{
	int ch;
	char c;
	complex ob1, ob2, ob;	
	do
	{
		cout<<"\nEnter 1. Add	2. Modulus and Argument";
	cin>>ch;
	switch(ch)
	{
		
		case 1:
		cout<<"\nThe real and imaginary part of first number is :";
		cin>>ob1.a>>ob1.b;
		cout<<"\nThe real and imaginary part of second number is :";
		cin>>ob2.a>>ob2.b;
		ob.add(ob1,ob2);
		break;
		case 2:
		cout<<"\nEnter the real and imaginary part of the number:";
		cin>>ob1.a>>ob1.b;
		cout<<"\nThe modulus and argument of the number is:";
		ob.tangent(ob1);.
		break;
		case 3:
	}
	cout<<"\nWant to perform again??";
	cin>>c;
	}while(tolower(c)=='y');
}
