#include <stdio.h>

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: \n");
    scanf("%s", str1);
    printf("Enter the second string: \n");
    scanf("%s", str2);
    int ident = 0;
    int len1 = 0;
    int len2 = 0;
    while (str1[len1] != '\0') 
    {
        len1++;
    }
    while (str2[len2] != '\0') 
    {
        len2++;
    }
    if (len1 != len2) 
    {
        ident++;
    }
    else 
    {
        for (int i = 0; i < len1; i++) {
            if (str1[i] != str2[i]) {
                ident++;
                break;
            }
        }
    }
    if (ident != 0) {
        printf("Strings are not equal\n");
    } else {
        printf("Strings are equal\n");
    }
    return 0;
}
