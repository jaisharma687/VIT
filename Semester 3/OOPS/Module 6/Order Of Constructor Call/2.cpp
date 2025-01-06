#include <iostream>

using namespace std;

class Base {
    int x;

public:
    Base(int i) {
        x = i;
        cout << "Base Parameterized Constructor" << endl;
    }
};

class Derived : public Base {
    int y;

public:
    Derived(int j) : Base(j) {
        y = j;
        cout << "Derived Parameterized Constructor";
    }
};

int main() {
    Derived d(10);
    return 0;
}
