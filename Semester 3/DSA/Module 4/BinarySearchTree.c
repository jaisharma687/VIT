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
        struct node* maxnode = findmax(head->left);
        head->data = maxnode->data;
        head->left = deleteelement(head->left, maxnode->data);
        return head;

        // struct node* minnode = findmin(head->right);
        // head->data = minnode->data;
        // head->right = deleteelement(head->right, minnode->data);
        // return head;
    }
}

void kthMinimum(struct node* head, int k, int* count, int* result) 
{
    if (head == NULL || *count >= k) 
    {
        return;
    }
    kthMinimum(head->left, k, count, result);
    (*count)++;
    if (*count == k) 
    {
        *result = head->data;
        return;
    }
    kthMinimum(head->right, k, count, result);
}

int main()
{
    struct node *root = NULL;
    int x, k;
    int count = 0;
    int result = 0;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 55);
    root = insert(root, 70);
    root = insert(root, 80);


    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Searching for 40: ");
    struct node *searchResult = NULL;
    searchResult = search(root, 40);
    if (searchResult != NULL)
        printf("Found\n");
    else
        printf("Not Found\n");

    root = deleteelement(root, 70);
    inorder(root);
    printf("\n");
    root = deleteelement(root, 30);
    inorder(root);
    printf("\n");
    root = deleteelement(root, 15);
    inorder(root);
    printf("\n");

    printf("Enter k for finding kth minimum: ");
    scanf("%d", &k);
    kthMinimum(root, k, &count, &result);
    if (count >= k)
        printf("The %dth minimum value is: %d\n", k, result);
    else
        printf("There are fewer than %d elements in the tree\n", k);
    return 0;
}