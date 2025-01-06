#include <stdio.h>
#include <string.h>

int main() {
    char input_str[100];
    printf("Input the string: ");
    fgets(input_str, sizeof(input_str), stdin);
    int words=1;
    int i=0;
    while(input_str[i]!=0)
    {
        if(input_str[i]==' ')
        {
            words++;
        }
        i++;
    }
    printf("Total number of words in the string is :%d\n",words);
    return 0;
}