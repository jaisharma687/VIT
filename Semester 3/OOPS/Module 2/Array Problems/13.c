# include <stdio.h>

int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<9;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}