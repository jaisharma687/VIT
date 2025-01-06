#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a==b){
        return a;
    }
    else if(a>b){
        return gcd(a-b,b);
    }
    else{
        return gcd(a,b-a);
    }
}

int main(){
    int a,b;
    cout<<"Enter number a: "<<endl;
    cin>>a;
    cout<<"Enter number b: "<<endl;
    cin>>b;
    cout<<"GCD of "<<a<<" and "<<b<<" is: "<<gcd(a,b)<<endl;
    return 0;
}