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
	
	printf("Enter: \n");
	scanf("%s", s);
	
	int P1 = fork();	// creates duplicate child process
	
	if(P1 == 0)	// Child 1	for	Task 1 (swapping the indexes)
	{	
		printf("\n");
		printf("(Task 1) --> I am Child 1: I am swapping the indexes\n");
		for(int i=0; i<=sizeof s / sizeof s[0]; i++)
		{
			if(s[i+1] != '\0')
			{
				temp = s[i];
				s[i] = s[i+1];
				s[i+1] = temp;
			}
		}
		
		printf("\n");
		printf("Ans: %s\n",s);
		
		int P2 = fork();
		if(P2 == 0)	// Child 2	for	Task 2 (count of each character in the string)
		{
			char *strings[100] = {s};
			execv("./Q5_T2",strings);
		}
	}
	wait(NULL);
}	// end of main class
