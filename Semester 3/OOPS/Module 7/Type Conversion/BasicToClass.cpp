# include <iostream>

using namespace std;

class typeconv
{
    private:
        int x;
        float f;
    public:
        typeconv()
        {
            x=0;
            f=0;
        }
        typeconv(float m)
        {
            x=2;
            f = m;
        }
        void display()
        {
            cout<<"x = "<<x<<" f = "<<f<<endl;
        }
};

int main()
{
    typeconv z;
    z.display();
    z=1;
    z.display();
    z=2.5;
    z.display();
    return 0;
}