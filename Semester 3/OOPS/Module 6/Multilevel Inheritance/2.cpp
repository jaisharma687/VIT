#include <iostream>

using namespace std;

class person {
protected:
    char name[50];

public:
    void getdata() {
        cout << "Enter name: ";
        cin >> name;
    }

    void display() {
        cout << "Name: " << name << endl;
    }
};

class employee : public person {
protected:
    int eid;
    char designation[30];

public:
    void getinfo();
    void dis();
};

class parttime_employee : public employee {
private:
    int no_of_hours_worked;

public:
    void get_parttime_employee() {
        employee::getinfo();
        cout << "Enter the no-of-hours-worked: ";
        cin >> no_of_hours_worked;
    }

    void info_parttime_employee() {
        employee::dis();
        cout << "Number of hours worked: " << no_of_hours_worked;
    }
};

void employee::getinfo() {
    person::getdata();
    cout << "Enter eid and designation: ";
    cin >> eid >> designation;
}

void employee::dis() {
    person::display();
    cout << "Eid = " << eid << endl;
    cout << "Designation = " << designation << endl;
}

int main() {
    parttime_employee e;
    e.get_parttime_employee();
    e.info_parttime_employee();

    return 0;
}
