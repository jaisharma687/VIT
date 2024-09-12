# include <iostream>

using namespace std;

class sampleFO
{
    public:
        void func(int x)
        {
            cout <<"Value of x is: "<<x<<endl;
        }
        void func(double x)
        {
            cout <<"Value of x is: "<<x<<endl;
        }
        void func(int x,int y)
        {
            cout <<"Value of x and y is: "<<x<<" , "<<y<<endl;
        }
};

int main()
{
    sampleFO obj;
    obj.func(7);
    obj.func(9.132);
    obj.func(85,64);
    return 0;
}