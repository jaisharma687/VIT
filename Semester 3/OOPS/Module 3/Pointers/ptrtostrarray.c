#include <stdio.h>
const int MAX = 4;
int main () 
{
    char *names[] = {"Samson", "Harish", "Nancy", "Saral"};
    int i = 0;
    for ( i = 0; i < MAX; i++) {
        printf("Value of names[%d] = %s\n", i, names[i] );
    }
    return 0;
}