#include <iostream>
#include <string>
using namespace std;

class person {
protected:
    string name;

public:
    void getdata() {
        cout << "Enter name: ";
        cin >> name;
    }

    void display() {
        cout << "Name: " << name << endl;
    }
};

class employee {
protected:
    int eid;
    string designation;

public:
    void getinfo() {
        cout << "Enter eid and designation: ";
        cin >> eid >> designation;
    }

    void dis() {
        cout << "Eid: " << eid << endl;
        cout << "Designation: " << designation << endl;
    }
};

class teacher : public person, public employee {
    string course_handling;

public:
    void get_teacher_info() {
        person::getdata();
        employee::getinfo();
        cout << "Enter the name of the course handling: ";
        cin >> course_handling;
    }

    void display_teacher_info() {
        person::display();
        employee::dis();
        cout << "Course handling: " << course_handling << endl;
    }
};

int main() {
    teacher e;
    e.get_teacher_info();
    e.display_teacher_info();
    return 0;
}
