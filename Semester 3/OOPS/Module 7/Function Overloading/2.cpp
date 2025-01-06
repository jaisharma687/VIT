# include <iostream>

using namespace std;

void sum(int x, int y)
{
    cout<<"Sum of integers is: "<< x+y<<endl;
}

void sum(double x, double y)
{
    cout<<"Sum of floats is: "<< x+y<<endl;
}

void sum(char x, char y)
{
    cout<<"Sum of characters is: "<< x+y<<endl;
}

int main()
{
    int a=10,b=20;
    double c=7.52,d=8.14;
    char e='a', f='b';
    sum(a,b);
    sum(c,d);
    sum(e,f);
}