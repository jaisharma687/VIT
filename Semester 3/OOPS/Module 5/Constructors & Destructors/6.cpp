#include<iostream>

using namespace std;

class Area
{
    private:
        int length;
        int breadth;
    public:
        Area()
        {
            length=5; breadth=2 ;
        }
        Area(int l, int b): length(l), breadth(b){}
        Area(Area &a)
        {
            length=a.length;
            breadth=a.breadth;
        }
        void GetLength()
        {
            cout<< "Enter length and breadth respectively: ";
            cin>>length>>breadth;
        }
        int AreaCalculation() 
        {
            return length * breadth;  
        }
        void DisplayArea(int temp)
        {
            cout << "Area: " << temp << endl;
        }
};

int main()
{
    Area A1, A2(2, 1);
    Area A3(A2);
    int temp;
    cout << "Default Area when no argument is passed." << endl;
    temp = A1.AreaCalculation();
    A1.DisplayArea(temp);
    cout << "Area when (2,1) is passed as argument." << endl;
    temp = A2.AreaCalculation();
    A2.DisplayArea(temp);
    cout << "Area when A1 (object ) is passed as argument." << endl;
    temp = A3.AreaCalculation();
    A3.DisplayArea(temp);
    return 0;
}
