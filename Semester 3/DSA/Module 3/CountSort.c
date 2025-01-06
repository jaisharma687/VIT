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
    int k=arr[0];
    for(int i=1;i<n;i++)
    {
        if(k<arr[i])
            k = arr[i];
    }
    int count[k+1];
    for(int i=0;i<=k;i++)
    {
        count[i] = 0;
    }
    int b[n];
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++)
    {
        count[i] += count[i-1];
    }
    for(int i =n-1;i>=0;i--)
    {
        b[--count[arr[i]]] = arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i] = b[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}