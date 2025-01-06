# include <stdio.h>
# include <math.h>

int stack[20];
int top=-1;

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    if(!isEmpty())
        return stack[top--];
}

int isOperator(char x)
{
    if(x == '+' || x == '-' || x == '/' || x == '*' || x == '^')
        return 1;
    else 
        return 0;
}

int evaluation(char exp[])
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if(isOperator(exp[i]))
        {
            int a = pop();
            int b = pop();
            int result;
            switch(exp[i])
            {
                case '+': result = b+a; break;
                case '-': result = b-a; break;
                case '*': result = b*a; break;
                case '/': result = b/a; break;
                case '^': result = pow(b,a); break;
            }
            push(result);
        }
        else
            push((int)exp[i]-'0');
    }
    int final=pop();
}

int main()
{
    char postfix[20];
    scanf("%s",postfix);
    printf("%d",evaluation(postfix));
}