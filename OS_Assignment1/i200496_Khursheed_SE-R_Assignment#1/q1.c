// Khursheed Alam Khan		Assignment#1: Answer to Question 1
// 20i-0496
// SE-R


#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

void display(int, int);

int main()
{	// start of main function	

	int pattern_option;
	int number;
	
	do
	{	
		printf("1. Display Left Pattern\n");
		printf("2. Display Right Pattern\n");
		printf("3. Display Inverted Full Pattern\n");
		printf("4. Quit\n");
		
		printf("\n");
		scanf("%d", &pattern_option);
		printf("\n");
		
		if(pattern_option == 1 || pattern_option == 2 || pattern_option == 3)
		{
			printf("Enter the number of rows: \n");
			scanf("%d", &number);
			printf("\n");
			
			display(pattern_option, number); // a function with two input parameters to display pattern
		}
		
		else if(pattern_option != 4)
		{	
			printf("Invalid input...\n");
			printf("\n");
		}
		
	}while(pattern_option != 4);
	
	printf("Thanks for using Khursheed's pattern displayer in C-language\n");

}	// end of main function


// Display Pattern
void display(int pattern_option, int number)
{	// start of Display Pattern Function

	if(pattern_option == 1) // left pattern
	{
		
		for(int i=1; i<=number; i++)
		{
			for(int j=1; j<=i; j++)
			{
				printf("*");
			}
		 printf("\n");
		}
		printf("\n");	
	}
	
	else if(pattern_option == 2) // right pattern
	{
		for(int i=1; i<=number; i++)
		{
			for(int k=number-i; k>=1; k--)
			{
				printf(" ");
			}
		
			for(int j=1; j<=i; j++)
			{
				printf("*");
			}
		  printf("\n");
		}
		printf("\n");
	}
	
	else if(pattern_option == 3)
	{
		// inverted_full pattern
		for (int i=number; i>=1; i--)  
    		{  
          
        		for (int j=1; j<=number; j++)  
        		{  
            			if(j<=i)
            			{  
            				printf("*");
            			} 
              
           			 else
            			{  
            				printf(" ");
            			}  
        		}
          
        		for (int j=number; j>=1; j--)  
        		{  
            			if(j<=i)
            			{  
            				printf("*");
            			}
              
           			 else
            			{  
            				printf(" ");
            			}  
        		}  
        	printf("\n");  
    		}
    		printf("\n");  
	}
	
}	// end of display pattern function



