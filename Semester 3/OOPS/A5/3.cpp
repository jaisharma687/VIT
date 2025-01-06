#include <iostream>

using namespace std;

template <typename T1, typename T2>

T1 init(T1 num1, T1 num2, T2& start) 
{
    start = T2(1);
    return num1 + num2;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    int start_value = 0;
    int result = init(num1, num2, start_value);
    cout << "start_value: " << start_value << endl;
    cout << "result: " << result << endl;
    return 0;
}