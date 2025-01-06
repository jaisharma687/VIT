#include<iostream>

using namespace std;

class volume
{
    double dim1, dim2, dim3;
    public:
        void setdim(double d1, double d2 = 0, double d3 = 0)
        {
            dim1 = d1;
            dim2 = d2;
            dim3 = d3;
        }
        void getdim(double &d1, double &d2, double &d3)
        {
            d1 = dim1;
            d2 = dim2;
            d3 = dim3;
        }
        virtual double getvolume() = 0;
};

class solid : public volume
{
    public:
        double getvolume()
        {
            double d1, d2, d3;
            getdim(d1, d2, d3);
            return (d1 * d2 * d3);
        }
};

class cone : public volume
{
    public:
        double getvolume()
        {
            double d1, d2, d3;
            getdim(d1, d2, d3);
            return (((float)1/3)*((float)22/7)*(d1 * d1 * d2));
        }
};

class sphere : public volume
{
    public:
        double getvolume()
        {
            double d1, d2, d3;
            getdim(d1, d2, d3);
            return (((float)4/3)*((float)22/7)*(d1*d1*d1));
        }
};

int main()
{
    volume *p;
    solid s;
    cone c;
    sphere sp;
    s.setdim(4, 5, 2);
    c.setdim(4, 5);
    sp.setdim(4);
    p = &s;
    cout << "volume of solid : " << p->getvolume() << "\n";
    p = &c;
    cout << "volume of cone : " << p->getvolume() << "\n";
    p = &sp;
    cout << "volume of sphere: " << p->getvolume() << "\n";
    return 0;
}
