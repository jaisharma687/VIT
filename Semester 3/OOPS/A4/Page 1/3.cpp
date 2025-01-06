# include <iostream>
# include <cstdlib>

using namespace std;

class Marks
{
    private:
        int roll;
        string name;
        float marks;
    public:
        void getname();
        string returnname();
        void getroll();
        int returnroll();
        int returnmarks();
        float averagemarks(int,int,int);
};


void Marks::getname()
{
    cout<<"Enter the name of student: "<<endl;
    cin>>name;
}

string Marks::returnname()
{
    return name;
}

void Marks::getroll()
{
    roll = rand()%1000;
}

int Marks::returnroll()
{
    return roll;
}

class Physics : public Marks
{
    private:
        int phymarks;
    public:
        void getPhy();
        int returnPhy();
};

void Physics::getPhy()
{
    cout<<"Enter Physics Marks:"<<endl;
    cin>>phymarks;
}

int Physics::returnPhy()
{
    return phymarks;
}

class Chemistry : public Marks
{
    private:
        int chemmarks;
    public:
        void getChem();
        int returnChem();
};

void Chemistry::getChem()
{
    cout<<"Enter Chemistry Marks:"<<endl;
    cin>>chemmarks;
}

int Chemistry::returnChem()
{
    return chemmarks;
}

class Mathematics : public Marks
{
    private:
        int mathmarks;
    public:
        void getMath();
        int returnMath();
};

void Mathematics::getMath()
{
    cout<<"Enter Mathematics Marks:"<<endl;
    cin>>mathmarks;
}

int Mathematics::returnMath()
{
    return mathmarks;
}

float Marks::averagemarks(int x,int y,int z)
{
    return marks = (x+y+z)/3;
}

int Marks::returnmarks()
{
    return marks;
}

int main()
{
    int n;
    cout<<"Enter the number of students: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        Marks M;
        M.getroll();
        M.getname();
        Physics P;
        Chemistry C;
        Mathematics Ma;
        P.getPhy();
        C.getChem();
        Ma.getMath();
        M.averagemarks(P.returnPhy(),C.returnChem(),Ma.returnMath());
        cout<<"Name of the student is: "<<M.returnname()<<endl;
        cout<<"Roll Number is: "<<M.returnroll()<<endl;
        cout<<"Physics Marks: "<<P.returnPhy()<<endl;
        cout<<"Chemistry Marks: "<<C.returnChem()<<endl;
        cout<<"Mathematics Marks: "<<Ma.returnMath()<<endl;
        cout<<"Average Marks: "<<M.returnmarks()<<endl;
    }
    return 0;
}