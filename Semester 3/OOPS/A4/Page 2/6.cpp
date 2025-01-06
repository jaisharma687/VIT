# include <iostream>

using namespace std;

class Rational
{
    private:
        int num,deno;
    public:
        Rational(){}
        Rational(int n, int d):num(n),deno(d){}
        Rational operator +(Rational);
        Rational operator -(Rational);
        Rational operator *(Rational);
        Rational operator /(Rational);
        void display()
        {
            cout<<"Rational number is: "<<num<<"/"<<deno<<endl;
        }
};

Rational Rational::operator+(Rational r)
{
    Rational temp;
    temp.num = num*(r.deno)+deno*(r.num);
    temp.deno = deno*(r.deno);
    return temp;
}

Rational Rational::operator-(Rational r)
{
    Rational temp;
    temp.num = num*(r.deno)-deno*(r.num);
    temp.deno = deno*(r.deno);
    return temp;
}

Rational Rational::operator*(Rational r)
{
    Rational temp;
    temp.num = num*(r.num);
    temp.deno = deno*(r.deno);
    return temp;
}

Rational Rational::operator/(Rational r)
{
    Rational temp;
    temp.num = num*(r.deno);
    temp.deno = deno*(r.num);
    return temp;
}

int main()
{
    Rational r1,r2,r3,r4,r5,r6;
    r1 = Rational(5,7);
    r2 = Rational(4,3);
    r1.display();
    r2.display();
    r3 = r1+r2;
    r4 = r1-r2;
    r5 = r1*r2;
    r6 = r1/r2;
    r3.display();
    r4.display();
    r5.display();
    r6.display();
    return 0;
}