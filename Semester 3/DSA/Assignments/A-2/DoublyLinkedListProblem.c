# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*tail,*newnode,*temp,*traverse;

void printdll()
{
    temp = head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void inputdll(int n)
{
    while(n>0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            newnode->prev=0;
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        n--;
    }
    tail = temp;
}

void insertend(int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = 0;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void insertfront(int value)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = 0;
    newnode->next = head;
    head = newnode;
}

void insertpos(int pos,int value)
{
    int i =1;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    temp = head;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void deleteele(int ele)
{
    traverse = head;
    while(traverse->data != ele)
    {
        traverse= traverse->next;
    }
    temp = traverse->prev;
    temp->next = traverse->next;
    traverse->next->prev = traverse->prev;
    free(traverse);
}

void searchele(int ele)
{
    traverse = head;
    int pos=1;
    while(traverse->data != ele)
    {
        traverse = traverse->next;
        pos++;
    }
    printf("\nItem %d Found in position:%d",ele,pos);
}

int main()
{
    head = 0;
    inputdll(7);
    printdll();
    insertend(11);
    printf("\n");
    printdll();
    insertfront(12);
    printf("\n");
    printdll();
    insertpos(4,14);
    printf("\n");
    printdll();
    searchele(10);
    deleteele(9);
    printf("\n");
    printdll();
    return 0;
}