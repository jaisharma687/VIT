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

void insertafterele(int ele,int elea)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ele;
    traverse = head;
    while(traverse->data != elea)
    {
        traverse = traverse->next;
    }
    newnode->prev = traverse;
    newnode->next = traverse->next;
    traverse->next->prev = newnode;
    traverse->next = newnode;
}

void insertbeforeele(int ele,int eleb)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ele;
    while(traverse->data != eleb)
    {
        temp = traverse;
        traverse = traverse->next;
    }
    newnode->prev = temp;
    newnode->next = traverse;
    temp->next = newnode;
    traverse->prev = newnode;
}

void deletefront()
{
    temp = head;
    head = head->next;
    head->prev=0;
    free(temp);
}

void deleteend()
{
    temp = tail;
    tail = tail->prev;
    tail->next = 0;
    free(temp);
}

void deletepos(int pos)
{
    int i =1;
    traverse = head;
    while(i<pos-1)
    {
        traverse = traverse->next;
        i++;
    }
    temp = traverse->next;
    traverse->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
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

void reversedll()
{
    struct node *current,*nextnode;
    current = head;
    while(current!=0)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }
    temp = head;
    head = tail;
    tail = temp;
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
    insertafterele(17,10);
    printf("\n");
    printdll();
    insertbeforeele(7,6);
    printf("\n");
    printdll();
    searchele(10);
    deletefront();
    printf("\n");
    printdll();
    deleteend();
    printf("\n");
    printdll();
    deletepos(5);
    printf("\n");
    printdll();
    deleteele(10);
    printf("\n");
    printdll();
    reversedll();
    printf("\n");
    printdll();
    return 0;
}
