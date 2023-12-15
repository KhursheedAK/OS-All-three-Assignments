// Khursheed Alam Khan		Assignment#1: Answer to Question 5
// 20i-0496
// SE-R

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char* argv[])
{	// start of main class
	
	int max=100;
	char s[max];
	char temp;
	int count=0;
	

	// Child 3	for	Task 3 (Add 2 in the ASCII of each character)
	
	printf("\n");
	printf("(Task 3) --> I am Child 3: I am adding 2 in the ASCII of each character\n");
	printf("\n");
	strcpy(s, argv[0]);
	
	int asc = 0;

	for(int i=0; s[i] != '\0'; i++)
	{
		asc =(s[i] + 2);
		printf("Ans: ASCII of '%c' after adding 2 is : %d\n", s[i], asc);
		printf("\n");
	}

	int P4 = fork();
	if(P4 == 0)	// Child 4	for	Task 4 (Sort array in descending order)
	{
		char *strings[100] = {s};
		execv("./Q5_T4", strings);
	}

	wait(NULL);	
}	// end of main class
