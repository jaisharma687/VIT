# include <iostream>

using namespace std;

class Student
{
    public:
        string name;
        int roll_no;
        long long int phone_no;
        string address;
};

int main()
{
    Student s1,s2;
    s1.name = "Sam";
    s1.phone_no = 7894561230;
    s1.roll_no = 465;
    s1.address = "Vellore";
    s2.name = "John";
    s2.phone_no = 3021654987;
    s2.roll_no = 789;
    s2.address = "Bengaluru";
    cout << "Student 1 Details:\n";
    cout << "Name: " << s1.name <<"\nRoll Number: " << s1.roll_no << "\nPhone Number: " << s1.phone_no << "\nAddress: " << s1.address;
    cout << "\n\nStudent 2 Details:\n";
    cout << "Name: " << s2.name <<"\nRoll Number: " << s2.roll_no << "\nPhone Number: " << s2.phone_no << "\nAddress: " << s2.address;
    return 0;
}