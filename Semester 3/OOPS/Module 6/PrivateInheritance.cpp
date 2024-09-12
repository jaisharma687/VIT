#include <iostream>

using namespace std;

class Base {
protected:
    int a;
    int b;
private:
    int c;
};

class Derived : private Base {
public:
    void doSomething() {
        a = 10; // Allowed
        b = 20; // Allowed
        // c = 30; // Not Allowed, Compiler Error, as c is still private in Base
    }
};

class Derived2 : private Derived {
public:
    void doSomethingMore() {
        // a = 10; // Not Allowed, Compiler Error, as a is now protected in Derived
        // b = 20; // Not Allowed, Compiler Error, as b is now protected in Derived
        // c = 30; // Not Allowed, Compiler Error, as c is still private in Base
    }
};

int main() {
    Derived obj;
    // obj.a = 10; // Not Allowed, Compiler Error, as a is protected in Derived
    // obj.b = 20; // Not Allowed, Compiler Error, as b is protected in Derived
    // obj.c = 30; // Not Allowed, Compiler Error, as c is still private in Base
}
