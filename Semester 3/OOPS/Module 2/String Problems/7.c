#include <stdio.h>

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    int alpha = 0;
    int digits = 0;
    int spchar = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') 
        {
            digits++;
        } 
        else if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) 
        {
            alpha++;
        } 
        else 
        {
            spchar++;
        }
        i++;
    }
    printf("Number of Alphabets in the string: %d\n", alpha);
    printf("Number of Digits in the string: %d\n", digits);
    printf("Number of Special Characters in the string: %d\n", spchar);
    return 0;
}
