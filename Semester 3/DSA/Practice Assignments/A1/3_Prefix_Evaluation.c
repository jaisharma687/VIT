# include <stdio.h>
# include <string.h>
# include <math.h>

int stack[30];
int top=-1;

void push(int x)
{
    stack[++top]= x;
}

int pop()
{
    int x = stack[top];
    top--;
    return x;
}

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

int evaluation(char s[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        if(isOperator(s[i]))
        {
            int a = pop();
            int b = pop();
            int result = operate(a,b,s[i]);
            push(result);
        }
        else
            push((int)(s[i]-'0'));
    }
    int val = pop();
}

int main()
{
    char exp[30];
    scanf("%s", exp);
    int val = evaluation(exp, strlen(exp));
    printf("%d", val);
    return 0;
}