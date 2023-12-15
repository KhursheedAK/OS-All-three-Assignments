// By: Khursheed Alam Khan								Term Project: DeadLock Detection
// Roll# 20i-0496
// Section: SE-R

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>

struct deadLocks
{
	int pid, allocated, requested, simulTime; 
} array[50], fileArray[50], alloArray[50], reqArray[50], deadArray[50], terminateArray[50];


int main(int argc, char* argv[])
{
	int sizeA=0, sizeF=0, sizeAllo=0, sizeReq=0, sizeDead=0, sizeT=0, sizeDup=0;
	
	int i=0, j=0, k=0, posA=0, posF=0, posAllo=0, posReq=0, posDead=0, posT=0, posDup=0, posSim=0;
	
	int process=0, file = 0, temp=0, temp2=0, temp3=0;
	
	bool flag = false;
	
	int distinct_req_exec_time=0, distinct_allo_exec_time=0, same_req_exec_time=0, same_allo_exec_time=0, min_exec_time=0, simTime=0, total_sim_time=0;
	
	int dupFile[50];
	    
		if(strcmp(argv[1], "-e") == 0 && strcmp(argv[2], "-f") == 0)
		{
			// file function
			FILE* myFile = fopen(argv[3], "r");

			if(myFile == NULL)
			{
				printf("FILE NOT FOUND !\n");
				exit(1);					
			}
							
			else
			{
				while(fscanf(myFile, "%d %d %d", &array[i].pid, &array[i].allocated, &array[i].requested) != EOF)
				{
					array[i].simulTime=0;
					i = i + 1;
					sizeA = i;
				}
				fclose(myFile); // content saved
			}
			
			
															//-- Printing Statistics --//
			// now calculating total files and processes in array
			for(int i=0; i<sizeA; i++)
			{
				// storing all files requested and locked to separate array
				
				dupFile[posDup] = array[i].allocated;
				posDup = posDup + 1;
				sizeDup = sizeDup + 1;
				
				dupFile[posDup] = array[i].requested;
				posDup = posDup + 1;
				sizeDup = sizeDup + 1;
				 
				//ending sotrage
				
				printf("Process | File Locked | File Requested : %d %d %d\n", array[i].pid, array[i].allocated, array[i].requested);
				
				process++;

			}
			
			// removing duplicate files from array
			for(i=0; i < sizeDup; i++)
			{
     				for(j = i+1; j < sizeDup; j++)
     				 {
         				if(dupFile[i] == dupFile[j])
         				{
            					for(k = j; k < sizeDup; k++)
            					{
               						dupFile[k] = dupFile[k+1];
            					}
            					j--;
            					sizeDup--;
         				}
      				}
   			}
   			
   			// calculating total files
   			for(int i=0; i<sizeDup; i++)
   			{
   				file = file + 1;
   			}
			
		      	printf("\n");
		      	printf("Total Processes: %d\n", process);
		      	printf("Total Files: %d\n", file);
		      	printf("\n");
		      													//-- Printing Execution Time --//
												
			for(int i=0; i<sizeA; i++)
			{
				if(array[i].requested != array[i+1].requested && array[i].requested != array[i-1].requested)
				{
					distinct_req_exec_time = 1;
				}
				
				if(array[i].allocated != array[i+1].allocated && array[i].allocated != array[i-1].allocated)
				{
					distinct_allo_exec_time = 1;
				}
				
				if(array[i].requested == array[i+1].requested && array[i].requested == array[i-1].requested)
				{
					same_req_exec_time = same_req_exec_time + 1;
				}
				
				if(array[i].allocated == array[i+1].allocated && array[i].allocated == array[i-1].allocated)
				{
					same_allo_exec_time = same_allo_exec_time + 1;
				}
				
			}
			min_exec_time = same_req_exec_time + same_allo_exec_time + distinct_req_exec_time + distinct_allo_exec_time;
			printf("Total Minimum Execution Time: %d\n", min_exec_time );
		}
		
		
				
		else if(strcmp(argv[1], "-f") == 0)	// testing here
	    	{
			// file function
			FILE* myFile = fopen(argv[2], "r");
			
			if(myFile == NULL)
			{
				printf("FILE NOT FOUND !\n");
				exit(1);					
			}
							
			else
			{
				while(fscanf(myFile, "%d %d %d", &array[i].pid, &array[i].allocated, &array[i].requested) != EOF)
				{
					i = i + 1;
					sizeA = i;
				}
				fclose(myFile); // content saved
			}
			
			
																//-- Printing Statistics --//
			// now calculating total files and processes in array
			for(int i=0; i<sizeA; i++)
			{
				// storing all files requested and locked to separate array
				
				dupFile[posDup] = array[i].allocated;
				posDup = posDup + 1;
				sizeDup = sizeDup + 1;
				
				dupFile[posDup] = array[i].requested;
				posDup = posDup + 1;
				sizeDup = sizeDup + 1;
				 
				//ending sotrage
				
				printf("Process | File Locked | File Requested : %d %d %d\n", array[i].pid, array[i].allocated, array[i].requested);
				
				process++;

			}
			
			// removing duplicate files from array
			for(i=0; i < sizeDup; i++)
			{
     				for(j = i+1; j < sizeDup; j++)
     				 {
         				if(dupFile[i] == dupFile[j])
         				{
            					for(k = j; k < sizeDup; k++)
            					{
               						dupFile[k] = dupFile[k+1];
            					}
            					j--;
            					sizeDup--;
         				}
      				}
   			}
   			
   			// calculating total files
   			for(int i=0; i<sizeDup; i++)
   			{
   				file = file + 1;
   			}
			
		      	printf("\n");
		      	printf("Total Processes: %d\n", process);
		      	printf("Total Files: %d\n", file);
		      	printf("\n");
		      	
		      													//-- Printing DeadLock Detection --//
		      	// detecting deadLocks
			for(int i=0; i<sizeA; i++)
			{
				if(array[i].requested == array[i+1].allocated || array[i].allocated == array[i+1].requested || array[i].requested == array[i-1].allocated)
				{
					flag = true;
					deadArray[posDead] = array[i];
					posDead++;
				}
			}
	
			if(flag == true)
			{
				printf("Deadlock detected.\n");
				printf("\n");												//--Printing List of Processes to terminate --//
	
				// List of processes to terminate store
				for(int i=0; i<sizeA; i++)
				{
					if(array[i].requested == array[i+1].allocated)
					{
						terminateArray[posT] = array[i];
						posT++;
						sizeT++;
					}
				}
				
				// Sorting processes that can be terminated from smallest to largest Pid
				for(i=0; i<sizeT; i++)
				{
					for(j=i+1; j<sizeT; j++)
					{
						if(terminateArray[i].pid > terminateArray[j].pid)
						{
							temp = terminateArray[i].pid;
							terminateArray[i].pid=terminateArray[j].pid;
							terminateArray[j].pid = temp;
							
							temp = terminateArray[i].allocated;
							terminateArray[i].allocated=terminateArray[j].allocated;
							terminateArray[j].allocated = temp;
							
							temp = terminateArray[i].requested;
							terminateArray[i].requested=terminateArray[j].requested;
							terminateArray[j].requested = temp;
						}
					}
				}
				
				if(flag==true)
				{
					printf("Terminate ");
					
					// now displaying the process to terminate
					for(int i=0; i<sizeT; i++)
					{
						if(sizeT>1)
						{
							if(terminateArray[i].pid < terminateArray[i+1].pid)
							{
								printf("%d ", terminateArray[i].pid);
								break;
							}
							
							else if(terminateArray[i].pid < terminateArray[i+1].pid && terminateArray[i].pid < terminateArray[i+2].pid)
							{
								printf("%d ", terminateArray[i].pid);
								break;
							}
						}
						
						else
						printf("%d ", terminateArray[i].pid);
					}
				}
				
				printf("\n");
			}
			
			else
			{
				printf("No deadlocks detected.\n");
			}
			
		}
		
		
		else if((strcmp(argv[1], "-c") && strcmp(argv[2], "-f")) == 0)
		{
			// file function
			FILE* myFile = fopen(argv[3], "r");

			if(myFile == NULL)
			{
				printf("FILE NOT FOUND !\n");
				exit(1);					
			}
							
			else
			{
				while(fscanf(myFile, "%d %d %d", &array[i].pid, &array[i].allocated, &array[i].requested) != EOF)
				{
					i = i + 1;
					sizeA = i;
				}
				fclose(myFile); // content saved
			}
			
																		//-- Printing Statistics --//
			// now calculating total files and processes in array
			for(int i=0; i<sizeA; i++)
			{
				// storing all files requested and locked to separate array
				
				dupFile[posDup] = array[i].allocated;
				posDup = posDup + 1;
				sizeDup = sizeDup + 1;
				
				dupFile[posDup] = array[i].requested;
				posDup = posDup + 1;
				sizeDup = sizeDup + 1;
				 
				//ending sotrage
				
				printf("Process | File Locked | File Requested : %d %d %d\n", array[i].pid, array[i].allocated, array[i].requested);
				
				process++;

			}
			
			// removing duplicate files from array
			for(i=0; i < sizeDup; i++)
			{
     				for(j = i+1; j < sizeDup; j++)
     				 {
         				if(dupFile[i] == dupFile[j])
         				{
            					for(k = j; k < sizeDup; k++)
            					{
               						dupFile[k] = dupFile[k+1];
            					}
            					j--;
            					sizeDup--;
         				}
      				}
   			}
   			
   			// calculating total files
   			for(int i=0; i<sizeDup; i++)
   			{
   				file = file + 1;
   			}
			
		      	printf("\n");
		      	printf("Total Processes: %d\n", process);
		      	printf("Total Files: %d\n", file);
		      	printf("\n");
		      															//-- Printing Processes in DeadLock free manner  --//
		      	// Allocating Files to process in deadlock free manner
			for(int i=0; i<sizeA; i++)
			{
			
				if(array[i].requested != array[i+1].allocated)
				{
					array[i].simulTime = simTime;
					array[i+1].simulTime = simTime;
					
					total_sim_time = simTime;	
				}
				
				else if(array[i].requested == array[i+1].allocated)
				{
					temp = array[i+1].pid;
					temp2 = array[i+1].allocated;
					temp3 = array[i+1].requested;
					
					array[i+1] = array[sizeA-1];
					
					array[sizeA-1].pid = temp;
					array[sizeA-1].allocated = temp2;
					array[sizeA-1].requested = temp3;
					
					array[i].simulTime = simTime;
					simTime++;
					array[i+1].simulTime = simTime;
					
					total_sim_time = simTime;	
				} 
			}
			
			
			// printing sequence of dead-lock free arrays with their time
			for(int i=0; i<sizeA; i++)
			{
				printf("%d %d %d %d\n", array[i].simulTime, array[i].pid, array[i].allocated, array[i].requested);
			}
			
			printf("\n");
			
			total_sim_time++;
			
			printf("Simulation Time: %d\n", total_sim_time );
		}
}
