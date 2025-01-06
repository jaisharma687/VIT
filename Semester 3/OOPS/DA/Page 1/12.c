# include <stdio.h>

int main()
{
    int n =100;
    int *ptr;
    ptr = &n;
    if(ptr == NULL)
		printf("ptr is NULL\n");
	else
		printf("ptr is NOT NULL\n");
    ptr = 0;
    if(ptr == NULL)
		printf("ptr is NULL\n");
	else
		printf("ptr is NOT NULL\n");
    return 0;
}