#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Helper function to check if a character is a digit
bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Helper function to check if a character is a letter (uppercase or lowercase)
bool is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Function to extract a constant (number) from the expression
double extract_constant(const string &exp, int &i) {
    double num = 0.0, factor = 1.0;
    bool is_fraction = false;

    while (i < exp.length() && (is_digit(exp[i]) || exp[i] == '.')) {
        if (exp[i] == '.') {
            is_fraction = true;
            i++;
        } else {
            num = num * 10 + (exp[i] - '0');
            if (is_fraction) {
                factor *= 10.0;
            }
            i++;
        }
    }
    return num / factor;
}

// Function to extract a variable name from the expression
void extract_variable(const string &exp, int &i, string &output) {
    while (i < exp.length() && is_letter(exp[i])) {
        output += exp[i++];
    }
}

int main() {
    string expression, optimized;
    int i = 0;
    double result = 0.0, current_value = 0.0;
    char current_op = '+';

    cout << "Enter the input string: ";
    getline(cin, expression);

    cout << "The Constants are: ";
    int constants = 0;
    int variables = 0;

    // Copy the part of the expression before '=' into the optimized string
    while (i < expression.length() && expression[i] != '=') {
        optimized += expression[i++];
    }

    // Copy the '=' character if present
    if (i < expression.length() && expression[i] == '=') {
        optimized += expression[i++];
    }

    // Parse the right-hand side of the expression
    while (i < expression.length()) {
        if (is_letter(expression[i])) {
            string variable;
            extract_variable(expression, i, variable);
            optimized += variable;
            variables++;
        } else if (is_digit(expression[i]) || expression[i] == '.') {
            double num = extract_constant(expression, i);
            constants++;
            cout << num << " ";

            if (current_op == '+') {
                result += current_value;
                current_value = num;
            } else if (current_op == '-') {
                result += current_value;
                current_value = -num;
            } else if (current_op == '*') {
                current_value *= num;
            } else if (current_op == '/') {
                current_value /= num;
            }
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            current_op = expression[i++];
        } else {
            i++;
        }
    }

    result += current_value; // Add the last pending operation result
    optimized += "+";
    optimized += to_string(result);

    cout << "\nBefore optimization: " << (variables + constants)
              << "\nAfter optimization: " << (variables + 1)
              << "\nOptimized expression: " << optimized
              << "\nThe value of the constant expression is: " << result << "\n";

    return 0;
}
