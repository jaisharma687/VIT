#include <stdio.h>

int main() {
    int a = 20, i;
    printf("%d ", ++a);
    {
        int a = 30;
        for (i = 0; i < 3; i++) {
            printf("%d ", a); 
        }
    }
    printf("%d ", a);  
}