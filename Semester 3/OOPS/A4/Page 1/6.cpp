# include <iostream>

using namespace std;

class Customer
{
    private:
        string name;
        long long int accnumb;
    public:
        Customer(string n, long long int acc):name(n),accnumb(acc){}
        void display()
        {
            cout<<"Customer name and account number: "<<name<<" "<<accnumb<<endl;
        }
};

class Account
{
    private:
        int balance;
        int with;
    public:
        Account(int b,int w):balance(b),with(w){}
        int getbalance()
        {
            return balance;
        }
        int getwithdrawal()
        {
            return with;
        }
};

class RBI
{
    protected:
        int minbal;
        int maxwith;
        double minrate = 4;
    public:
        RBI(){}
        RBI(int minbal, int maxwith)
        {
            this->minbal = minbal;
            this->maxwith = maxwith;
        }
        double getrate()
        {
            return minrate;
        }
        bool checkbal(int bal)
        {
            if(bal<minbal)
                return false;
            else
                return true;
        }
        bool checkwith(int with)
        {
            if(with>maxwith)
                return false;
            else
                return true;
        }
};

class SBI : public RBI
{
    public:
        SBI(double minrate)
        {
            this->minrate = minrate;
        }
        double getrate()
        {
            return minrate;
        }
};

class ICICI : public RBI
{
    public:
        ICICI(double minrate)
        {
            this->minrate = minrate;
        }
        double getrate()
        {
            return minrate;
        }
};

class PNB : public RBI
{
    public:
        PNB(double minrate)
        {
            this->minrate = minrate;
        }
        double getrate()
        {
            return minrate;
        }
};

int main()
{
    int acc;
    string name;
    cout<<"Enter name and account number: ";
    cin>>name>>acc;
    Customer C(name,acc);
    int bal,with;
    cout<<"Enter account balance and withdrawal: ";
    cin>>bal>>with;
    Account A(bal,with);
    int maxw,minb;
    cout<<"Enter minimum balance and maximum withdrawl: ";
    cin>>minb>>maxw;
    RBI R(minb,maxw);
    int rsbi,ricici,rpnb;
    cout<<"Enter interest rate for SBI, ICICI and PNB: ";
    cin>>rsbi>>ricici>>rpnb;
    SBI S(rsbi);
    ICICI I(ricici);
    PNB P(rpnb);
    C.display();
    cout<<"Account balance is and withdrawal: "<<A.getbalance()<<" "<<A.getwithdrawal()<<endl;
    if(R.checkbal(A.getbalance()))
        cout<<"Balance is sufficient"<<endl;
    else
        cout<<"Balance is insufficient"<<endl;
    if(R.checkwith(A.getwithdrawal()))
        cout<<"Withdrawal is valid"<<endl;
    else
        cout<<"Withdrawal is invalid"<<endl;
    cout<<"Minimum interest rate set by RBI: "<<R.getrate()<<endl;
    cout<<"Interest rate of SBI, ICICI and PNB: "<<S.getrate()<<" "<<I.getrate()<<" "<<P.getrate()<<endl;
    return 0;
}