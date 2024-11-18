#include<bits/stdc++.h>
using namespace std;

string xorBinary(const string &a,const string &b){
    string result = "";
    for(int i=0;i<a.size();i++){
        result += (a[i]==b[i])?'0':'1';
    }
    return result;
}

string CRC(string dividend, string divisor){
    int n = dividend.size();
    int m = divisor.size();
    for(int i=0;i<=n-m;i++){
        if(dividend[i]=='1'){
            string remainder = xorBinary(dividend.substr(i,m),divisor);
            for(int j=0;j<m;j++){
                dividend[i+j] = remainder[j];
            }
        }
    }
    return dividend.substr(n-m+1);
}

string encodeDividend(string dividend, string divisor){
    string appended = dividend + string(divisor.size()-1,'0');
    string remainder = CRC(appended,divisor);
    return dividend + remainder;
}

bool verifyCRC(string dividend,string divisor){
    string remainder = CRC(dividend,divisor);
    cout<<"Remainder: "<<remainder<<endl;
    return remainder.find('1') == string::npos;
}

int main(){
    string dividend;
    string divisor;
    cout<<"Enter dividend: ";
    cin>>dividend;
    cout<<"Enter divisor: ";
    cin>>divisor;
    string encoded = encodeDividend(dividend,divisor);
    cout<<"Encoded Dividend: "<<encoded<<endl;
    if(verifyCRC(encoded,divisor)){
        cout<<"CRC is valid"<<endl;
    }
    else{
        cout<<"CRC is invalid"<<endl;
    }
}