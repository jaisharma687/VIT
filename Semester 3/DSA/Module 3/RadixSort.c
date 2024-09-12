# include <stdio.h>

int getMax(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(max<a[i])
            max = a[i];
    }
    return max;
}

void countsort(int a[],int n, int pos)
{
    int count[10] = {0};
    int b[n];
    for(int i=0;i<n;i++)
    {
        count[(a[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++)
    {
        count[i] += count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        b[--count[(a[i]/pos)%10]] = a[i];
    }
    for(int i=0;i<n;i++)
    {
        a[i] = b[i];
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max = getMax(arr,n);
    for(int pos = 1; max/pos>0; pos *= 10)
    {
        countsort(arr,n,pos);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}