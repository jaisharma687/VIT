#include <iostream>

using namespace std;

class base
{
public:
    int i;
    base(int x) { i = x; }
    virtual void func()
    {
        cout << "Base class func() :\n";
    }
};

class der1 : public base
{
public:
    der1(int x) : base(x) {}
    void func() override
    {
        cout << "Derived class1 func() :\n";
    }
};

class der2 : public der1
{
public:
    der2(int x) : der1(x) {}
    void initx()
    {
        int x = 15;
        cout << "The value of x: " << x << "\n";
    }
};

int main()
{
    base *p;
    base bob(5);
    der1 dob1(10);
    der2 dob2(20);
    p = &bob;
    p->func();
    p = &dob1;
    p->func();
    p = &dob2;
    p->func();
    dob2.initx();
    return 0;
}
