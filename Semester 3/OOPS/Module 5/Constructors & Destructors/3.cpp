#include<iostream>

using namespace std;

class Marks
{
    public:
        int maths;
        int science;
        Marks() 
        {
            maths=10;
            science=5;
        }
        Marks(Marks  &t) 
        {
            maths=t.maths;
            science=t.science;
        }
        void display() 
        {
            cout << "Maths :  " << maths <<endl;
            cout << "Science :" << science << endl;
        }
};

int main() 
{
    Marks m1;
    Marks m2(m1);
    m1.display();
    m2.display();
    return 0;
}