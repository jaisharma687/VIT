# include <stdio.h>

int main()
{
    int arr[10];
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    int ele,pos;
    scanf("%d %d", &ele , &pos);
    for(int i = n-1;i>=pos-1;i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos] = ele;
    for(int i = 0;i<n+1;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}