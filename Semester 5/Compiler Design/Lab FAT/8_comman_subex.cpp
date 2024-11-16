#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPR 100
#define MAX_LEN 1000

typedef struct {
    char left;
    char op1;
    char op2;
} Expression;

Expression parseExpression(const char* expr) {
    Expression e;
    e.left = expr[0];
    e.op1 = expr[2];
    e.op2 = expr[4];
    return e;
}

int wasRedefined(char var, Expression* exprs, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (exprs[i].left == var) {
            return 1;
        }
    }
    return 0;
}

int findCommonSubexpression(Expression* exprs, int count, char op1, char op2, int currentIndex) {
    for (int i = 0; i < currentIndex; i++) {
        if ((exprs[i].op1 == op1 && exprs[i].op2 == op2) || (exprs[i].op1 == op2 && exprs[i].op2 == op1)) {
            if (!wasRedefined(op1, exprs, i + 1, currentIndex - 1) && 
                !wasRedefined(op2, exprs, i + 1, currentIndex - 1)) {
                return i;
            }
        }
    }
    return -1;
}

int splitExpressions(char* input, char expressions[][MAX_LEN]) {
    int count = 0;
    char* token = strtok(input, ";");
    while (token != NULL) {
        strcpy(expressions[count++], token);
        token = strtok(NULL, ";");
    }
    return count;
}

void optimizeExpressions(char expressions[][MAX_LEN], int count) {
    Expression* exprs = (Expression*)malloc(count * sizeof(Expression));
    for (int i = 0; i < count; i++) {
        exprs[i] = parseExpression(expressions[i]);
    }

    for (int i = 0; i < count; i++) {
        int matchIdx = findCommonSubexpression(exprs, count, exprs[i].op1, exprs[i].op2, i);
        if (matchIdx != -1) {
            sprintf(expressions[i], "%c=%c", exprs[i].left, exprs[matchIdx].left);
        }
    }

    free(exprs);
}

int main() {
    char input[MAX_LEN];
    char expressions[MAX_EXPR][MAX_LEN];

    printf("Enter expressions: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0;

    int count = splitExpressions(input, expressions);
    optimizeExpressions(expressions, count);

    for (int i = 0; i < count; i++) {
        printf("%s", expressions[i]);
        if (i < count - 1) printf(";");
    }
    printf("\n");

    return 0;
}
