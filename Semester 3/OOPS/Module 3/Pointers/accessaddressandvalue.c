#include <stdio.h>

int main () 
{
    int  v;
    scanf("%d",&v);
    int *input;
    input = &v;
    printf("Address of v variable: %x\n", &v  );
    printf("Address stored in input variable: %x\n", input );
    printf("Value of *input variable: %d\n", *input );
    return 0;
}
