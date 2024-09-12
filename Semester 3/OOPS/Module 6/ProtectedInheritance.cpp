#include <iostream>

using namespace std;

class Base {
protected:
    int a;
    int b;
private:
    int c;
};

class Derived : protected Base {
public:
    void doSomething() {
        a = 10; // Allowed
        b = 20; // Allowed
        // c = 30; // Not Allowed, Compiler Error, as c is private in Base
    }
};

class Derived2 : public Derived {
public:
    void doSomethingMore() {
        a = 10; // Allowed, a is now protected member inside Derived2
        b = 20; // Allowed, b is now protected member inside Derived2
        // c = 30; // Not Allowed, Compiler Error, as c is private in Base
    }
};

int main() {
    Derived2 d2;
    d2.doSomethingMore(); // You can call the public member function in Derived2
    // d2.a = 10; // Not Allowed, a is protected in Derived2
    // d2.b = 20; // Not Allowed, b is protected in Derived2
    // d2.c = 30; // Not Allowed, c is private in Base
    return 0;
}
