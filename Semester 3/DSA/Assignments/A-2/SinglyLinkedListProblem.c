# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp;

void printll()
{
    temp = head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void inputll(int n)
{
    while(n>0)
    {   
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head = temp =newnode;
        }
        else
        {
            temp->next=newnode;
            temp = newnode;
        }
        n--;
    }
}

void insertend(int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    temp = head;
    while(temp->next!=0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = 0;
    printll();
}

void insertfront(int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head = newnode;
    printll();
}

void insertpos(int pos,int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    int i=1;
    temp = head;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    struct node *temp2;
    temp2= temp->next;
    temp->next = newnode;
    newnode->next = temp2;
    printll();
}

void deleteele(int value)
{
    temp=head;
    struct node *temp2;
    while(temp->data!=value)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
    free(temp);
    printll();
}

void searchele(int value)
{
    temp = head;
    int pos =1;
    while(temp->data!=value)
    {
        temp = temp->next;
        pos++;
    }
    printf("\nItem %d Found in position:%d\n",value,pos);
}

int main()
{
    head = 0;
    inputll(7);
    printll();
    printf("\n");
    insertend(11);
    printf("\n");
    insertfront(12);
    printf("\n");
    insertpos(4,14);
    searchele(10);
    deleteele(9);
    return 0;
}