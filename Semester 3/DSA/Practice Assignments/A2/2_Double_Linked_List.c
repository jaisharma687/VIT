# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node *head=NULL,*tail=NULL,*newnode,*temp;

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

void create(int n)
{
    for(int i=0;i<n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        int x;
        scanf("%d",&x);
        newnode->data = x;
        newnode->next = newnode->prev = NULL;
        if(head==NULL)
            head = temp = newnode;
        else
        {
            newnode->prev = temp;
            temp->next = newnode;
            temp = newnode;
        }
    }
    tail = temp;
    display();
}

void insertend(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
    display();
}

void inserfront(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    head->prev = newnode;
    newnode->next = head;
    newnode->prev = NULL;
    head = newnode;
    display();
}

void insertpos(int x,int pos)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = newnode->next = NULL;
    temp = head;
    while(pos>2)
    {
        pos--;
        temp=temp->next;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    display();
}

void deleteele(int x)
{
    temp = head;
    struct node *temp2=NULL;
    while(temp->data!=x)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    display();
}

void search(int x)
{
    temp = head;
    int pos =1;
    while(temp->data!=x && temp->next!=NULL)
    {
        pos++;
        temp = temp->next;
    }
    if(temp->next == NULL)
        printf("Key not found\n");
    else
        printf("Key found at position %d\n",pos);
}

int main()
{
    create(5);
    insertend(6);
    inserfront(0);
    insertpos(7,3);
    deleteele(4);
    search(89);
    search(2);
    return 0;
}