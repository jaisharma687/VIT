#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

double extract_constant(char *exp, int *i) {
    double num = 0.0, factor = 1.0;
    int is_fraction = 0;
    while (is_digit(exp[*i]) || exp[*i] == '.') {
        if (exp[*i] == '.') {
            is_fraction = 1;
            (*i)++;
        } else {
            num = num * 10 + (exp[*i] - '0');
            if (is_fraction) {
                factor *= 10.0;
            }
            (*i)++;
        }
    }
    return num / factor;
}

void extract_variable(char *exp, int *i, char *output, int *j) {
    while (is_letter(exp[*i])) {
        output[(*j)++] = exp[*i];
        (*i)++;
    }
}

int main() {
    char expression[200], optimized[200];
    int i = 0, j = 0;
    double result = 0, current_value = 0;
    char current_op = '+';

    printf("Enter the input string: ");
    scanf("%[^\n]s", expression);

    printf("The Constants are: ");
    int constants = 0;
    int variables = 0;

    while (expression[i] != '=' && expression[i] != '\0') {
        optimized[j++] = expression[i++];
    }

    if (expression[i] == '=') {
        optimized[j++] = expression[i++];
    }

    while (expression[i] != '\0') {
        if (is_letter(expression[i])) {
            extract_variable(expression, &i, optimized, &j);
            variables++;
        } else if (is_digit(expression[i]) || expression[i] == '.') {
            double num = extract_constant(expression, &i);
            constants++;
            printf("%.2f ", num);
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

    result += current_value;
    optimized[j] = '\0';

    printf("\nBefore optimization: %d\nAfter optimization: %d", variables + constants, variables + 1);
    printf("\nOptimized expression: %s+%.2f\n", optimized, result);
    printf("The value of the constant expression is: %.2f\n", result);

    return 0;
}
