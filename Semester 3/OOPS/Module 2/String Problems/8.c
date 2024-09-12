#include <stdio.h>

int main() 
{
    char str1[100], str2[100];
    int i;
    printf("Input the string: ");
    fgets(str1, sizeof(str1), stdin);
    for (i = 0; str1[i] != '\0'; i++) {
        str2[i] = str1[i];
    }
    str2[i] = '\0';
    printf("The First string is: %s", str1);
    printf("The Second string is: %s", str2);
    printf("Number of characters copied: %d\n", i);
    return 0;
}
