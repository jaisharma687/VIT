# include <stdio.h>
# include <string.h>

char stack[20];
int top=-1;
char pre[30];
int toppre = -1;

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

void reverse(char exp[])
{
    char temp[30];
    int l = strlen(exp);
    int k=-1;
    for(int i=l-1;i>=0;i--)
        temp[++k] = exp[i];
    temp[++k] = '\0';
    for(int i=0;i<l;i++)
        exp[i] = temp[i];
}

void prefix(char exp[])
{
    reverse(exp);
    for(int i=0; exp[i]!='\0' ;i++)
    {
        if(!isOperator(exp[i]))
            pre[++toppre] = exp[i];
        else if(exp[i] == ')')
            push(exp[i]);
        else if(exp[i] == '(')
        {
            while(!isEmpty() && stack[top]!=')')
            {
                pre[++toppre] = pop();
            }
            top--;
        }
        else if(exp[i] != '^')
        {
            while(!isEmpty() && precedence(exp[i])<precedence(stack[top]))
            {
                pre[++toppre] = pop();
            }
            push(exp[i]);
        }
        else if(exp[i] == '^')
        {
            if(!isEmpty() && precedence(exp[i])==precedence(stack[top]))
            {
                pre[++toppre] = pop();
            }
            push(exp[i]);
        }
    }
    while(!isEmpty())
    {
        pre[++toppre] = pop();
    }
    pre[++toppre] = '\0';
    reverse(pre);
}

int main()
{
    char infix[30];
    scanf("%s",infix);
    prefix(infix);
    printf("%s",pre);
    return 0;
}