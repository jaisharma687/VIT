# include <iostream>
# include <cmath>

using namespace std;

class Shapes
{
    public:
        Shapes(){}
        void area(int,int,int);//triangle
        void area(int,int);//rectangle
        void area(double);//circle

};

void Shapes::area(int a, int b, int c)
{
    double ar,s;
    s=(a+b+c)/2;
    ar = sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<"Area of triangle is: "<<ar<<endl; 

}

void Shapes::area(int l, int b)
{
    cout<<"Area of rectangle is: "<<l*b<<endl; 
}

void Shapes::area(double r)
{
    cout<<"Area of circle is: "<<3.14*r*r<<endl;  
}

int main()
{
    Shapes S;
    S.area(3,4,5);
    S.area(3,4);
    S.area(3);
    return 0;
}