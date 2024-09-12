# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *head = NULL, *newnode,*temp;

struct node* create(int n)
{
    for(int i=0;i<n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        int x;
        scanf("%d",&x);
        newnode->data = x;
        newnode->next = NULL;
        if(head==NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void display()
{
    temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertend(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newnode;
    display();
}

void insertfront(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    display();
}

void insertpos(int x,int pos)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    temp = head;
    while(pos>2)
    {
        temp = temp->next;
        pos--;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    display();
}

void deleteele(int x)
{
    temp = head;
    struct node *temp2 = NULL;
    while(temp->data!=x)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
    free(temp);
    display();
}

void search(int x)
{
    temp = head;
    int pos=1;
    int found =0;
    while(temp->data!=x && temp->next!=NULL)
    {
        pos++;
        temp = temp->next;
    }
    if(temp->next==NULL)
        printf("Key not found\n");
    else
        printf("Key found at position %d\n",pos);
}

int main()
{
    create(5);
    display();
    insertend(6);
    insertfront(0);
    insertpos(45,3);
    deleteele(4);
    search(45);
    search(10);
    return 0;
}