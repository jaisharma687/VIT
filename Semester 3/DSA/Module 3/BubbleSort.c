# include <stdio.h>

int main()
{
    int arr[100];
    int n,temp;
    scanf("%d",&n);
    for(int i = 0; i<n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        int ifswap=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                ifswap++;
            }
        }
        if(ifswap==0)
            break;
    }
    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}