# include <stdio.h>

char stack[20];
char postfix[20];
int top = -1;
int post = -1;

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(!isEmpty())
        return stack[top--];
}

int isOperator(char x)
{
    if(x == '+' || x == '-' || x == '/' || x == '*' || x == '^' || x == ')' || x == '(')
        return 1;
    else 
        return 0;
}

int precedence(char x)
{
    if(x == '^')
        return 3;
    else if(x == '/' || x == '*')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else 
        return 0;
}

void postfixcon(char exp[])
{
    for(int i=0; exp[i]!='\0';i++)
    {
        if(!isOperator(exp[i]))
            postfix[++post] = exp[i];
        else if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            while(stack[top]!='(')
                postfix[++post] = pop();
            pop();
        }
        else if(exp[i]!='^')
        {
            while(!isEmpty() && precedence(exp[i]) <= precedence(stack[top]))
                postfix[++post] = pop();
            push(exp[i]);
        }
        else if(exp[i]=='^')
        {
            push(exp[i]);
        }
    }
    while(!isEmpty())
        postfix[++post] = pop();
}

int main()
{
    char infix[20];
    scanf("%s",infix);
    postfixcon(infix);
    printf("%s",postfix);
}