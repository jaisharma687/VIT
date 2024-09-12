#include <stdio.h>
#include <time.h>

int* getRandom() 
{
    static int  r[10];
    int i;
    for ( i = 0; i < 5; ++i) {
        r[i] = rand();
        printf("%d\n", r[i] );
    }
    return r;
}

int main () 
{
    int *p;
    int i;
    p = getRandom();
    for ( i = 0; i < 5; i++ )
        printf("*(p + [%d]) : %d\n", i, *(p + i) );
    return 0;
}


