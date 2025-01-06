#include <bits/stdc++.h>
using namespace std;

// Function to check if a string represents a numeric value
bool isNumericValue(const string &inputStr) {
    try {
        stod(inputStr);
        return true;
    } catch (...) {
        return false;
    }
}

bool isFloatValue(const string &inputStr) {
    return isNumericValue(inputStr) && inputStr.find('.') != string::npos;
}

// Function to generate assembly code from Three Address Code (TAC)
string generateAssemblyCode(const string &TAC) {
    // Determine the operator type based on the presence of operators in the TAC
    int operatorType = 0; // 0 = none, 1 = +, 2 = -, 3 = *, 4 = /
    for (int i = 0; i < TAC.size(); i++) {
        if (TAC[i] == '+') operatorType = 1;
        else if (TAC[i] == '-') operatorType = 2;
        else if (TAC[i] == '*') operatorType = 3;
        else if (TAC[i] == '/') operatorType = 4;
    }

    // Regular expression to parse the TAC into components
    regex expressionPattern(R"((\w+)=(\w+|#?\d+(?:\.\d+)?)[+/*-](\w+|#?\d+(?:\.\d+)?);?)");
    smatch expressionMatches;

    // Match the TAC against the regular expression
    if (regex_search(TAC, expressionMatches, expressionPattern)) {
        string result = expressionMatches[1];     // LHS of the assignment
        string operand1 = expressionMatches[2];   // First operand
        string operand2 = expressionMatches[3];   // Second operand

        string assemblyCode;
        // Determine if the result is a floating-point operation
        bool isResultFloat = isFloatValue(operand1) || isFloatValue(operand2);

        // Prefix numeric values with '#' for immediate addressing
        if (isNumericValue(operand1)) operand1 = "#" + operand1;
        if (isNumericValue(operand2)) operand2 = "#" + operand2;

        // Generate the assembly code for loading the second operand into R1
        assemblyCode += isResultFloat ? "MOVF " + operand2 + ", R1\n" : "MOV " + operand2 + ", R1\n";

        // Generate the assembly code for the operator
        if (operatorType == 1) {
            assemblyCode += isResultFloat ? "ADDF " + operand1 + ", R1\n" : "ADD " + operand1 + ", R1\n";
        } else if (operatorType == 2) {
            assemblyCode += isResultFloat ? "SUBF " + operand1 + ", R1\n" : "SUB " + operand1 + ", R1\n";
        } else if (operatorType == 3) {
            assemblyCode += isResultFloat ? "MULF " + operand1 + ", R1\n" : "MUL " + operand1 + ", R1\n";
        } else if (operatorType == 4) {
            assemblyCode += isResultFloat ? "DIVF " + operand1 + ", R1\n" : "DIV " + operand1 + ", R1\n";
        }

        // Store the result back to the destination
        assemblyCode += isResultFloat ? "MOVF R1, " + result : "MOV R1, " + result;

        return assemblyCode;
    }

    // If the TAC format is invalid, return an error message
    return "Invalid expression format";
}

int main() {
    string tacInput;

    // Prompt the user for the Three Address Code input
    cout << "Enter the Three Address Code: ";
    getline(cin, tacInput);

    // Generate and display the corresponding assembly code
    cout << generateAssemblyCode(tacInput) << endl;

    return 0;
}
