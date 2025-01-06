# include <stdio.h>

int stack[20];
int top=-1;
int n;

void isFullEmpty()
{
    if(top==-1)
        printf("Stack Empty\n");
    else if(top==n-1)
        printf("Stack Full\n");
}

void push(int x)
{
    if(top == n-1)
    {
        printf("Stack Full\n");
    }
    else
    {
        stack[++top] = x;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack Empty\n");
    }
    else
    {
        top--;
    }
}

void display()
{
    printf("Stack is: ");
    for(int i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter number of elements in stack: ");
    scanf("%d",&n);
    isFullEmpty();
    for(int i=0;i<n;i++)
    {
        int ele;
        scanf("%d",&ele);
        push(ele);
    }
    display();
    isFullEmpty();
    pop();
    display();
    isFullEmpty();
    pop();
    display();
    isFullEmpty();
    pop();
    display();
    isFullEmpty();
    pop();
    display();
    isFullEmpty();
    pop();
    isFullEmpty();
    return 0;
}