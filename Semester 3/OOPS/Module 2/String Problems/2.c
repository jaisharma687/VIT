#include <stdio.h>

int main() {
    char input_str[100];
    int length = 0;
    printf("Input the string: ");
    scanf("%s", input_str);
    while (input_str[length] != '\0') 
    {
        length++;
    }
    printf("Length of the string is: %d\n", ++length);
    return 0;
}