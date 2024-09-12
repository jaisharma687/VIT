# include <stdio.h>
# include <stdlib.h>

struct bst
{
    int data;
    struct bst*right;
    struct bst* left;
};

struct bst*newnode;

struct bst*create(int x)
{
    newnode = (struct bst*)malloc(sizeof(struct bst));
    newnode->data = x;
    newnode->right = newnode->left = NULL;
    return newnode;
}

struct bst* insert(int x, struct bst *y)
{
    if(y==NULL)
        y = create(x);
    else if(x>y->data)
        y->right = insert(x,y->right);
    else if(x<y->data)
        y->left = insert(x,y->left);
    return y;
}

void preorder(struct bst *y)
{
    if (y == NULL)
        return;
    else
    {
        printf("%d ", y->data);
        preorder(y->left);
        preorder(y->right);
    }
}

void inorder(struct bst *y)
{
    if (y == NULL)
        return;
    else
    {
        inorder(y->left);
        printf("%d ", y->data);
        inorder(y->right);
    }
}

void postorder(struct bst *y)
{
    if (y == NULL)
        return;
    else
    {
        postorder(y->left);
        postorder(y->right);
        printf("%d ", y->data);
    }
}

struct bst* findmin(struct bst *y)
{
    if(y==0)
        return y;
    else if(y->left == NULL)
        return y;
    else 
        return findmin(y->left);
}

struct bst* deletenode(struct bst*y,int x)
{
    if(y==NULL)
        return y;
    if(y->data > x)
        y->left = deletenode(y->left,x);
    else if(y->data < x)
        y->right = deletenode(y->right,x);
    else
    {
        if(y->left == NULL)
        {
            struct bst*temp = y->right;
            free(y);
            return temp;
        }
        else if(y->right == NULL)
        {
            struct bst*temp = y->left;
            free(y);
            return temp;
        }
        else 
        {
            struct bst*min = findmin(y->right);
            y->data = min->data;
            y->right = deletenode(y->right,min->data);
        }
    }
    return y;
}

int main()
{
    struct bst *root;
    root = NULL;
    int n;
    root = insert(5,root);
    root = insert(10,root);
    root = insert(3,root);
    root = insert(2,root);
    root = insert(15,root);
    root = insert(6,root);
    root = insert(4,root);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    root = deletenode(root,6);
    inorder(root);
    printf("\n");
    root = insert(8,root);
    inorder(root);
    printf("\n");
    root = deletenode(root,5);
    inorder(root);
    printf("\n");
    return 0;
}