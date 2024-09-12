# include <iostream>

using namespace std;

class complex
{
    private:
        int real;
        int img;
    public:
        complex():real(0),img(0){}
        complex(int r, int i):real(r),img(i){}
        void display();
        complex operator +(complex);
};

void complex::display()
{
    cout<<real<<" + "<<img<<"j"<<endl;
}

complex complex::operator+(complex a)
{
    complex c;
    c.real = real + a.real;
    c.img = img + a.img;
    return c;
}

int main()
{
    complex C1(4,5), C2(5,4),C3;
    C3 = C1+C2;
    C3.display();
    return 0;
}