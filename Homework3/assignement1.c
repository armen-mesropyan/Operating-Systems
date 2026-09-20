#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();

	if(pid < 0)
	{
		perror("fork failed");
		return 1;
	}

	else if (pid == 0)
	{
		printf("Child PID = %d\n", getpid());
	}
	
    	else 
    	        printf("Parent PID = %d\n", getpid());

	return 0;
}