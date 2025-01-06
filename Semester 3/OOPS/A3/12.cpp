# include <iostream>

using namespace std;

class AddDistance
{
    int f1,f2,i1,i2;
    public:
        AddDistance(int feet1,int inch1,int feet2,int inch2):f1(feet1),f2(feet2),i1(inch1),i2(inch2){}
        void add()
        {
            int f3 = f1+f2;
            int i3 = i1+i2;
            if(i3>=12)
            {
                f3++;
                i3 -= 12;
            }
            cout << "Distance 1 is " << f1 << " feet " << i1 << " inches\n";
            cout << "Distance 2 is " << f2 << " feet " << i2 << " inches\n";
            cout << "Added Distance is " << f3 << " feet " << i3 << " inches";
        }
};

int main()
{
    AddDistance feettoinch(5,7,6,9);
    // input is 5 feet 7 inch and 6 feet 9 inch
    feettoinch.add();
    return 0;
}