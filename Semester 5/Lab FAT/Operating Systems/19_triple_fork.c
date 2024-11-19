#include<unistd.h>
#include<stdio.h>
int main()
{
	printf("-------------------------------------\n");
	printf("\tCalling Triple Fork()\n");
	printf("-------------------------------------\n");
	//calling triple fork();
	fork();
	fork();
	fork();
	printf("Welcome to Chennai\n");
	return 0;
}
