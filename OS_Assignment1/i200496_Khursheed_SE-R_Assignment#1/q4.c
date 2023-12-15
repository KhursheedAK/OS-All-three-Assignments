// Khursheed Alam Khan		Assignment#1: Answer to Question 4
// 20i-0496
// SE-R

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{	// start of main function
	
	char* argument_list[] = {"grep", "-n", "out", "q4_pdf.txt", NULL};
	
	printf("Process ID: %d\n", getpid());
	printf("\n");
	int P1 = fork();
	
	if(P1 == 0)	// child process
	{
		printf("Child process ID: %d\n", getpid());
		printf("Parent process ID: %d\n", getppid());
		printf("\n");
		execvp("grep", argument_list);
	}
	
	else if(P1<0)	// failed fork
	{

		printf("Failed to fork!\n");
	}
	
	else
	{
		wait(NULL);
		system("grep -n out *.txt > output.txt");
		printf("\n");
		printf("Content saved to output.txt!\n");
	}
}	// end of main function
