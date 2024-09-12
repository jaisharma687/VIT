# include <stdio.h>

void swap(int *a,int *b)
{   
    int temp= *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int lb,int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while(start <= end)
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while (a[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[lb],&a[end]);
    return end;
}

void quicksort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc = partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
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
    quicksort(arr,0,n-1);
    printf("Sorted array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}