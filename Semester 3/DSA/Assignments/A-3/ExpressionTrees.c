# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

struct node * create(char x)
{
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->right = newnode->left = NULL;
    return newnode;
}

struct node *root = NULL;
struct node* stack[20];
int top = -1;

void push(struct node *x)
{
    stack[++top] = x;
}

struct node *pop()
{
    struct node * temp = stack[top];
    top--;
    return temp;
}

void postordertoinorder(char s[])
{
    int l = strlen(s);
    struct node *z;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
        {
            z = create(s[i]);
            z->right = pop();
            z->left = pop();
            push(z);
        }
        else
        {
            z = create(s[i]);
            push(z);
        }
    }
}

void inorder(struct node* root)
{
	if (root == NULL)
		return;
	else
    {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
	}
}

int main()
{
    char stk[20];
    scanf("%s",stk);
    postordertoinorder(stk);
    root = pop();
    inorder(root);
    return 0;
}