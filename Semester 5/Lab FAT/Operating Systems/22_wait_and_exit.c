#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	pid_t pd;
	printf("------------------------------------\n");
	printf("\twait() and exit()\n");
	printf("------------------------------------\n");
	//execution of fork() call
	if(fork()==0)
	{
		printf("Child is calling ...\n");
		//normal termination
		exit(0);
	}
	else
	{
		//get the PID of terminated child process
		pd = wait(NULL);
		printf("Parent is calling ...\n");
		//print the process IDs of parent and the child processes
		printf("Parent PID\t: %d\n",getppid());
		printf("Child PID\t: %d\n",pd);
	}
	return 0;
}
