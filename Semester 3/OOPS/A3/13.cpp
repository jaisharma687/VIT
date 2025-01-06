# include <iostream>

using namespace std;

class Employee
{
    private:
        string name;
        int salary;
        int workinghours;
    public:
        void getInfo(string n, int hours, int s)
        {
            name = n; 
            salary = s; 
            workinghours = hours;
        }
        void AddSal()
        {
            if(salary<500)
                salary += 10;
        }
        void AddWork()
        {
            if(workinghours>6)
                salary += 5;
        }
        void display()
        {
            cout << "Name : " << name << "\nWorking hours : " << workinghours << " hours \nSalary : $" << salary << "\n";
        }
};

int main()
{
    Employee e1,e2,e3;
    e1.getInfo("Sam",8,500);
    e1.AddSal();
    e1.AddWork();
    e2.getInfo("John",5,475);
    e2.AddSal();
    e2.AddWork();
    e3.getInfo("Robert",5,520);
    e3.AddSal();
    e3.AddWork();
    e1.display();
    e2.display();
    e3.display();
    return 0;
}