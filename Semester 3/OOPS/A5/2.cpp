#include <iostream>

using namespace std;

template <typename WhatKind>
void multiples(WhatKind& sum, WhatKind x, int n) 
{
    sum = WhatKind(0);
    for (int i = 1; i <= n; ++i) 
    {
        sum += i * x;
    }
}

int main() 
{
    int result_int = 0;
    multiples(result_int, 2, 5);
    cout << "Result (int): " << result_int << endl;

    double result_double = 0.0;
    multiples(result_double, 2.5, 4);
    cout << "Result (double): " << result_double << endl;

    return 0;
}