# include <stdio.h>

int queue[20];
int front = -1;
int rear = -1;
int n;

void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void isFullEmpty()
{
    if(front > rear || front == -1)
        printf("Queue Empty\n");
    else if(rear == n-1)
        printf("Queue Full\n");
}

void enqueue(int x)
{
    if(front==-1)
    {
        front = 0;
    }
    queue[++rear] = x;
}

void dequeue()
{
    front++;
}

int main()
{
    printf("Enter the number of elements in Queue: ");
    scanf("%d",&n);
    isFullEmpty();
    for(int i=0;i<n;i++)
    {
        int ele;
        scanf("%d",&ele);
        enqueue(ele);
    }
    display();
    isFullEmpty();
    for(int i=0;i<n;i++)
    {
        dequeue();
        display();
        isFullEmpty();
    }
    return 0;
}