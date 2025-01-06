# include <iostream>

using namespace std;

class Area
{
    int length, breadth;
    public:
    Area(int len, int bre)
    {
        length = len;
        breadth = bre;
    }
    double returnArea()
    {
        double area = length * breadth;
        return area;
    }
};

int main()
{
    double l, b;
    std::cout << "Enter the length of the rectangle: ";
    std::cin >> l;
    std::cout << "Enter the breadth of the rectangle: ";
    std::cin >> b;
    Area a(l,b);
    cout << "Area of the rectangle: " << a.returnArea();
    return 0;
}