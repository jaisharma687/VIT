# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>

int topstack = -1;
int toppostfix = -1;

char postfix[100];
char stack[100];

int precedence(char a)
{
    if(topstack>-1)
    {
        char b = stack[topstack];
        int ap = getpriority(a);
        int bp = getpriority(b);
        if(ap = bp)
        {
            if(associativity(a))
            {
                pushstack(a);
            }
            else
            {
                pushpostfix(popstack());
                precedence(a);
            }
        }
        else if(ap>bp)
        {
            pushstack(a);
        }
        else if(ap<bp)
        {
            pushpostfix(popstack());
            precedence(a);
        }
    }
    else if (topstack==-1)
    {
        pushstack(a);
    }
}

int getpriority(char a)
{
    int getp;
    if(a=='+'||a=='-')
        return getp = 0;
    else if(a=='*'||a=='/'||a=='^')
        return getp = 1;
}

int associativity(char a)
{
    int asso;
    if(a=='+'||a=='-')
        return asso = 1;
    else if(a=='*'||a=='/'||a=='^')
        return asso = 0;
}

void pushstack(char a)
{
    stack[++topstack] = a;
}

void pushpostfix(char a)
{
    postfix[++toppostfix] = a;
}

char popstack()
{
    char a = stack[topstack];
    topstack--;
    return a;
}

void infixtopostfix(char a)
{
    if(isdigit(a)||isalpha(a))
    {
        pushpostfix(a);
    }
    else
    {
        char b = stack[topstack];
        if(a=='(')
        {
            pushstack(a);
        }
        else if(b=='(')
        {
            pushstack(a);
        }
        else if(a==')')
        {
            while(b!='(')
            {
                pushpostfix(popstack());
                topstack--;
            }
        }
        else
        {
            precedence(a);
        }
    }
}

int main()
{
    char infix[100];
    fgets(infix, sizeof(infix), stdin);
    for(int i=0;i<sizeof(infix);i++)
    {
        infixtopostfix(infix[i]);
    }
    printf("\n%s",postfix);
    return 0;
}