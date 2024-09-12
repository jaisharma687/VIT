# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev;
};

struct node *head,*tail,*temp,*newnode;

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
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head==NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        tail = temp;
        n--;
    }
    display();
}

void insert(int x, int pos)
{
    if(pos == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;
        temp = head;
        while(pos>2)
        {
            temp = temp->next;
            pos--;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
    display();
}

void insertend(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    display();
}

void deleteele(int x)
{
    temp = head;
    while(temp->data != x)
        temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    display();
}

int search(int x)
{
    temp = head;
    int pos=1;
    while(temp->data != x && temp!=NULL)
    {
        temp = temp->next;
        pos++;
    }
    if(temp==0)
        return 0;
    else
        return pos;
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