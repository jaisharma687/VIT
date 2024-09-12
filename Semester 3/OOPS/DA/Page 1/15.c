# include <stdio.h>
# include <stdlib.h>

int main()
{
    char *txt;
    txt = (char *)malloc(100*sizeof(char));
    printf("Enter the text:\n");
    scanf("%[^\n]s",txt);
    printf("The output is:\n%s",txt);
    free(txt);
    return 0;
}