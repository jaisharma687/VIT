# include <iostream>

using namespace std;

class Counter
{
    private:
        int count;
    public:
        Counter():count(0){}
        int getcount()
        {
            return count;
        }
        void operator ++()
        {
            count++;
        }
        void operator ++(int)
        {
            count++;
        }
};

int main()
{
    Counter c1, c2;
    cout<<"Initial count of c1 & c2: "<<c1.getcount()<<" "<<c2.getcount()<<endl;
    c1++;
    c2++;
    ++c2;
    ++c1;
    c1++;
    cout<<"After applying ++ operator c1= "<<c1.getcount()<<" c2= "<<c2.getcount()<<endl;
    return 0;
}