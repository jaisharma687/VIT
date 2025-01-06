# include <iostream>

using namespace std;

class minutes
{
    int m;
    public:
        minutes()
        {
            m=240;
        }
        int get()
        {
            return (m);
        }
        void display()
        {
            cout<<"Minutes = "<<m<<endl;
        }
};

class hours
{
    int h;
    public:
        void operator =(minutes x);
        void display()
        {
            cout<<"Hours = "<<h<<endl;
        }
};

void hours::operator=(minutes x)
{
    h = x.get()/60;
}

int main()
{
    minutes min;
    hours hr;
    hr = min;
    min.display();
    hr.display();
    return 0;
}