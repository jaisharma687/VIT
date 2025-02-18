#include <iostream>

using namespace std;

class Box 
{
    private:
        double length; 
        double breadth; 
        double height;
    public:
        static int objectCount;
        Box(double l = 2.0, double b = 2.0, double h   = 2.0) : length(l),breadth(b),height(h)
        {
            objectCount++;
        }
        double Volume() {
            return length * breadth * height;
        }	
};

int Box::objectCount = 0;

int main(void) 
{
    Box Box1(3.3, 1.2, 1.5); 
    Box Box2(8.5, 6.0, 2.0);    
    cout << "Object Count is "<<Box::objectCount << endl;
    return 0;
}
