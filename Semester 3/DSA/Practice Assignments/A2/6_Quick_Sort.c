# include <stdio.h>

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

void swap(int * a,int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while(start<=end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
            swap(&a[end],&a[start]);
    }
    swap(&a[end],&a[lb]);
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
    input(n,arr);
    display(n,arr);
    quicksort(arr,0,n-1);
    display(n,arr);
    return 0;
}