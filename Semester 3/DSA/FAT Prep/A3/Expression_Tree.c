# include <stdio.h>
# include <stdlib.h>

struct tree
{
    char data;
    struct tree *right;
    struct tree *left;
};

struct tree *newnode;

struct tree *create(char x)
{
    newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->data = x;
    newnode->right = newnode->left = NULL;
    return newnode;
}

struct tree* stack[20];
int top=-1;

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(struct tree *x)
{
    stack[++top] = x;
}

struct tree* pop()
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

void inorder(struct tree *y)
{
    if (y == NULL)
        return;
    else
    {
        inorder(y->left);
        printf("%c ", y->data);
        inorder(y->right);
    }
}

int main()
{
    char exp[20];
    scanf("%s",exp);
    struct tree *x, *y, *z;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(!isOperator(exp[i]))
        {
            z = create(exp[i]);
            push(z);
        }
        else
        {
            x = pop();
            y = pop();
            z = create(exp[i]);
            z->left = y;
            z->right = x;
            push(z);
        }
    }
    struct tree * root = pop();
    inorder(root);
    return 0;
}