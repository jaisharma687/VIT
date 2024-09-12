# include <iostream>

using namespace std;

class Area
{
    int len,bre;
    public:
    void getDim()
    {
        cout << "Enter the length: ";
        cin >> len;
        cout << "Enter the breadth: ";
        cin >> bre;
    }
    double getArea()
    {
        double area = len*bre;
        return area;
    }
};

int main()
{
    Area a;
    a.getDim();
    cout << "Area :\n" << a.getArea(); 
    return 0;
}