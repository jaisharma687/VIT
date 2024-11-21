#include<bits/stdc++.h>
using namespace std;

bool isNumeric(string &s){
    try{
        stod(s);
        return true;
    }catch(...){
        return false;
    }
}

bool isFloat(string &s){
    return isNumeric(s) && s.find('.') != string::npos;
}

string threeAddressCodeGenerator(string &exp){
    int opType=0;
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='+') opType = 1;
        else if(exp[i]=='-') opType = 2;
        else if(exp[i]=='*') opType = 3;
        else if(exp[i]=='/') opType = 4;
    }
    string code = "";
    regex pattern(R"((\w+)=(\w+|#?\d+(?:\.\d+)?)[+/*-](\w+|#?\d+(?:\.\d+)?);?)");
    smatch e;
    if(regex_search(exp,e,pattern)){
        string res = e[1];
        string op1 = e[2];
        string op2 = e[3];
        if(isNumeric(op1)) op1 = "#" + op1;
        if(isNumeric(op2)) op2 = "#" + op2;
        bool isFloating = isFloat(op1) || isFloat(op2);
        code += ((isFloating) ? "MOVF " : "MOV ") + op2 + ", R1\n";
        if(opType==1) code += ((isFloating) ? "ADDF " : "ADD ") + op1 + ", R1\n";
        else if(opType==2) code += ((isFloating) ? "SUBF " : "SUB ") + op1 + ", R1\n";
        else if(opType==3) code += ((isFloating) ? "MULF " : "MUL ") + op1 + ", R1\n";
        else if(opType==4) code += ((isFloating) ? "DIVF " : "DIV ") + op1 + ", R1\n";
        code += ((isFloating) ? "MOVF R1, " : "MOV R1, ") + res;
    }
    else{
        code = "Invalid";
    }
    return code;
}

int main(){
    string tac;
    cout<<"Enter the Three Address Code: ";
    getline(cin,tac);
    cout<<threeAddressCodeGenerator(tac);
}