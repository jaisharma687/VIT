# include <iostream>

using namespace std;

class complex
{
    private:
        double real, img;
    public:
        complex(){}
        complex(float r, float i):real(r),img(i){}
        void display();
        complex operator +(complex);
        complex operator -(complex);
        complex operator *(complex);
        complex operator /(complex);
};


void complex::display()
{
    cout << real << " + " << img << "i" << endl;
}


complex complex::operator+(complex c)
{
    complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    return temp;
}

complex complex::operator-(complex c)
{
    complex temp;
    temp.real = real - c.real;
    temp.img = img - c.img;
    return temp;
}

complex complex::operator*(complex c)
{
    complex temp;
    temp.real = (real)*(c.real)-(img)*(c.img);
    temp.img = (img)*(c.real)+(real)*(c.img);
    return temp;
}

complex complex::operator/(complex c)
{
    complex temp;
    temp.real = ((real)*(c.real)+(img)*(c.img))/((c.real)*(c.real)+(c.img)*(c.img));
    temp.img = ((img)*(c.real)-(real)*(c.img))/((c.real)*(c.real)+(c.img)*(c.img));
    return temp;
}

int main()
{
    complex C1,C2,C3,C4,C5,C6;
    C1 = complex(8.3,4.7);
    C2 = complex(4.9,3.7);
    C3 = C1+C2;
    cout << "C1 = ";
    C1.display();
    cout << "C2 = ";
    C2.display();
    cout << "C3 = ";
    C3.display();
    C4 = C1-C2;
    cout << "C4 = ";
    C4.display();
    C5 = C1*C2;
    cout << "C5 = ";
    C5.display();
    C6 = C1/C2;
    cout << "C6 = ";
    C6.display();
    return 0;
}