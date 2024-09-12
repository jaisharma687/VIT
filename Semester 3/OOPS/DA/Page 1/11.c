#include <stdio.h>

int main(void) 
{
	int n = 10;
	int *ptr1 = &n;
	int *ptr2=0;
	int *ptr3=0;
	if(ptr1 == 0)
		printf("ptr1: NULL\n");
	else
		printf("ptr1: NOT NULL\n");
	if(ptr2 == 0)
		printf("ptr2: NULL\n");
	else
		printf("ptr2: NOT NULL\n");
	if(ptr3 == 0)
		printf("ptr3: NULL\n");
	else
		printf("ptr3: NOT NULL\n");
	return 0;
}
