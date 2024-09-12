#include<stdio.h> 

int main() 
{ 
    int *p;
    int arr[5]; 
    int (*ptr)[5]; 
    p = arr;
    ptr = &arr;
    printf("p = %p, ptr = %p\n", p, ptr); 
    p++;  
    ptr++; 
    printf("p = %p, ptr = %p\n", p, ptr); 
    return 0; 
} 


