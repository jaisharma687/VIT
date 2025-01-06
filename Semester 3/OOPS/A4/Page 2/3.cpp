# include <iostream>

using namespace std;

class Swapping
{
    public:
        Swapping(){}
        void swap(int &a,int &b);
        void swap(float &a, float &b);
        void swap(char &a, char &b);
        void swap(string &a, string &b);
};

void Swapping::swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Swapping::swap(float &a, float &b)
{
    float temp;
    temp = a;
    a = b;
    b = temp;
}

void Swapping::swap(char &a, char &b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

void Swapping::swap(string &a, string &b)
{
    string temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    Swapping S;
    int x,y;
    float a,b;
    char u,v;
    string p,q;
    cout<<"Enter the int numbers to swap x & y: ";
    cin>>x>>y;
    cout<<"Enter the float numbers to swap a & b: ";
    cin>>a>>b;
    cout<<"Enter the char to swap u & v: ";
    cin>>u>>v;
    cout<<"Enter the string to swap p & q: ";
    cin>>p>>q;
    cout<<"Before Swap values:"<<endl;
    cout<<"x = "<<x<<"\ny = "<<y<<endl;
    cout<<"a = "<<a<<"\nb = "<<b<<endl;
    cout<<"u = "<<u<<"\nv = "<<v<<endl;
    cout<<"p = "<<p<<"\nq = "<<q<<endl;
    S.swap(x,y);
    S.swap(a,b);
    S.swap(u,v);
    S.swap(p,q);
    cout<<"After Swap values:"<<endl;
    cout<<"x = "<<x<<"\ny = "<<y<<endl;
    cout<<"a = "<<a<<"\nb = "<<b<<endl;
    cout<<"u = "<<u<<"\nv = "<<v<<endl;
    cout<<"p = "<<p<<"\nq = "<<q<<endl;
    return 0;
}