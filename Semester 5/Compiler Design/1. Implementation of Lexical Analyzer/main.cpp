/*
Testcases:

1. 
for(i=0; i<10; i++){
    scanf("%d",a[i]);
}

2.
if(a>b){
    printf("a is greater");
}
else{
    printf("b is grater");
}

*/



#include<bits/stdc++.h>

#define MAX_TOKEN_SIZE 100

using namespace std;

const vector<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return",
    "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while",
};

const vector<string> punctuators = {
    "{", "}", "[", "]", "(", ")", ";", ",", ".", ":", "?", "#", "##", "<%", "%>", "<:", ":>",
    "%:", "%:%:"
};

const vector<string> operators = {
    "+", "-", "*", "/", "%", "++", "--", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!",
    "&", "|", "^", "~", "<<", ">>", "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="
};

bool isKeyword(const string& str) {
    return find(keywords.begin(), keywords.end(), str) != keywords.end();
}

bool isPunctuator(char ch) {
    return any_of(punctuators.begin(), punctuators.end(), [ch](const string& p) {
        return p[0] == ch;
    });
}

bool isOperator(const string& str) {
    return find(operators.begin(), operators.end(), str) != operators.end();
}

bool isConstant(const string& str) {
    if (isdigit(str[0])) {
        for (char ch : str) {
            if (!isdigit(ch) && ch != '.') {
                return false;
            }
        }
        return true;
    }
    return false;
}

void tokenize(const string& code) {
    int i = 0;
    while (i < code.length()) {
        string token;
        while (isspace(code[i])) {
            i++;
        }
        if (isalpha(code[i]) || code[i] == '_') {
            while (isalnum(code[i]) || code[i] == '_') {
                token += code[i++];
            }
            if (isKeyword(token)) {
                cout << "Keyword: " << token << endl;
            } else {
                cout << "Identifier: " << token << endl;
            }
        } else if (isdigit(code[i])) {
            while (isdigit(code[i])) {
                token += code[i++];
            }
            if (code[i] == '.') {
                token += code[i++];
                while (isdigit(code[i])) {
                    token += code[i++];
                }
            }
            cout << "Constant: " << token << endl;
        } else if (code[i] == '"' || code[i] == '\'') {
            char delimiter = code[i++];
            token += delimiter;
            while (code[i] != delimiter && code[i] != '\0') {
                token += code[i++];
            }
            if (code[i] == delimiter) {
                token += code[i++];
            }
            cout << "Literal: " << token << endl;
        } else if (isPunctuator(code[i])) {
            token += code[i++];
            cout << "Punctuator: " << token << endl;
        } else if (isOperator(token)) {
            while (isOperator(token)) {
                token += code[i++];
            }
            cout << "Operator: " << token << endl;
        } else {
            i++;
        }
    }
}

int main() {
    string code;
    getline(cin, code);
    tokenize(code);
    return 0;
}
