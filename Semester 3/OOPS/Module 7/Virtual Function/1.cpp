#include <iostream>

using namespace std;

class Base
{
    public:
        int i;
        Base(int x) { i = x; }
        virtual void func()
        {
            cout << "Base class func() " << i << "\n";
        }
};

class Der1 : public Base
{
    public:
        Der1(int x) : Base(x) { }
        void func()
        {
            cout << "Derived class1 func() " << i * i << "\n";
        }
};

class Der2 : public Base
{
    public:
        Der2(int x) : Base(x) { }
        void func()
        {
            cout << "Derived class2 func() " << i + i << "\n";
        }
};

int main()
{
    Base *p;
    Base bob(10);
    Der1 dob1(10);
    Der2 dob2(10);
    p = &bob;
    p->func();
    p = &dob1;
    p->func();
    p = &dob2;
    p->func();
    return 0;
}
