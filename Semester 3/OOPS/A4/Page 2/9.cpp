#include <iostream>

using namespace std;

class Palindrome
{
    public:
        void pal(int);
        void pal(string);
};

void Palindrome::pal(int a)
{
    int temp = 0;
    int rem;
    int n = a;
    for (int i = 0; n != 0; i++)
    {
        temp *= 10;
        rem = n % 10;
        temp += rem;
        n /= 10;
    }
    if (a == temp)
    {
        cout << a << " is a Palindrome" << endl;
    }
    else
    {
        cout << a << " is Not a Palindrome" << endl;
    }
}

void Palindrome::pal(string s)
{
    string p = "";
    int n = s.length();
    for (int i = 0; i < s.length(); i++)
    {
        p += s[n - 1];
        n--;
    }
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (p[i] != s[i])
        {
            count++;
            break;
        }
    }
    if (count == 0)
        cout << s << " is a Palindrome" << endl;
    else
        cout << s << " is Not a Palindrome" << endl;
}

int main()
{
    Palindrome P;
    P.pal(12321);
    P.pal("Hello");
    P.pal("viviv");
    P.pal(46531);
    return 0;
}