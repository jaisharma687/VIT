# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node* create(int x)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int height(struct node *x)
{
    if(x==NULL)
        return 0;
    else
        return x->height;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

struct node *rightrotation(struct node * z)
{
    struct node *x = z->left;
    struct node *y = x->right;
    x->right = z;
    z->left = y;
    z->height = max(height(z->left),height(z->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}


struct node *leftrotation(struct node *z)
{
    struct node *x = z->right;
    struct node *y = x->left;
    x->left = z;
    z->right = y;
    z->height = max(height(z->left),height(z->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}

int balancefactor(struct node *z)
{
    if(z==NULL)
        return 0;
    else
        return height(z->left) - height(z->right);
}

struct node *insert(struct node *z,int x)
{
    if(z==NULL)
        return create(x);
    if(x<z->data)
        z->left = insert(z->left,x);
    else if(x>z->data)
        z->right = insert(z->right,x);
    else
        return z;
    z->height = max(height(z->left),height(z->right))+1;
    int balance = balancefactor(z);
    if(balance>1 && x < z->left->data)
        return rightrotation(z);
    if(balance<-1 && x > z->right->data)
        return leftrotation(z);
    if(balance>1 && x > z->left->data)
    {
        z->left = leftrotation(z->left);
        return rightrotation(z);
    }
    if(balance<-1 && x < z->right->data)
    {
        z->right = rightrotation(z->right);
        return leftrotation(z);
    }
    return z;
}

void preorder(struct node *head)
{
    if(head==0)
        return;
    else
    {
        printf("%d ",head->data);
        preorder(head->left);
        preorder(head->right);
    }
}

void postorder(struct node *head)
{
    if(head==0)
        return;
    else
    {
        postorder(head->left);
        postorder(head->right);
        printf("%d ",head->data);
    }
}

void inorder(struct node *head)
{
    if(head==0)
        return;
    else
    {
        inorder(head->left);
        printf("%d ",head->data);
        inorder(head->right);
    }
}

int main()
{
    struct node *root = NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int d;
        scanf("%d",&d);
        root = insert(root,d);
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}