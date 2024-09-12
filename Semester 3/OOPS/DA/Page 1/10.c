# include <stdio.h>

int main()
{
    int arr[10] = {1,2,0,5,6,7,3,4,9,8};
    int *ptr[10];
    for(int i=0;i<10;i++)
    {
        ptr[i] = &arr[i];
    }
    for(int i=0;i<10;i++)
        printf("Element %d has value %d and address %x\n",i+1,arr[i],ptr[i]);
    return 0;
}