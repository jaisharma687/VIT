# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
    int height;
};

int height(struct node *head)
{
    if(head==NULL)
        return 0;
    else
        return head->height;
}

int max(int a,int b)
{
    return (a > b) ? a : b ;
}

struct node * create(int x)
{
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

struct node *rightrotation(struct node *temp)
{
    struct node *x = temp->left;
    struct node *y = x->right;
    x->right = temp;
    temp->left = y;
    temp->height = max(height(temp->left),height(temp->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}

struct node *leftrotation(struct node *temp)
{
    struct node *x = temp->right;
    struct node *y = x->left;
    x->left = temp;
    temp->right = y;
    temp->height = max(height(temp->left),height(temp->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}

int balancefactor(struct node *root)
{
    if(root==NULL)
        return 0;
    else
        return height(root->left) - height(root->right);
}

struct node *insert(struct node *root,int x)
{
    if(root==NULL)
        return create(x);
    if(x < root->data)
        root->left = insert(root->left,x);
    else if (x > root->data)
        root->right = insert(root->right,x);
    else
        return root;
    root->height = max(height(root->left),height(root->right))+1;
    int balance = balancefactor(root);
    if(balance>1 && x < root->left->data)
        return rightrotation(root);
    if(balance<-1 && x > root->right->data)
        return leftrotation(root);
    if(balance>1 && x > root->left->data)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if(balance<-1 && x < root->right->data)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
    return root;
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