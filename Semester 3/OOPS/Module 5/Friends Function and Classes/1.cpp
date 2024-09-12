#include <iostream>

using namespace std;

class Demo {
    friend void Change(Demo& obj);

public:
    Demo(double x0 = 0.0, int y0 = 0.0) : x(x0), y(y0) {}
    void print();

private:
    double x;
    int y;
};

void Demo::print() {
    cout << "This is x " << x << endl;
    cout << "This is y " << y << endl;
}

void Change(Demo& obj) {
    obj.x += 100;
    obj.y += 200;
    cout << "This is obj.x " << obj.x << endl;
    cout << "This is obj.y " << obj.y << endl;
}

int main() {
    double x_input;
    int y_input;

    cout << "Enter a value for x: ";
    cin >> x_input;
    cout << "Enter a value for y: ";
    cin >> y_input;

    Demo obj(x_input, y_input);
    obj.print();

    Change(obj);

    return 0;
}
