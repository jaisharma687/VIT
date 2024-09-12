#include <iostream>
using namespace std;

class person
{
protected:
    char name[50];

public:
    void getdata() {
        cout << "Enter name:";
        cin >> name;
    }

    void display() {
        cout << "Name: " << name << endl;
    }
};

class employee : public person
{
protected:
    int eid;
    char designation[30];

public:
    void getinfo() {
        person::getdata();
        cout << "Enter e-id and designation:";
        cin >> eid >> designation;
    }

    void dis() {
        person::display();
        cout << "E-id: " << eid << endl;
        cout << "Designation: " << designation << endl;
    }
};

int main() {
    employee e;
    e.getinfo();
    e.dis();
    return 0;
}
