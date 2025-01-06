#include <iostream>

using namespace std;

template <class T>
void swapfun(T &n1, T &n2) {
    T temp = n1;
    n1 = n2;
    n2 = temp;
}

int main() {
    int i1, i2;
    float f1, f2;
    char c1, c2;

    cout << "Enter two integers: ";
    cin >> i1 >> i2;
    swapfun(i1, i2);
    cout << "Swapped values are: " << i1 << " & " << i2 << endl;

    cout << "Enter two floats: ";
    cin >> f1 >> f2;
    swapfun(f1, f2);
    cout << "Swapped values are: " << f1 << " & " << f2 << endl;

    cout << "Enter two characters: ";
    cin >> c1 >> c2;
    swapfun(c1, c2);
    cout << "Swapped values are: " << c1 << " & " << c2 << endl;

    return 0;
}
