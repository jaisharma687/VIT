# include <iostream>

using namespace std;

int perfect(int n)
{
    int sum = 0;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            sum += i;
        }
    }
    if(sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int input;
    cout << "Enter the number:\n"; 
    cin >> input;
    if(perfect(input))
    {
        cout << "Perfect number";
    }
    else
    {
        cout << "Not Perfect number";
    }
    return 0;
}