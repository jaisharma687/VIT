# include <iostream>

using namespace std;

class complex
{
    private:
        float real, img;
    public:
        complex(){}
        complex(float r, float i):real(r),img(i){}
        void display();
        complex operator +(complex);
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

int main()
{
    complex C1,C2,C3;
    C1 = complex(8.3,4.7);
    C2 = complex(4.9,3.7);
    C3 = C1+C2;
    cout << "C1 = ";
    C1.display();
    cout << "C2 = ";
    C2.display();
    cout << "C3 = ";
    C3.display();
    return 0;
}