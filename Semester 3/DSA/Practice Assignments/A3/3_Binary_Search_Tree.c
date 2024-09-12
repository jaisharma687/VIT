#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(int x, struct node *y)
{
    if (y == NULL)
        y = create(x);
    else if (x < y->data)
        y->left = insert(x, y->left);
    else if (x > y->data)
        y->right = insert(x, y->right);
    return y;
}

void preorder(struct node *y)
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

void inorder(struct node *y)
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

void postorder(struct node *y)
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

struct node *findmin(struct node *y)
{
    if (y == NULL)
        return y;
    else if (y->left == NULL)
        return y;
    else
        return findmin(y->left);
}

struct node *findmax(struct node *y)
{
    if (y == NULL)
        return y;
    else if (y->right == NULL)
        return y;
    else
        return findmax(y->right);
}

struct node *deletenode(int x, struct node *y)
{
    if (y == NULL)
        return y;
    if (x < y->data)
    {
        y->left = deletenode(x, y->left);
        return y;
    }
    else if (x > y->data)
    {
        y->right = deletenode(x, y->right);
        return y;
    }
    if (y->left == NULL)
    {
        struct node *temp = y->right;
        free(y);
        return temp;
    }
    else if (y->right == NULL)
    {
        struct node *temp = y->left;
        free(y);
        return temp;
    }
    else
    {
        // struct node *maxnode;
        // maxnode = findmax(y->left);
        // y->data = maxnode->data;
        // y->left = deletenode(maxnode->data, y->left);

        struct node* minnode = findmin(y->right);
        y->data = minnode->data;
        y->right = deletenode(minnode->data,y->right);

        return y;
    }
}

int main()
{
    struct node *root;
    root = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int ele;
        scanf("%d", &ele);
        root = insert(ele, root);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    root = deletenode(6, root);
    inorder(root);
    printf("\n");
    root = deletenode(5, root);
    inorder(root);
    printf("\n");
    return 0;
}
