// Khursheed Alam Khan		Assignment#1: Answer to Question 2
// 20i-0496
// SE-R


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{ // start of main

	printf("P1: ID:= %d", getpid());
	printf(", Parent ID = %d\n", getppid());
	
	int P2 = fork();
	
	if(P2 == 0)
	{	// start outer 1st iF
		
		printf("P2: ID:= %d", getpid());
		printf(", Parent ID = %d\n", getppid());
	
		int P4 = fork();
		
		if(P4 == 0)
		{	// start inner 2nd if
		
			printf("P4: ID:= %d", getpid());
			printf(", Parent ID = %d\n", getppid());
			
		}	// end inner 2nd if
		
	}	// end outer 1st if
	
	else
	{
		wait(NULL); // waits for child process to terminate before parent process performs next function
	}
	
	
	if(P2>0) // if fork executed successfully
	{	// start outer 2nd if
	
		int P3 = fork();
		
		if(P3 == 0)
		{	// start innter 1st if
	
			printf("P3: ID:= %d", getpid());
			printf(", Parent ID = %d\n", getppid());
	
		}	// end inner 1st if
		
	}	// end outer 2nd if	
	
	return 0;

}// end of main
