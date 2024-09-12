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
        operator int()
        {
            return (x);
        }
        operator float()
        {
            return f;
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
    int j;
    float k;
    typeconv z;
    z.display();
    z=5.5;
    z.display();
    j = z;
    k = z;
    cout<<"j = "<<j<<" k = "<<k<<endl;
    return 0;
}