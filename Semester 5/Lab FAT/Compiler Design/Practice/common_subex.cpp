#include<bits/stdc++.h>
using namespace std;

struct Expression{
    char left;
    char op1;
    char op2;
};

Expression parseExpressions(string &e){
    Expression exp;
    exp.left = e[0];
    exp.op1 = e[2];
    if(e.size()>3) exp.op2 = e[4];
    return exp;
}

vector<string> splitExpression(string &e){
    vector<string> expressions;
    stringstream ss(e);
    string token;
    while(getline(ss,token,';')){
        expressions.push_back(token);
    }
    return expressions;
}

bool wasRedifined(char v, vector<Expression> &exps, int start, int end){
    for(int i=start;i<=end;i++){
        if(exps[i].left == v) return true;
    }
    return false;
}

int findCommonSubExpressions(vector<Expression> &exps, int current, char op1, char op2){
    for(int i=0;i<current;i++){
        if((exps[i].op1 == op1 && exps[i].op2 == op2)
        || (exps[i].op1 == op2 && exps[i].op2 == op1)){
            if(!wasRedifined(op1,exps,i+1,current-1)
            && !wasRedifined(op2,exps,i+1,current-1)){
                return i;
            }
        }
    }
    return -1;
}

void optimizeExpressions(vector<string> &exps){
    vector<Expression> e;
    for(int i=0;i<exps.size();i++){
        e.push_back(parseExpressions(exps[i]));
    }
    for(int i=0;i<exps.size();i++){
        int idx = findCommonSubExpressions(e,i,e[i].op1,e[i].op2);
        if(idx != -1){
            exps[i] = string(1,e[i].left) + '=' + e[idx].left;
        }
    }
}

int main(){
    string exp;
    cout<<"Enter the Expressions: ";
    getline(cin,exp);
    vector<string> exps = splitExpression(exp);
    optimizeExpressions(exps);
    cout<<"Optimized Expressions: ";
    for(int i=0;i<exps.size();i++){
        cout<<exps[i]<<";";
    }
    return 1;
}