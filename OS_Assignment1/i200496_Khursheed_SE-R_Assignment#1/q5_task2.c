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
	
	strcpy(s, argv[0]);
	
	// Child 2	for	Task 2 (count of each character in the string)
	printf("\n");
	printf("(Task 2) --> I am Child 2: I am counting each character in the String\n");
	printf("\n");

	
	for(int i=0; s[i] != '\0'; i++)
	{
		count=0;
		for(int j=0 ; s[j] != '\0'; j++)
		{
			if(s[j] == s[i])
			{
				count++;
			}
		}
		printf("Ans: %c : %d\n", s[i], count);
	}
	
	int P3 = fork();
	if(P3 == 0)	// Child 3	for	Task 3 (Add 2 in the ASCII of each character)
	{	
		char *strings[100] = {s};
		execv("./Q5_T3", strings);
	}
	wait(NULL);			
}	// end of main class
