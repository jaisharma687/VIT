# include <stdio.h>

void merge(int a[],int lb,int mid,int ub)
{
    int i = lb;
    int j = mid+1;
    int b[ub+1];
    int k = lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for(int i=lb;i<=ub;i++)
    {
        a[i] = b[i];
    }
}

void mergesort(int a[],int lb,int ub)
{
    if(lb<ub)
    {    
        int mid = (lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
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
    int n;
    scanf("%d",&n);
    int arr[n];
    input(n,arr);
    display(n,arr);
    mergesort(arr,0,n-1);
    display(n,arr);
    return 0;
}