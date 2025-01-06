# include <iostream>

using namespace std;

class Rectangle
{
    int l,b;
    public:
    Rectangle(int length, int breadth)
    {
        l = length;
        b = breadth;
    }
    double Area()
    {
        double area;
        return area = l*b;
    }
};

int main()
{
    Rectangle r1(4,5), r2(5,8);
    cout << "Area of Rectangle 1: " << r1.Area() << "\nArea of Rectangle 2: " << r2.Area();
    return 0;
}