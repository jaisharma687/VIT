#include<iostream>

using namespace std;

template <class t>

class add
{
    private:
        t n1,n2,total;
    public:
        void data()
        {
            cout<<"\nenter two number "<<endl;
            cin>>n1>>n2;
        }
        void sum()
        {
            total=n1+n2;
            cout<<total;
        }
};

int main()
{
    add <int>x;
    x.data();
    x.sum();
    add <float>y;
    y.data();
    y.sum();
    return 0;
}