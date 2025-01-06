# include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            arr[i] = 0;
        }
        else
        {
            arr[i] = 1;
        }
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}