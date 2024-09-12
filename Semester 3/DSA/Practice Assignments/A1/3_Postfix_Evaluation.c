#include <stdio.h>
#include <string.h>
#include <math.h>

char stack[20];
int top = -1;

int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return 1;
    else
        return 0;
}

int operate(int a, int b, char x)
{
    int val;
    switch (x)
    {
        case '+': val = a + b; break;
        case '-': val = a - b; break;
        case '*': val = a * b; break;
        case '/': val = a / b; break;
        case '^': val = (int)pow(a, b); break;
    }
    return val;
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    char x = stack[top];
    top--;
    return x;
}

int evaluation(char s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isOperator(s[i]))
        {
            int b = (int)(pop() - '0');
            int a = (int)(pop() - '0');
            int result = operate(a, b, s[i]);
            push((char)(result + '0'));
        }
        else
            push(s[i]);
    }
    int val = (int)(pop()-'0');
    return val;
}

int main()
{
    char exp[20];
    scanf("%s", exp);
    int val = evaluation(exp, strlen(exp));
    printf("%d", val);
    return 0;
}