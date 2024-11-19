#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{
	int id;
	printf("-------------------------------------\n");
	printf("\tProcess ID of Parent & Child\n");
	printf("-------------------------------------\n");
	//calling fork()
	id=fork();
	if(id==0)
	{
		printf("Child Process is calling ...\n");
		printf("Process ID (PID) of Child Process : %d\n",getpid());
	}
	else
	{
		printf("Parent Process is calling ...\n");
		printf("Process ID (PID) of Parent Process : %d\n",getppid());
	}
	return 0;
}
