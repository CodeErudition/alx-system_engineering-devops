#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * infinite_while - A function that runs an infinite loop to
 * keep the program running.
 *
 * Return: Always returns 0.
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Creates 5 zombie processes.
 *
 * Description: The program forks 5 child processes. Each child process
 *              exits immediately, becoming a zombie process. The parent
 *              process does not collect the exit status of the children,
 *              leaving them in the zombie state. The parent process
 *              then enters an infinite loop to keep running.
 *
 * Return: Always returns 0.
 */

int main(void)
{
	pid_t child_pid;
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid > 0)
		{
			printf("Zombie process created, PID: %d\n", child_pid);
		}
		else if (child_pid == 0)
		{
			exit(0);
		}
		else
		{
			perror("fork");
			exit(1);
		}
	}

	infinite_while();

	return (0);
}
