# include <stdio.h>

int main()
{
    int arr[10] = {5,9,45,64,3,4,1,7,99,38};
    int *ptr;
    ptr = arr;
    for(int i=0;i<10;i++)
    {
        printf("Key for %d elemet of the array is and its address is %x\n",*(ptr+i),ptr+i);
    }
    return 0;
}