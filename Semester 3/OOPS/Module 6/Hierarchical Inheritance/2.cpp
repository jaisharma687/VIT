#include <iostream>
using namespace std;

class emp {
protected:
    int eid;
    char ename[20];
};

class permanent_emp : public emp {
private:
    char design[20];
    char depart[20];

public:
    void get_permanent_emp() {
        cout << "Enter eid & name:" << endl;
        cin >> eid >> ename;
        cout << "Designation:" << endl;
        cin >> design;
        cout << "Department:";
        cin >> depart;
    }

    void display_permanent_emp() {
        cout << "Empid: " << eid << endl;
        cout << "Name: " << ename << endl;
        cout << "Designation: " << design << endl;
        cout << "Department: " << depart << endl;
    }
};

class tempemp : public emp {
public:
    int workingday;
    char contractorname[20];
    void get_tempemp() {
        cout << "Enter eid & name:" << endl;
        cin >> eid >> ename;
        cout << "Enter the number of working day: " << endl;
        cin >> workingday;
        cout << "Enter the contractor name: " << endl;
        cin >> contractorname;
    }

    void display_tempemp() {
        cout << "Empid: " << eid << endl;
        cout << "Name: " << ename << endl;
        cout << "Number of working day: " << workingday << endl;
        cout << "Contractor name: " << contractorname << endl;
    }
};

int main() {
    permanent_emp pemp;
    tempemp temp;

    pemp.get_permanent_emp();
    pemp.display_permanent_emp();

    temp.get_tempemp();
    temp.display_tempemp();

    return 0;
}
