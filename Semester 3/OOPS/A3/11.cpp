# include <iostream>

using namespace std;

class Employee
{
    private:
        string name;
        int year_of_joining;
        int salary;
        string address;
    public:
        Employee(string n, int yoj, int s, string add):name(n),year_of_joining(yoj),salary(s),address(add){}
        void display()
        {
            cout << "\n" << name << "\t" << year_of_joining << "\t\t\t" << salary << "\t" << address; 
        }
};

int main()
{
    Employee e1("Robert", 1994, 25000, "64D -Walls Street");
    Employee e2("Sam", 2000, 35000, "68D -Walls Street");
    Employee e3("John", 1999, 45000, "26D -Walls Street");
    cout << "Name\tYear of Joining\t\tSalary\tAddress";
    e1.display();
    e2.display();
    e3.display();
    return 0;
}