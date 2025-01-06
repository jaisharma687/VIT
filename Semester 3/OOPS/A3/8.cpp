# include <iostream>

using namespace std;

class Average
{
    public:
    static void calanddispavg(int a,int b,int c)
    {
        double avg = (a+b+c)/3;
        cout << "Average: \n" <<  avg;
    }
};

int main()
{
    Average::calanddispavg(3,7,5);
    return 0;
}