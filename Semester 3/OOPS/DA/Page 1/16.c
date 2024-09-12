# include <stdio.h>
# include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of inputs in array:\n");
    scanf("%d",&n);
    int *arr;
    arr = (int *)malloc(n*sizeof(int));
    int sum =0;
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",(arr+i));
        sum += *(arr+i);
    }
    for(int i=0;i<n;i++)
        printf("Element %d is: %d\n",i+1,*(arr+i));
    printf("Sum of all elemets is: %d",sum);
    free(arr);
    return 0;
}