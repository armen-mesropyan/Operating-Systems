#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() 
{
	pid_t f1 = fork();
	if (f1 == 0) 
	{ 
		printf("Child 1\n"); 
		exit(0); 
	}
	
	pid_t f2 = fork();
	if (f2 == 0)
	{
		printf("Child 2\n"); 
		exit(0); 
	}

	waitpid(f2, NULL, 0);
	wait(NULL);

	return 0;
}
