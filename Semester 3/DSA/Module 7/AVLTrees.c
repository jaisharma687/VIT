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

struct node *findmin(struct node *head)
{
    if(head==0)
        return head;
    else if(head->left == 0)
        return head;
    else
        return findmin(head->left);
}

struct node *findmax(struct node *head)
{
    if(head==0)
        return 0;
    else if(head->right == 0)
        return head;
    else
        return findmax(head->right);
}

struct node *deletenode(struct node * root, int x)
{
    struct node *temp;
    if(root == NULL)
        return root;
    if(x < root->data)
        root->left = deletenode(root->left,x);
    else if(x > root->data)
        root->right = deletenode(root->right,x);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            // struct node *temp = findmin(root->right);
            // root->data = temp->data;
            // root->right = deletenode(root->right, temp->data);

            struct node* temp = findmax(root->left);
            root->data = temp->data;
            root->left = deletenode(root->left, temp->data);
        }
    }
    if(root == NULL)
        return root;
    root->height = max(height(root->left),height(root->right))+1;
    int balance = balancefactor(root);
    if(balance>1 && balancefactor(root->left)>=0)
        return rightrotation(root);
    if(balance<-1 && balancefactor(root->right)<=0)
        return leftrotation(root);
    if(balance>1 && balancefactor(root->left)<0)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if(balance<-1 && balancefactor(root->right)>0)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
    return root;
}

struct node* search(struct node* head, int x)
{
    if (head == 0)
        return NULL;
    else if (x < head->data)
        return search(head->left, x);
    else if (x > head->data)
        return search(head->right, x);
    else
        return head;
}

int main()
{
    struct node *root = NULL;
    int n;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int d;
        printf("Enter the data %d: ",i+1);
        scanf("%d",&d);
        root = insert(root,d);
        printf("Inorder after inserting %d :",d);
        inorder(root);
        printf("\n");
        printf("Preorder after inserting %d :",d);
        preorder(root);
        printf("\n");
        printf("Postorder after inserting %d :",d);
        postorder(root);
        printf("\n");
    }
    int del;
    printf("Enter the number of elements to delete: ");
    scanf("%d",&del);
    for(int i=0;i<del;i++)
    {
        int ele;
        printf("Enter the element to delete: ");
        scanf("%d",&ele);
        root = deletenode(root,ele);
        printf("Inorder after deleting %d :",ele);
        inorder(root);
        printf("\n");
        printf("Preorder after deleting %d :",ele);
        preorder(root);
        printf("\n");
        printf("Postorder after deleting %d :",ele);
        postorder(root);
        printf("\n");
    }
    int s;
    printf("Enter the element to search: ");
    scanf("%d",&s);
    printf("Searching for %d: ",s);
    struct node *searchResult = NULL;
    searchResult = search(root, s);
    if (searchResult != NULL)
        printf("Found\n");
    else
        printf("Not Found\n");
    return 0;
}