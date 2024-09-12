# include <stdio.h>

void search(int n, int arr[],int ele)
{
    int found = 0;
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            found++;
            break;
        }
    }
    if(found)
        printf("Key found and position is %d",i+1);
    else
        printf("Key not found");
    
}

void input(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void display(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int m;
    scanf("%d",&m);
    int a[m];
    input(m,a);
    display(m,a);
    search(m,a,7);
    return 0;
}