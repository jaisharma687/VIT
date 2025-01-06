# include <stdio.h>

void merge(int a[],int lb, int mid, int ub)
{
    int i= lb;
    int j= mid+1;
    int k= lb;
    int b[ub+1];
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
            k++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }
    for(k=lb;k<=ub;k++)
    {
        a[k] = b[k];
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

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int i =0; i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}