# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp,*traverse;

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
        printf("Enter the data\n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        n--;
    }
    printll();
}

void insertfront(int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    printll();
}

void insertend(int value)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = 0;
    traverse = head;
    while(traverse->next!=0)
    {
        traverse = traverse -> next;
    }
    traverse->next = newnode;
    printll();
}

void insertafter(int ele,int elea)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ele;
    traverse = head;
    while(elea!=traverse->data)
    {
        traverse = traverse->next;
    }
    temp = traverse->next;
    traverse->next=newnode;
    newnode->next = temp;
    printll();
}

void insertbefore(int ele,int eleb)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ele;
    traverse = head;
    while(eleb!=traverse->data)
    {
        temp = traverse;
        traverse = traverse->next;
    }
    temp->next = newnode;
    newnode->next = traverse;
    printll();
}

void insertpos(int ele, int pos)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ele;
    int i=1;
    traverse = head;
    while(i<pos-1)
    {
        traverse = traverse->next;
        i++;
    }
    temp = traverse->next;
    traverse->next = newnode;
    newnode->next = temp;
    printll();
}

void deletefront()
{
    temp = head;
    head = head->next;
    free(temp);
    if(head==0)
    {
        printf("List is empty");
    }
    else
    {
        printf("\nAfter deleting front element:\n");
        printll();
    }
}

void deleteend()
{
    traverse = head;
    while(traverse->next!=0)
    {
        temp = traverse;
        traverse = traverse->next;
    }
    if(traverse==head)
    {
        head=0;
    }
    else
    {
        temp->next = 0;
    }
    free(traverse);
    printf("\nAfter deleting end element:\n");
    printll();
}

void deleteele(int delele)
{
    traverse = head;
    while(traverse->data!=delele)
    {
        temp=traverse;
        traverse=traverse->next;
    }
    temp->next = traverse->next;
    free(traverse);
    printll();
}

void deletepos(int position)
{
    int i=1;
    traverse=head;
    while(i<position)
    {
        temp=traverse;
        traverse=traverse->next;
        i++;
    }
    temp->next=traverse->next;
    free(traverse);
    printll();
}

void reversell()
{
    struct node *prevnode,*nextnode,*currentnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while(nextnode!=0)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
    printf("\nReversed linked list is:\n");
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
    if(temp->next==NULL)
        printf("Key not found\n");
    else
        printf("Key found at position %d\n",pos);
}

int main()
{    
    head = 0;
    int n,front,end,ele,eleafter,elebefore,pos,search;
    
    printf("Enter the number of elements you want to insert:\n");
    scanf("%d",&n);
    inputll(n);
    
    printf("\nEnter the element you want to insert in the front:\n");
    scanf("%d",&front);
    insertfront(front);
    
    printf("\nEnter the element you want to insert in the end:\n");
    scanf("%d",&end);
    insertend(end);
    
    printf("\nEnter the element you want to insert and the element after which you want to insert:\n");
    scanf("%d %d",&ele,&eleafter);
    insertafter(ele,eleafter);
    
    printf("\nEnter the element you want to insert and the element before which you want to insert:\n");
    scanf("%d %d",&ele,&elebefore);
    insertbefore(ele,elebefore);
    
    printf("\nEnter the element you want to insert and the position you want to insert:\n");
    scanf("%d %d",&ele,&pos);
    insertpos(ele,pos);
    
    deletefront();
    
    deleteend();
    
    printf("\nEnter the element you want to delete:\n");
    scanf("%d",&ele);
    deleteele(ele);
    
    printf("\nEnter the position you want to delete:\n");
    scanf("%d",&pos);
    deletepos(pos);
    
    reversell();

    printf("\nEnter the element you want to search:\n");
    scanf("%d",&search);
    searchele(search);

    return 0;
}