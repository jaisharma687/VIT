# include <iostream>

using namespace std;

double calc_GrossPay(float basic, float da, float hra)
{
    return basic +da/100*basic+hra;
}

double calc_GrossPay(float hr, float wg)
{
    return hr*wg;
}

double calc_GrossPay(float p)
{
    return p;
}

int main()
{
    int choice;
    double gross;
    cin>>choice;
    if(choice==1)
    {
        float basic,da,hra;
        cin>>basic>>da>>hra;
        cout<<calc_GrossPay(basic,da,hra);
        gross = basic + da/100*basic + hra;
    }
    else if(choice ==2)
    {
        float hours, wages;
        cin>>hours>>wages;
        cout<<calc_GrossPay(hours,wages);
    }
    else if(choice == 3)
    {
        float pay;
        cin>>pay;
        cout<<calc_GrossPay(pay);
    }
    return 0;
}