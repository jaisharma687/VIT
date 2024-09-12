# include <iostream>

using namespace std;

template<class t>

t large(t n1, t n2)
{
    return (n1>n2)?n1:n2;
}

int main()
{
    int i1, i2;
    float f1,f2;
    char c1,c2;
    i1 = 15; i2 = 45;
    f1 = 2.65 ; f2 = 0.256;
    c1 = 'a' ; c2 = 'A';
    cout<<large(i1,i2)<<endl;
    cout<<large(f1,f2)<<endl;
    cout<<large(c1,c2)<<endl;
    return 0;
}