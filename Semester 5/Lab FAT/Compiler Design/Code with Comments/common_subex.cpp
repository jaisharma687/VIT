#include<bits/stdc++.h>
using namespace std;

// Structure to represent a three-address expression
struct Expression {
    char left; // Result variable
    char op1;  // First operand
    char op2;  // Second operand
};

// Function to parse a single expression (e.g., "a=b+c") into the `Expression` structure
Expression parseExpression(const string& expr) {
    Expression e;
    e.left = expr[0];  // The left-hand side (result variable)
    e.op1 = expr[2];   // The first operand
    e.op2 = expr[4];   // The second operand
    return e;
}

// Function to check if a variable was redefined between a range of expressions
bool wasRedefined(char var, const vector<Expression>& exprs, int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (exprs[i].left == var) { // Check if the variable was redefined
            return true;
        }
    }
    return false;
}

// Function to find a common subexpression
// Returns the index of the matching expression or -1 if no match is found
int findCommonSubexpression(const vector<Expression>& exprs, int currentIndex, char op1, char op2) {
    for (int i = 0; i < currentIndex; ++i) { // Compare with earlier expressions
        if ((exprs[i].op1 == op1 && exprs[i].op2 == op2) || // Check if operands match
            (exprs[i].op1 == op2 && exprs[i].op2 == op1)) { // Check for commutative operations
            // Ensure neither operand was redefined in the range
            if (!wasRedefined(op1, exprs, i + 1, currentIndex - 1) &&
                !wasRedefined(op2, exprs, i + 1, currentIndex - 1)) {
                return i; // Return the index of the matching expression
            }
        }
    }
    return -1; // No common subexpression found
}

// Function to split the input into individual expressions
vector<string> splitExpressions(const string& input) {
    vector<string> expressions;
    stringstream ss(input);
    string token;

    // Split by semicolon
    while (getline(ss, token, ';')) {
        expressions.push_back(token);
    }

    return expressions;
}

// Function to optimize expressions by identifying and replacing common subexpressions
void optimizeExpressions(vector<string>& expressions) {
    vector<Expression> exprs;

    // Parse each expression into the `Expression` structure
    for (const auto& expr : expressions) {
        exprs.push_back(parseExpression(expr));
    }

    // Iterate through each expression to find optimizations
    for (int i = 0; i < expressions.size(); ++i) {
        // Check if the current expression has a common subexpression with earlier ones
        int matchIdx = findCommonSubexpression(exprs, i, exprs[i].op1, exprs[i].op2);
        if (matchIdx != -1) { // If a match is found
            // Replace the current expression with an optimized one
            expressions[i] = string(1, exprs[i].left) + "=" + exprs[matchIdx].left;
        }
    }
}

int main() {
    string input; // Input string to hold all expressions

    cout << "Enter expressions: ";
    getline(cin, input); // Read input from the user

    // Split the input into individual expressions
    vector<string> expressions = splitExpressions(input);

    // Optimize the expressions by identifying common subexpressions
    optimizeExpressions(expressions);

    // Print the optimized expressions, separated by semicolons
    for (int i = 0; i < expressions.size(); ++i) {
        cout << expressions[i] << ";"; // Add a semicolon between expressions
    }
    cout << endl;

    return 0;
}
