# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head,*temp,*newnode;

void display()
{
    temp = head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void create(int n)
{
    while(n>0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next =0;
        if(head==0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        n--;
    }
    display();
}

void insert(int x, int pos)
{
    if(pos==1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = head;
        head = newnode;
    }
    else
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
    }
    display();
}

void insertend(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    temp = head;
    while(temp->next!=0)
        temp = temp->next;
    temp->next = newnode;
    display();
}

int search(int x)
{
    temp = head;
    int pos=1;
    while(x!=temp->data && temp!=NULL)
    {
        temp = temp->next;
        pos++;
    }
    if(temp==NULL)
        return 0;
    else
        return pos;
}

void deleteele(int x)
{
    temp = head;
    struct node *prev;
    while(temp->data!=x)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    display();
}

int main()
{
    head = 0;
    create(7);
    insertend(11);
    insert(12,1);
    insert(14,4);
    deleteele(9);
    int pos = search(10);
    if(pos)
        printf("Element found at pos:%d",pos);
    else
        printf("Not found");
    return 0;
}