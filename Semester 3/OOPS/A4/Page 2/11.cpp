# include <iostream>

using namespace std;

class Volume
{
    public:
        void vol(int);
        void vol(double,int);
        void vol(double);
};

void Volume::vol(int s)
{
    cout<<"Volume of Cube is: "<<s*s*s<<endl;
}

void Volume::vol(double r)
{
    cout<<"Volume of Sphere is: "<<(4*r*r*r*3.14)/3<<endl;
}

void Volume::vol(double r, int h)
{
    cout<<"Volume of Cylinder is: "<<3.14*r*r*h<<endl;
}

int main()
{
    Volume V;
    V.vol(5);
    V.vol(4.5);
    V.vol(4.2,6);
    return 0;
}