# include <iostream>

using namespace std;

class Mammals
{
    public:
        void identitymammals()
        {
            cout<<"I am a Mammal"<<endl;
        }
};

class MarineAnimals
{
    public:
        void identitymarine()
        {
            cout<<"I am a Marine Animal"<<endl;
        }
};

class BlueWhale : public Mammals, public MarineAnimals 
{
    public:
        void identityblue()
        {
            cout<<"I belong to both the categories: Mammals as well as Marine Animal"<<endl;
        }
};

int main()
{
    Mammals m;
    MarineAnimals ma;
    BlueWhale b;
    m.identitymammals();
    ma.identitymarine();
    b.identityblue();
    b.identitymammals();
    b.identitymarine();
    return 0;
}