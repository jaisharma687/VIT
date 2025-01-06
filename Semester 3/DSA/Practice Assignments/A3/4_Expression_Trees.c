# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *create(char x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int top=-1;
struct node* stack[20];

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(struct node *x)
{
    stack[++top] = x;
}

struct node * pop()
{
    struct node *temp;
    temp = stack[top];
    top--;
    return temp;
}

int isoperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
        return 1;
    else
        return 0;
}

void inorder(struct node* x)
{
	if (x == NULL)
		return;
	else
    {
        inorder(x->left);
        printf("%c ", x->data);
        inorder(x->right);
	}
}

void preorder(struct node *y)
{
    if (y == NULL)
        return;
    else
    {
        printf("%c ", y->data);
        preorder(y->left);
        preorder(y->right);
    }
}

void postorder(struct node *y)
{
    if (y == NULL)
        return;
    else
    {
        postorder(y->left);
        postorder(y->right);
        printf("%c ", y->data);
    }
}

int main()
{
    char postfix[20];
    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    struct node *z;
    for(int i=0;i<strlen(postfix);i++)
    {
        if(isoperator(postfix[i]))
        {
            z = create(postfix[i]);
            z->right = pop();
            z->left = pop();
            push(z);
        }
        else
        {
            z = create(postfix[i]);
            push(z);
        }
    }
    struct node * root = pop();
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}