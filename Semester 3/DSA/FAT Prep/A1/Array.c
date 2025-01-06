# include <stdio.h>

int n;

void display(int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int search(int arr[],int search)
{
    int j=0;
    while(arr[j]!=search && j<n)
    {
        j++;
    }
    if(j==n)
    {
        return 0;
    }
    else
    {
        return j;
    }
}

void deleteelement(int arr[])
{
    int del;
    printf("Enter the element to delete: ");
    scanf("%d",&del);
    int posin;
    posin = search(arr,del);
    for(int i=posin;i<n-1;i++)
    {
        arr[i] = arr[i+1];
    }
    n--;
}

void input(int arr[])
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void insert(int arr[])
{
    int in, pos;
    printf("Enter the element to insert and pos: ");
    scanf("%d %d",&in,&pos);
    for(int i=n;i>=pos-1;i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos-1] = in;
    n++;
}

int main()
{
    int arr[20];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    input(arr);
    insert(arr);
    display(arr);
    deleteelement(arr);
    display(arr);
    int sea;
    printf("Enter the element to search: ");
    scanf("%d",&sea);
    int s = search(arr,sea);
    if(s)
    {
        printf("Found");
    }
    else
    {
        printf("Not found");
    }
    return 0;
}