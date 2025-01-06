#include <stdio.h>
#include <string.h>

int main() {
    char input_str[100];
    printf("Input the string: ");
    scanf("%s", input_str);
    printf("The characters of the string are :\n");
    int i = 0;
    while(input_str[i]!=0)
    {
        printf("%c\t",input_str[i]);
        i++;
    }
    return 0;
}