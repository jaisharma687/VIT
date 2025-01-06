#include <iostream>
#include <cstdlib>
#include <iomanip>

class base {
public:
    int i;
    base(int x) : i(x) {}

    virtual void func() {
        std::cout << "Base class func() " << i << "\n";
    }
};

class der1 : public base {
public:
    der1(int x) : base(x) {}

    void func() {
        std::cout << "Derived class1 func() " << i * i << "\n";
    }
};

class der2 : public base {
public:
    der2(int x) : base(x) {}

    void func() {
        std::cout << "Derived class2 func() " << i + i << "\n";
    }
};

int main() {
    int i, j;
    base* p;
    der1 dob1(10);
    der2 dob2(10);

    for (i = 0; i < 4; i++) {
        j = std::rand() / 7;
        std::cout << std::setw(10) << j << "  ";
        if (j % 2)
            p = &dob1;
        else
            p = &dob2;
        p->func();
    }

    return 0;
}
