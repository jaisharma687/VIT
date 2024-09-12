#include <iostream>

using namespace std;

class Complex 
{
    private:
        double real;
        double imaginary;
    public:
        Complex(){}
        Complex(double r, double i) : real(r), imaginary(i) {}
        Complex operator+(Complex);
        Complex operator++();
        Complex operator++(int);
        void print();
};

Complex Complex::operator+(Complex c)
{
    Complex temp;
    temp.real = real + c.real;
    temp.imaginary = imaginary + c.imaginary;
    return temp;
}

Complex Complex::operator++() 
{
    real++;
    imaginary++;
    return *this;
}

Complex Complex::operator++(int) 
{
    Complex temp(*this);
    real++;
    imaginary++;
    return temp;
}

void Complex::print()
{
    cout << real << " + " << imaginary << "i" << endl;
}

int main() 
{
    Complex A(3, 4), B(5, 6);
    A.print();
    B.print();
    Complex C = A + B;
    C.print();
    ++A;
    A.print();
    Complex D = A++;
    D.print();
    A.print();
    return 0;
}
