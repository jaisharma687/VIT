#include<bits/stdc++.h>
using namespace std;

bool typeCheck(const string &type1, const string &type2){
    return type1 == type2;
}

void parseDeclarations(stringstream &s, unordered_map<string, string> &typeMap){
    string type, var;
    while(s >> type){
        if(type == "char" || type == "int" || type == "float"|| type == "double"){
            while(getline(s,var,',')){
                var.erase(0,var.find_first_not_of(" \t"));
                var.erase(var.find_last_not_of(" \t;")+1);
                if(!var.empty()){
                    typeMap[var] = type;
                }
                if(var.find(';') != string::npos){
                    break;
                }
            }
        }
    }
}

void checkAssignment(const string& str, unordered_map<string, string> &typeMap){
    size_t pos = str.find('=');
    if(pos == string::npos) return;
    string lhs = str.substr(0,pos);
    string rhs = str.substr(pos+1);
    rhs.erase(rhs.find_last_not_of("; ")+1);
    lhs.erase(0,lhs.find_first_not_of(" \t"));
    lhs.erase(lhs.find_last_not_of(" \t")+1);
    vector<string> tokens;
    string token;
    for(char c: rhs){
        if(c=='+'||c=='-'||c=='*'||c=='/'){
            if(!token.empty()){
                tokens.push_back(token);
                token.clear();
            }
        }
        else if(!isspace(c)){
            token += c;
        }
    }
    if(!token.empty()){
        tokens.push_back(token);
    }
    string lhsType = typeMap[lhs];
    cout<<"In "<<str<<endl;
    int i = 0;
    for(const auto& var: tokens){
        if(typeMap.find(var) != typeMap.end()){
            cout<<"Type of "<<lhs<<" & "<<var<<" --> ";
            if(typeCheck(lhsType,typeMap[var])){
                cout<<"MATCHED"<<endl;
            }
            else{
                cout<<"NOT MATCHED"<<endl;
                break;
            }
        }
    }
}

int main() {
    unordered_map<string, string> typeMap;
    string input;
    cout << "Enter expressions: ";
    getline(cin, input);
    stringstream ss(input);
    string stmt;
    while (getline(ss, stmt, ';')) {
        if (stmt.find('=') == string::npos) {
            stringstream declStream(stmt + ";");
            parseDeclarations(declStream, typeMap);
        }
    }
    ss.clear();
    ss.str(input);
    while (getline(ss, stmt, ';')) {
        if (stmt.find('=') != string::npos) {
            checkAssignment(stmt + ";", typeMap);
        }
    }
    return 0;
}