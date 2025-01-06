# include <iostream>

using namespace std;

void area(int x)
{
    cout<<"area is: "<< x*x<<endl;
}

void area(int x, int y)
{
    cout<<"area of rectangle is: "<< x*y<<endl;
}

void area(int x, int y, int z)
{
    cout<<"volume is: "<< x*y*z<<endl;
}

int main()
{
    int side=10,le=5,br=6,a=4,b=5,c=6;
    area(side);
    area(le,br);
    area(a,b,c);
}