# include <stdio.h>

char stack[20];
int top=-1;
char post[30];
int toppost = -1;

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
    char temp;
    temp = stack[top];
    top--;
    return temp;
}

int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == ')' || x == '(')
        return 1;
    else
        return 0;
}

int precedence(char x)
{
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

void postfix(char exp[])
{
    for(int i=0; exp[i]!='\0' ;i++)
    {
        if(!isOperator(exp[i]))
            post[++toppost] = exp[i];
        else if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            while(!isEmpty() && stack[top]!='(')
            {
                post[++toppost] = pop();
            }
            top--;
        }
        else if(exp[i] != '^')
        {
            while(!isEmpty() && precedence(exp[i])<=precedence(stack[top]))
            {
                post[++toppost] = pop();
            }
            push(exp[i]);
        }
        else if(exp[i] == '^')
        {
            push(exp[i]);
        }
    }
    while(!isEmpty())
    {
        post[++toppost] = pop();
    }
    post[++toppost] = '\0';
}

int main()
{
    char infix[30];
    scanf("%s",infix);
    postfix(infix);
    printf("%s",post);
    return 0;
}