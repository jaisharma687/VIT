#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{
	pid_t id;
	printf("-----------------------------------\n");
	printf("\tReturn Code of Parent & Child\n");
	printf("-----------------------------------\n");
	//calling fork()
	id=fork();
	if(id==0)
	{
		printf("Child Process is calling ...\n");
		printf("Return Value of Child Process : %d\n",id);
	}
	else
	{
		printf("Parent Process is calling ...\n");
		printf("Returned Value of Parent Process : %d\n",id);
	}
	return 0;
}
