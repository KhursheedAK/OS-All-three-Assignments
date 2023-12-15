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
				
	// Child 5	for	Task 5 (Encrypt each character in string with my roll-number: 20-0496)
	
	printf("\n");
	printf("(Task 5) --> I am Child 5: I am encrypting each character in string by multiplying with my Roll-Number: 20-0496\n");
	printf("\n");
	strcpy(s, argv[0]);
	
	int i=0;
	int j=0;
	int roll[6] = {2, 0, 0, 4, 9, 6};
	printf("ENCRYPTION: ");
	while(s[i] != '\0')
	{
		if(j < 6)
		{
			printf("%c", s[i]);
			printf("*");
			printf("%d", roll[j]);
			s[i] = s[i] * roll[j];
			i++;
			j++;
			if(s[i] != '\0')
			{
				printf(", ");
			}
			else if(s[i] == '\0')
			{
				printf(".");
			}
		}
		else if(j == 6)
		{
			j = 0;
		}
		
	}
	printf("\n");
	printf("Ans: Encrypted Text now is: %s\n", s);

	wait(NULL);
}	// end of main class
