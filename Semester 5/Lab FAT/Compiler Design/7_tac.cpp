#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool isNumericValue(const string &inputStr) {
    string tempStr = inputStr;
    if (tempStr[0] == '#') tempStr = tempStr.substr(1);
    try {
        stod(tempStr);
        return true;
    } catch (invalid_argument &) {
        return false;
    }
}

bool isFloatValue(const string &inputStr) {
    string tempStr = inputStr;
    if (tempStr[0] == '#') tempStr = tempStr.substr(1);
    if (!isNumericValue(tempStr)) return false;
    return tempStr.find('.') != string::npos || tempStr.find('e') != string::npos ||
        tempStr.find('E') != string::npos;
}

bool isFloatVariableName(const string &variableName) {
    return variableName[0] == 'f' || variableName.find("float") != string::npos ||
        variableName.find("decimal") != string::npos || variableName.find("real") != string::npos;
}

string generateAssemblyCode(const string &TAC) {
    string cleanCode = regex_replace(TAC, regex("\\s+"), "");
    size_t colonIndex = cleanCode.find(':');
    if (colonIndex == string::npos) {
        return "Invalid input format";
    }
    int operatorType = 0;
    for (int i = 0; i < TAC.size(); i++) {
        if (TAC[i] == '+') operatorType = 1;
        else if (TAC[i] == '-') operatorType = 2;
        else if (TAC[i] == '*') operatorType = 3;
        else if (TAC[i] == '/') operatorType = 4;
    }

    string resultVar = cleanCode.substr(0, colonIndex);
    string expression = cleanCode.substr(colonIndex + 1);
    regex expressionPattern(R"((\w+)=(\w+|#?\d+(?:\.\d+)?)[+/*-](\w+|#?\d+(?:\.\d+)?);?)");
    smatch expressionMatches;
    if (regex_search(expression, expressionMatches, expressionPattern)) {
        string result = expressionMatches[1];
        string operand1 = expressionMatches[2];
        string operand2 = expressionMatches[3];

        bool isResultFloat = isFloatValue(operand1) || isFloatValue(operand2) || isFloatVariableName(operand1) || isFloatVariableName(operand2);

        string assemblyCode;
        if (isNumericValue(operand2)) {
            assemblyCode += "MOV #" + operand2 + ", R1\n";
        } else {
            assemblyCode += isResultFloat ? "MOVF " + operand2 + ", R1\n" : "MOV " + operand2 + ", R1\n";
        }

        if (operatorType == 1) {
            if (isNumericValue(operand1)) {
                assemblyCode += isFloatValue(operand1) || isFloatValue(operand2) ?
                                "ADDF #" + operand1 + ", R1\n" : "ADD #" + operand1 + ", R1\n";
            } else {
                assemblyCode += isResultFloat ? "ADDF " + operand1 + ", R1\n" : "ADD " + operand1 + ", R1\n";
            }
        } else if (operatorType == 2) {
            if (isNumericValue(operand1)) {
                assemblyCode += isFloatValue(operand1) || isFloatValue(operand2) ?
                                "SUBF #" + operand1 + ", R1\n" : "SUB #" + operand1 + ", R1\n";
            } else {
                assemblyCode += isResultFloat ? "SUBF " + operand1 + ", R1\n" : "SUB " + operand1 + ", R1\n";
            }
        } else if (operatorType == 3) {
            if (isNumericValue(operand1)) {
                assemblyCode += isFloatValue(operand1) || isFloatValue(operand2) ?
                                "MULF #" + operand1 + ", R1\n" : "MUL #" + operand1 + ", R1\n";
            } else {
                assemblyCode += isResultFloat ? "MULF " + operand1 + ", R1\n" : "MUL " + operand1 + ", R1\n";
            }
        } else if (operatorType == 4) {
            if (isNumericValue(operand1)) {
                assemblyCode += isFloatValue(operand1) || isFloatValue(operand2) ?
                                "DIVF #" + operand1 + ", R1\n" : "DIV #" + operand1 + ", R1\n";
            } else {
                assemblyCode += isResultFloat ? "DIVF " + operand1 + ", R1\n" : "DIV " + operand1 + ", R1\n";
            }
        }

        assemblyCode += isResultFloat ? "MOVF R1, " + result : "MOV R1, " + result;
        return assemblyCode;
    }
    return "Invalid expression format";
}

int main() {
    string tacInput;
    cout << "Enter the Three Address Code: ";
    getline(cin, tacInput);
    string formattedInput = "Enter the Three Address Code: " + tacInput;
    cout << generateAssemblyCode(formattedInput) << endl;
    return 0;
}