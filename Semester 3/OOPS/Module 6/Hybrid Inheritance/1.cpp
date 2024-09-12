#include <iostream>
using namespace std;

class Person {
protected:
    char name[20];
    int age;

public:
    void get();
    void print();
};

void Person::get() {
    cin >> name >> age;
}

void Person::print() {
    cout << "Name: " << name << endl << "Age: " << age << endl;
}

class Student : public Person {
    int rollno;
    int marks;

public:
    void get();
    void print();
};

void Student::get() {
    Person::get();
    cin >> rollno >> marks;
}

void Student::print() {
    Person::print();
    cout << "Roll Number: " << rollno << endl << "Marks: " << marks << endl;
}

class GateScore {
protected:
    int gateScore;

public:
    void get();
    void print();
};

void GateScore::get() {
    cin >> gateScore;
}

void GateScore::print() {
    cout << "Gate Score: " << gateScore << endl;
}

class PGStudent : public Student, public GateScore {
    char deptName[10];

public:
    void get();
    void print();
};

void PGStudent::get() {
    Student::get();
    GateScore::get();
    cin >> deptName;
}

void PGStudent::print() {
    Student::print();
    GateScore::print();
    cout << "Department Name: " << deptName << endl;
}

int main() {
    PGStudent p;
    cout << "Enter PG student details:" << endl;
    p.get();
    cout << "PG Student Details:" << endl;
    p.print();

    return 0;
}
