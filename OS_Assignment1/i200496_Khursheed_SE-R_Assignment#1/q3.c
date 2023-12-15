// Khursheed Alam Khan		Assignment#1: Answer to Question 3
// 20i-0496
// SE-R


#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{	// start of main

	float a, b, c ,d ,e ,f; // value assignment
	
	float a_multi_b=0;
	
	float c_div_d=0;
	
	float e_sub_f=0;
	
	float sum=0;
	
	int fd[2];
	
	// Get User Values
	printf("Enter 1st value: ");
	scanf("%f", &a);
	printf("\n");
	
	printf("Enter 2nd value: ");
	scanf("%f", &b);
	printf("\n");
	
	printf("Enter 3rd value: ");
	scanf("%f", &c);
	printf("\n");
	
	printf("Enter 4th value: ");
	scanf("%f", &d);
	printf("\n");
	
	printf("Enter 5th value: ");
	scanf("%f", &e);
	printf("\n");
	
	printf("Enter 6th value: ");
	scanf("%f", &f);
	printf("\n");
	// End of user values
	
	pipe(fd); // calling pipe system call
	
	int P1 = fork();
	
	if(P1 == 0) // First Child
	{	// start outer 1st if
		
		close(fd[0]);
		
		a_multi_b = a * b;
		printf("Child Process 1 operation: %f\n", a_multi_b);
		
		write(fd[1], &a_multi_b, sizeof(a_multi_b));

		
		int P2 = fork();
		
		if(P2 == 0)  // Second Child
		{	//start inner 1st if 
		
			c_div_d = c / d;
			printf("Child Process 2 operation: %f\n", c_div_d);
			
			write(fd[1], &c_div_d, sizeof(c_div_d));
	
			
			int P3 = fork();
			
			if(P3 == 0)
			{	// start inner 1st if
			
				e_sub_f = e - f;
				printf("Child Process 3 operation: %f\n", e_sub_f);
				
				write(fd[1], &e_sub_f, sizeof(e_sub_f));
				close(fd[1]);
			
			} 	// end inner 1st if

		}	// end inner 1st if
		
	
	}	// end outer 1st if

	else if(P1>0)
	{	// start outer else
		close(fd[1]);		
		read(fd[0], &a_multi_b, sizeof(a_multi_b));
		
		read(fd[0], &c_div_d, sizeof(c_div_d));
		
		read(fd[0], &e_sub_f, sizeof(e_sub_f));
		close(fd[0]);
		
		wait(NULL);
		wait(NULL);
		wait(NULL);	// wait for child processes to terminate before continuing parent process
		sum = (a_multi_b) + (c_div_d) + (e_sub_f);
		
		printf("Parent Process Final Result Computation: %f\n", sum); 
	
	}	// end outer else

	return 0;
}	// end of main
