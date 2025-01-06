# include <iostream>

using namespace std;

template <class t>

t large(t n1,t n2)
{
    return (n1>n2?n1:n2);
}

int main()
{
    int i1,i2;
    float f1,f2;
    char c1,c2;
    cout<<"enter two integer ";
    cin>>i1>>i2;
    cout<<large(i1,i2)<<" is larger"<<endl;
    cout<<"enter two float ";
    cin>>f1>>f2;
    cout<<large(f1,f2)<<" is larger"<<endl;
    cout<<"enter two char ";
    cin>>c1>>c2;
    cout<<large(c1,c2)<<" is larger";
    return 0;
}