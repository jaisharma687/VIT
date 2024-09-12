#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int code;

public:
    Person(const std::string& name, int code) : name(name), code(code) {}

    void display() {
        std::cout << "Name: " << name << ", Code: " << code << std::endl;
    }
};

class Account : public Person {
protected:
    double pay;

public:
    Account(const std::string& name, int code, double pay) : Person(name, code), pay(pay) {}

    void display() {
        Person::display();
        std::cout << "Pay: " << pay << std::endl;
    }
};

class Admin : public Person {
protected:
    int experience;

public:
    Admin(const std::string& name, int code, int experience) : Person(name, code), experience(experience) {}

    void display() {
        Person::display();
        std::cout << "Experience: " << experience << " years" << std::endl;
    }
};

class Master : public Account, public Admin {
public:
    Master(const std::string& name, int code, double pay, int experience)
        : Account(name, code, pay), Admin(name, code, experience) {}

    void display() {
        std::cout << "Master Information" << std::endl;
        Account::display();
        Admin::display();
    }
};

int main() {
    std::string name;
    int code, experience;
    double pay;

    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter code: ";
    std::cin >> code;
    std::cout << "Enter pay: ";
    std::cin >> pay;
    std::cout << "Enter experience: ";
    std::cin >> experience;

    Master employee(name, code, pay, experience);
    employee.display();

    return 0;
}
