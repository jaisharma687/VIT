#include <stdio.h>
#include <string.h>

int main() {
    char input_str[100];
    printf("Input the string: ");
    scanf("%s", input_str);
    printf("The characters of the string are :\n");
    for(int i=strlen(input_str)-1;i>=0;i--)
    {
        printf("%c\t",input_str[i]);
    }
    return 0;
}