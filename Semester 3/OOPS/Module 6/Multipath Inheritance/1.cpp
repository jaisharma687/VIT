#include<iostream>

class ClassA {
public:
    int a;
};

class ClassB : public ClassA {
public:
    int b;
};

class ClassC : public ClassA {
public:
    int c;
};

class ClassD : public ClassB, public ClassC {
public:
    int d;
};

int main() {
    ClassD obj;

    obj.ClassB::a = 10;
    obj.ClassC::a = 100;

    obj.b = 20;
    obj.c = 30;
    obj.d = 40;

    std::cout << "a from ClassB: " << obj.ClassB::a << std::endl;
    std::cout << "a from ClassC: " << obj.ClassC::a << std::endl;

    std::cout << "b: " << obj.b << std::endl;
    std::cout << "c: " << obj.c << std::endl;
    std::cout << "d: " << obj.d << std::endl;

    return 0;
}
