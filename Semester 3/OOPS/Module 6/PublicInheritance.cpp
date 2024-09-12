#include <iostream>

using namespace std;

class Base {
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Derived : public Base {
public:
    void doSomething() {
        a = 10; // Allowed
        b = 20; // Allowed
        // c = 30; // Not Allowed, Compiler Error
    }
};

int main() {
    Derived obj;
    obj.a = 10; // Allowed
    // obj.b = 20; // Not Allowed, Compiler Error
    // obj.c = 30; // Not Allowed, Compiler Error
}
