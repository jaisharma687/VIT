# include <stdio.h>
# include <stdlib.h>

struct tree
{
    int data;
    struct tree*right;
    struct tree*left;
    int height;
};

struct tree *newnode;

struct tree *create(int x)
{
    newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int getheight(struct tree *y)
{
    if(y==NULL)
        return 0;
    else
        return y->height;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int balancefactor(struct tree *y)
{
    if(y==NULL)
        return 0;
    else
        return getheight(y->left) - getheight(y->right);
}

struct tree * right(struct tree *y)
{
    struct tree *b = y->left;
    struct tree * temp = b->right;
    b->right = y;
    y->left = temp;
    y->height = max(getheight(y->left),getheight(y->right))+1;
    b->height = max(getheight(b->left),getheight(b->right))+1;
    return b;
}

struct tree * left(struct tree *y)
{
    struct tree *b= y->right;
    struct tree *temp = b->left;
    b->left = y;
    y->right = temp;
    y->height = max(getheight(y->left),getheight(y->right))+1;
    b->height = max(getheight(b->left),getheight(b->right))+1;
    return b;
}

struct tree *insert(int x, struct tree *y)
{
    if(y==NULL)
        return create(x);
    if(x<y->data)
        y->left = insert(x,y->left);
    else if(x>y->data)
        y->right = insert(x,y->right);
    else
        return y;
    y->height = max(getheight(y->left),getheight(y->right))+1;
    int balance = balancefactor(y);
    if(balance>1 && x<y->left->data)
        return right(y);
    else if(balance<-1 && x>y->right->data)
        return left(y);
    else if(balance>1 && x>y->left->data)
    {
        y->left = left(y->left);
        return right(y);
    }
    else if(balance<-1 && x<y->right->data)
    {
        y->right = right(y->right);
        return left(y);
    }
    return y;
}

void preorder(struct tree *y)
{
    if(y==0)
        return;
    else
    {
        printf("%d ",y->data);
        preorder(y->left);
        preorder(y->right);
    }
}

void postorder(struct tree *y)
{
    if(y==0)
        return;
    else
    {
        postorder(y->left);
        postorder(y->right);
        printf("%d ",y->data);
    }
}

void inorder(struct tree *y)
{
    if(y==NULL)
        return;
    else
    {
        inorder(y->left);
        printf("%d ",y->data);
        inorder(y->right);
    }
}

int main()
{
    struct tree *root = NULL;
    root = insert(10,root);
    root = insert(20,root);
    root = insert(30,root);
    root = insert(40,root);
    root = insert(50,root);
    root = insert(25,root);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}