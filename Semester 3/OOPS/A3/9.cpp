# include <iostream>

using namespace std;

class Complex
{
    int r1,r2,i1,i2;
    public:
    Complex(int real1,int img1,int real2,int img2)
    {
        r1 = real1;
        r2 = real2;
        i1 = img1;
        i2 = img2;
    }
    void sum()
    {
        int r3 = r1+r2;
        int i3 = i1+i2;
        cout << "The sum of complex " << r1 << " + " << i1 << "i and " << r2 << " + " << i2 << "i is\n" << r3 << " + " << i3 <<"i";
    }
    void diff()
    {
        int r3 = r1-r2;
        int i3 = i1-i2;
        cout << "\nThe difference of complex " << r1 << " + " << i1 << "i and " << r2 << " + " << i2 << "i is\n" << r3 << " + " << i3 <<"i";
    }
    void pdt()
    {
        int r3 = r1*r2 - i1*i2;
        int i3 = i1*r2+ i2*r1;
        cout << "\nThe product of complex " << r1 << " + " << i1 << "i and " << r2 << " + " << i2 << "i is\n" << r3 << " + " << i3 <<"i";
    }
};

int main()
{
    int real1, real2,img1,img2;
    cout << "Enter the first complex number:\n";
    cin >> real1 >> img1;
    cout << "Enter the second complex number:\n";
    cin >> real2 >> img2;
    Complex comp(real1,img1,real2,img2);
    comp.sum();
    comp.diff();
    comp.pdt();
    return 0;
}