#include<unistd.h>
#include<stdio.h>
int main()
{
	printf("----------------------------------\n");
	printf("\tSimple Fork()\n");
	printf("----------------------------------\n");
	//calling fork()
	fork();
	printf("Hello World\n");
	return 0;
}
