# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create()
{
    struct node *newnode;
    int x;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data (enter -1 for no node) : ");
    scanf("%d",&x);
    if(x==-1)
        return 0;
    else
    {
        newnode->data = x;
        printf("\nEnter left child of %d : ",x);
        newnode->left = create();
        printf("\nEnter right child of %d : ",x);
        newnode->right = create();
        return newnode;
    }
}

void preorder(struct node *root)
{
    if(root==0)
        return;
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root==0)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct node *root)
{
    if(root==0)
        return;
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root;
    root = NULL;
    root = create();
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    return 0;
}