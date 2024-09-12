# include <iostream>

using namespace std;

class Vehicle
{
    public:
        double mileage;
        int price;
        Vehicle(double m, int p):mileage(m),price(p){}
};

class Car : public Vehicle
{
    public:
        int owershipcost;
        int warranty;
        int capacity;
        string fuel;
        Car(double m, int p, int o, int w, int c, string f):Vehicle(m,p),owershipcost(o),warranty(w),capacity(c),fuel(f){}
};

class Audi : public Car
{
    public:
        string modeltype;
        Audi(double m, int p, int o, int w, int c, string f,string mt):Car(m,p,o,w,c,f),modeltype(mt){}
        void display();
};

class Ford : public Car
{
    public:
        string modeltype;
        Ford(double m, int p, int o, int w, int c, string f,string mt):Car(m,p,o,w,c,f),modeltype(mt){}
        void display();
};

class Bike : public Vehicle
{
    public:
        int cylinders;
        int gears;
        int tanksize;
        string cooling;
        string wheel;
        Bike(double m, int p,int c, int g, double t, string cool, string w):Vehicle(m,p),cylinders(c),gears(g),tanksize(t),cooling(cool),wheel(w){}
};

class Bajaj : public Bike
{
    public:
        string maketype;
        Bajaj(double m, int p,int c, int g, double t, string cool, string w,string mt):Bike(m,p,c,g,t,cool,w),maketype(mt){}
        void display();
};

class TVS : public Bike
{
    public:
        string maketype;
        TVS(double m, int p,int c, int g, double t, string cool, string w,string mt):Bike(m,p,c,g,t,cool,w),maketype(mt){}
        void display();
};

void Audi::display()
{
    cout<<"Audi Details:"<<endl;
    cout<<"Model Name: "<<modeltype<<endl;
    cout<<"Mileage: "<<mileage<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Ownership cost: "<<owershipcost<<endl;
    cout<<"Warranty: "<<warranty<<endl;
    cout<<"Seating Capacity: "<<capacity<<endl;
}

void Ford::display()
{
    cout<<"\nFord Details:"<<endl;
    cout<<"Model Name: "<<modeltype<<endl;
    cout<<"Mileage: "<<mileage<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Ownership cost: "<<owershipcost<<endl;
    cout<<"Warranty: "<<warranty<<endl;
    cout<<"Seating Capacity: "<<capacity<<endl;
}

void Bajaj::display()
{
    cout<<"\nBajaj Details:"<<endl;
    cout<<"Make Name: "<<maketype<<endl;
    cout<<"Mileage: "<<mileage<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Number of Cylinders: "<<cylinders<<endl;
    cout<<"Number of Gears: "<<gears<<endl;
    cout<<"Cooling Type: "<<cooling<<endl;
    cout<<"Wheel Type: "<<wheel<<endl;
    cout<<"Fuel Tank Size: "<<tanksize<<endl;
};

void TVS::display()
{
    cout<<"\nTVS Details:"<<endl;
    cout<<"Make Name: "<<maketype<<endl;
    cout<<"Mileage: "<<mileage<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Number of Cylinders: "<<cylinders<<endl;
    cout<<"Number of Gears: "<<gears<<endl;
    cout<<"Cooling Type: "<<cooling<<endl;
    cout<<"Wheel Type: "<<wheel<<endl;
    cout<<"Fuel Tank Size: "<<tanksize<<endl;
};

int main()
{
    Audi A(25.5,550000,5000,5,5,"Petrol","A3");
    A.display();
    Ford F(28.4,300000,8000,6,5,"Diesel","Mustang");
    F.display();
    Bajaj B(45.9,75000,2,5,10.5,"Air","Alloys","Pulsar");
    B.display();
    TVS T(40.7,60000,2,6,14.4,"Oil","Spokes","Apache");
    T.display();
    return 0;
}