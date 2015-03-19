#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

class sincurve
{
    float a, b, i;
    public:
    void sinconvert();
    sincurve()
    {
        cout<<"\nEnter the starting and ending value of the curve: \n";
        cin>>a>>b;
    }

    ~sincurve()
    {
        cout<<"\nDestroying object at the end of the program";
    }
};

void sincurve::sinconvert()
{
    a=a*(3.14/180);
    b=b*(3.14/180);
    for(i=a;i<b;i+=0.1)
    {
        cout<<"*"<<setw(i);
    }
}

int main(void)
{
    sincurve *ob=new sincurve();
    return 0;
}
