#include<iostream>

using namespace std;

template <class t>

class one
{
    public:
        one(t c)
        {
        cout<<c<<endl;
        }
};

int main()
{
    one <char>x('a');
    one <int>y(10);
    one <float>z(5.5);
    return 0;
}