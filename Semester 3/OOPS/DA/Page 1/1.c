# include <stdio.h>

int main()
{
    int *ptr, n; //create
    ptr = &n; //assign
    n = 10; // intialize
    printf("Number is: %d and its address is: %x",*ptr,ptr); //access
    return 0;
}