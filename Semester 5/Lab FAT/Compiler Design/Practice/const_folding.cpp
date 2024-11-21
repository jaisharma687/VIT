#include<bits/stdc++.h>
using namespace std;

bool isDigit(char s){
    return s>='0' && s<='9';
}

bool isLetter(char s){
    return s>='a' && s<='z' || s>='A' && s<='Z';
}

double extractConstant(string &exp, int &i){
    double val = 0;
    double factor = 1;
    bool isFactor = false;
    while(i<exp.size() && (isDigit(exp[i]) || exp[i] == '.')){
        if(exp[i]=='.'){
            isFactor = true;
        }
        else{
            val = val * 10 + (int)(exp[i] - '0');
            if(isFactor) factor *= 10;
        }
        i++;
    }
    return (double)(val/factor);
}

string extractVariable(string &exp, int &i){
    int start = i;
    while(i<exp.size() && isLetter(exp[i])){
        i++;
    }
    return exp.substr(start,i-start);
}

int main(){
    string exp, opt;
    cout<<"Enter the expression: "<<endl;
    getline(cin,exp);
    int cons = 0;
    int var = 0;
    int i = 0;
    while(i<exp.size() && exp[i]!='='){
        i++;
    }
    if(i<exp.size() && exp[i]=='='){
        i++;
    }
    opt = exp.substr(0,i);
    char currentOp = '=';
    double result = 0, current = 0;
    cout<<"Constants are: ";
    while(i<exp.size()){
        if(isLetter(exp[i])){
            opt += extractVariable(exp,i);
            var++;
        }
        else if(isDigit(exp[i])){
            double num = extractConstant(exp,i);
            cout<<num<<" ";
            cons++;
            if(currentOp=='+'){
                result+=current;
                current=num;
            }
            else if(currentOp=='-'){
                result+=current;
                current=-num;
            }
            else if(currentOp=='*'){
                current*=num;
            }
            else if(currentOp=='/'){
                current/=num;
            }
        }
        else if(exp[i]=='=' || exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            currentOp = exp[i++];
        }
        else{
            i++;
        }
    }
    result += current;
    cout<<"\nConstants: "<<cons<<endl;
    cout<<"Variables: "<<var<<endl;
    cout<<"Before Optimization: "<<var+cons<<endl;
    cout<<"After Optimization: "<<var+1<<endl;
    opt += "+" + to_string(result);
    cout<<"Optimized expression: "<<opt<<endl;
    cout<<"Constant Value: "<<result<<endl;
    return 0;
}