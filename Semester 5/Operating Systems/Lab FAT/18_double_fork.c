#include<unistd.h>
#include<stdio.h>
int main()
{
	printf("----------------------------------\n");
	printf("\tCalling Double Fork()\n");
	printf("----------------------------------\n");
	//caling double fork()
	fork();
	fork();
	printf("Good Morning\n");
	return 0;
}
