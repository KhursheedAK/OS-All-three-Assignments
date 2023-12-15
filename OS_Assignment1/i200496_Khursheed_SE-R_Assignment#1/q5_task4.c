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
	
	// Child 4	for	Task 4 (Sort array in descending order)
	printf("\n");
	printf("(Task 4) --> I am Child 4: I am sorting the array in descending order\n");
	printf("\n");
	strcpy(s, argv[0]);
	
	for(int i=0; i<=sizeof s / sizeof s[0]; i++)
	{
			if((s[i] > s[i+1]) && s[i+1] != '\0')
			{
				temp = s[i];
				s[i] = s[i+1];
				s[i+1] = temp;
			}
	}
	printf("Descending Sorting Completed!...\n");
	printf("Ans: New output: %s\n", s);
	
	int P5 = fork();
	if(P5 == 0)	// Child 5	for	Task 5 (Encrypt each character in string with my roll-number: 20-0496)
	{
		char* strings[100] = {s};
		execv("./Q5_T5", strings);
	}
	wait(NULL);
}	// end of main class
