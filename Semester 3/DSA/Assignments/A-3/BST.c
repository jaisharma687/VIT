# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = 0;
    newnode->right = 0;
    return newnode;
}

struct node *insert(struct node *head,int x)
{
    if(head == 0)
        head = create(x);
    else if (x < head->data)
        head->left = insert(head->left,x);
    else
        head->right = insert(head->right,x);
    return head;
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

struct node* deleteelement(struct node* head, int k)
{
    if (head == NULL)
        return head;
    if (k < head->data) 
    {
        head->left = deleteelement(head->left, k);
        return head;
    }
    else if (k > head->data) 
    {
        head->right = deleteelement(head->right, k);
        return head;
    }
    if (head->left == NULL) 
    {
        struct node* temp = head->right;
        free(head);
        return temp;
    }
    else if (head->right == NULL) 
    {
        struct node* temp = head->left;
        free(head);
        return temp;
    }
    else 
    {
        struct node* insucc = head;
        struct node* succ = head->right;
        while (succ->left != NULL) 
        {
            insucc = succ;
            succ = succ->left;
        }
        if (insucc != head)
            insucc->left = succ->right;
        else
            insucc->right = succ->right;
        head->data = succ->data;
        free(succ);
        return head;
    }
}

int main()
{
    struct node *root = NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        root = insert(root,k);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    deleteelement(root,6);
    inorder(root);
    printf("\n");
    root = insert(root,8);
    inorder(root);
    printf("\n");
    deleteelement(root,5);
    inorder(root);
    return 0;
}