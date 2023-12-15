/* By Khursheed Alam Khan								// Operating Systems: Assignment 2	
   20i-0496
   SE-R
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PCB
{
	int pid, arrival, burst, waiting, turnAround, pr, response, rem_bt, completion;
	 
} Que1[10], Que2[10], Que3[10], Que4[10], Max[1], Copy[10], Copy2[10];

int main()
{
	int option, choice;
	
	printf("Enter no. of algorithms: \n");
	scanf("%d", &option);
	
	switch(option)
	{
		case 1: // Priority Based Scheduling queue
			{
				printf("\n");
				// code starts here
				int n, temp, i, j, position = 0;
				
				// Ask user to enter or take values from file
				printf("Press '1' to Read Processes from a file directly\n");
				printf("Press '2' to Enter Processes Manually\n");
				printf("Select your option: \n");
				scanf("%d", &choice);
				
				if(choice == 1)
				{
					FILE* myFile = fopen("input.txt", "r");

					if(myFile == NULL)
					{
						printf("No such File !\n");
						exit(1);
						
					}
					
					else
					{
						while(!feof(myFile))
						{
							fscanf(myFile, "%d %d %d %d\n", &Que1[position].pid, &Que1[position].arrival, &Que1[position].burst, &Que1[position].pr);
							
							position = position + 1;
					
						}
					}
					
					fclose(myFile); // content saved
					
					n = position;
				}
				
				else
				{
					printf("Enter number of processes: \n");
					scanf("%d", &n);
				
					// for loop to get arrival time, burst time, and priority 
					for(i=0; i<n; i++)
					{
						Que1[i].pid=i;
						printf("Enter Arrival Time, Burst Time, and Priority for Process no. %d\n", Que1[i].pid);
						scanf("%d %d %d", &Que1[i].arrival, &Que1[i].burst, &Que1[i].pr);
					}
				}
				
				printf("\n");
				printf("Queue 1 Priority Based Scheduling Started : \n");	
				printf("\n");
				
				// Bubble Sorting the processes by priority, then sorting their arrival and then sorting their burst
				for(i=0; i<n-1; i++)
				{
					for(j=0; j<n-i-1; j++)
					{
						if(Que1[j].pr < Que1[j+1].pr)
						{
							// sorted by priority
							temp = Que1[j].pr;
							Que1[j].pr=Que1[j+1].pr;
							Que1[j+1].pr = temp;
							
							// sorted by arrival
							temp = Que1[j].arrival;
							Que1[j].arrival=Que1[j+1].arrival;
							Que1[j+1].arrival = temp;
							
							// now sort by burst
							temp = Que1[j].burst;
							Que1[j].burst=Que1[j+1].burst;
							Que1[j+1].burst=temp;
						}
					}
				}
				
				int completion = 0; // exit time (completion time)
				int waiting=0;	// waiting time
				int turnAround=0;	// turn around time
				Que1[0].waiting=0;	// first process waiting time will be 0
				
				float avg_turn = 0, avg_wait = 0;
				
				printf("Process ID | Arrival Time | \tBurst Time | \t Waiting Time | Turn Around Time | Priority\n");
				
				// Now calculating the completion time, waiting time, and Turn around time;
				for(i=0; i<n; i++)
				{
					completion = completion + Que1[i].burst;
					Que1[i].completion = completion;
					
					turnAround = Que1[i].completion - Que1[i].arrival;
					Que1[i].turnAround = turnAround;
					
					waiting = Que1[i].turnAround - Que1[i].burst;
					Que1[i].waiting = waiting;
				
					avg_turn = avg_turn + turnAround;
					avg_wait = avg_wait + waiting;
				
					printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", Que1[i].pid, Que1[i].arrival, Que1[i].burst, Que1[i].waiting, Que1[i].turnAround, Que1[i].pr); 
				}
				
				avg_turn = avg_turn/n;
				avg_wait = avg_wait/n;
				
				printf("Average Waiting Time: %f\n", avg_wait);
				printf("Average Turn Around Time: %f\n", avg_turn);
				
				// code ends here
				
				printf("\n");
				break;
			}
		
		case 2:	// Priority Based and finally Round Robin Based Scheduling Quantum Time 8 queue
			{
				printf("\n");
				
				// code starts here
				int n, temp, i, j, position = 0;
				
				// Ask user to enter or take values from file
				printf("Press '1' to Read Processes from a file directly\n");
				printf("Press '2' to Enter Processes Manually\n");
				printf("Select your option: \n");
				scanf("%d", &choice);
				
				if(choice == 1)
				{
					FILE* myFile = fopen("input.txt", "r");

					if(myFile == NULL)
					{
						printf("No such File !\n");
						exit(1);
						
					}
					
					else
					{
						while(!feof(myFile))
						{
							fscanf(myFile, "%d %d %d %d\n", &Que1[position].pid, &Que1[position].arrival, &Que1[position].burst, &Que1[position].pr);
							
							position = position + 1;
						}
					}
					
					fclose(myFile); // content saved
					
					n = position;
				}
				
				else
				{
					printf("Enter number of processes: \n");
					scanf("%d", &n);
				
					// for loop to get arrival time, burst time, and priority 
					for(i=0; i<n; i++)
					{
						Que1[i].pid=i;
						printf("Enter Arrival Time, Burst Time, and Priority for Process no. %d\n", Que1[i].pid);
						scanf("%d %d %d", &Que1[i].arrival, &Que1[i].burst, &Que1[i].pr);
					}
				}
				
				printf("\n");
				printf("Queue 1 Priority Based Scheduling Started : \n");	
				printf("\n");
				
				// Bubble Sorting the processes by priority, then sorting their arrival and then sorting their burst
				for(i=0; i<n-1; i++)
				{
					for(j=0; j<n-i-1; j++)
					{
						if(Que1[j].pr < Que1[j+1].pr)
						{
							// sorted by priority
							temp = Que1[j].pr;
							Que1[j].pr=Que1[j+1].pr;
							Que1[j+1].pr = temp;
							
							// sorted by arrival
							temp = Que1[j].arrival;
							Que1[j].arrival=Que1[j+1].arrival;
							Que1[j+1].arrival = temp;
							
							// now sort by burst
							temp = Que1[j].burst;
							Que1[j].burst=Que1[j+1].burst;
							Que1[j+1].burst=temp;
						}
					}
				}
				
				// sepearting the max PR process from other processes
				Max[0] = Que1[0];
				
				int completion = 0; // exit time (completion time)
				int waiting=0;	// waiting time
				int turnAround=0;	// turn around time
				Max[0].waiting=0;	// first process waiting time will be 0
				
				float avg_turn = 0, avg_wait = 0;
				
				printf("Process ID | Arrival Time | \tBurst Time | \t Waiting Time | Turn Around Time | Priority\n");
				
				// Now calculating the completion time, waiting time, and Turn around time;
				for(i=0; i<sizeof Max / sizeof Max[0]; i++)
				{
					completion = completion + Max[0].burst;
					Max[0].completion = completion;
					
					turnAround = Max[0].completion - Max[0].arrival;
					Max[0].turnAround = turnAround;
					
					waiting = Max[0].turnAround - Max[0].burst;
					Max[0].waiting = waiting;
					
					avg_turn = avg_turn + turnAround;
					avg_wait = avg_wait + waiting;
				
					printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", Max[0].pid, Max[0].arrival, Max[0].burst, Max[0].waiting, Max[0].turnAround, Max[0].pr); 
				}
				
				avg_turn = avg_turn/(sizeof Max / sizeof Max[0]) ;
				avg_wait = avg_wait/(sizeof Max / sizeof Max[0]);
				
				printf("Average Waiting Time: %f\n", avg_wait);
				printf("Average Turn Around Time: %f\n", avg_turn);
				
				// now deleteing the Que1[0] from the original queue
				for(i=0; i<n; i++)
				{
					Que1[i] = Que1[i+1];				
				}
				n = n - 1; // decreasing the number of processes since process 1 has finished
				
				printf("Execution of First Process in Queue 1 (Priority Based Scheduling) Completed! \n");
				printf("\n");
			
				// Placing all the processes in Queue 1 to Queue 2 so that I can send it to Round Robin Process with Time Quantum 8
				for(i=0; i<n; i++)
				{
					Que2[i].pid = Que1[i].pid;
					Que2[i].arrival = Que1[i].arrival;
					Que2[i].burst = Que1[i].burst;
					Que2[i].pr = Que1[i].pr;
					Que2[i].rem_bt = Que1[i].burst;
						
				}			
				
				printf("-------------------------------------------------------------------------------------------------------\n");
				
				/* Round Robin Algorithm with time quantum 8*/
				
				printf("Queue 2 ROUND ROBIN Time Quantum of 8 Started : \n");
				printf("\n");
				// Bubble Sorting the processes by arrival, then sorting their burst with priority
				for(i=0; i<n-1; i++)
				{
					for(j=0; j<n-i-1; j++)
					{
						if(Que2[j].arrival > Que2[j+1].arrival)
						{	
							// sorted by arrival
							temp = Que2[j].arrival;
							Que2[j].arrival=Que2[j+1].arrival;
							Que2[j+1].arrival = temp;
							
							// now sort the burst
							temp = Que2[j].burst;
							Que2[j].burst=Que2[j+1].burst;
							Que2[j+1].burst=temp;
							
							// now sort the remaining burst
							temp = Que2[j].rem_bt;
							Que2[j].rem_bt=Que2[j+1].rem_bt;
							Que2[j+1].rem_bt=temp;
							
							// now sort the priority
							temp = Que2[j].pr;
							Que2[j].pr=Que2[j+1].pr;
							Que2[j+1].pr = temp;
						}
					}
				}
				
				int count =0; // no. of processes that finished
				int tQ=8;
				Que2[0].waiting=Max[0].turnAround - Max[0].burst;
				
				float awt =0, atat=0;
				int temp2=0;
				printf("Process ID | Arrival Time | \tBurst Time | \t Waiting Time | Turn Around Time | Priority\n");
				
					while(count!=n)	// until count reaches the total number of processes in the queue
					{
						for(i=0; i<n; i++) // count is incremented with each complete execetion of a process 
						{
							temp=tQ; // assigning time quantum variable to temp to use with temp 2 variable to calculate turnAround for each process
							
							if(Que2[i].rem_bt==0) // if remaining burst time of a process is 0
							{
								count++; // count incremeneted since process has completely executed by the CPU
								if(count == n)
								{
									break;
								}
								else
								continue; // next iteration started
							}
							
							if(Que2[i].rem_bt > tQ) // process still needs to be processed since its reminaing burst time is higher than time quantum of 8
							{
								Que2[i].rem_bt = Que2[i].rem_bt - tQ;	// decreasing the remaining burst by subtracting from time quantum
							}
							else
							{
								if(Que2[i].rem_bt >= 0 )
								{
									temp = Que2[i].rem_bt;	// reamining burst since is less than 8 so RR will execute for less than 8 upto the remaining burst of the process 
									Que2[i].rem_bt = 0;	// ultimately the process will be finished executing and count will be incremented next time the iteration starts from the beginning up to this process 
								}
							}
								temp2 = temp2 + temp;	// two temporary variables to help calculate total turn around time
								Que2[i].turnAround = temp2; // turn around time is obtained from two temporary variables
						}

					}
				
				// Here I am calculating the sum of turn around and waiting time respectively to later on calculate the average of both and display
				for(i=0; i<n; i++)
				{
					Que2[i].waiting = Que2[i].turnAround - Que2[i].burst;
					awt=awt + Que2[i].waiting;
					atat=atat+Que2[i].turnAround;
					
					printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", Que2[i].pid, Que2[i].arrival, Que2[i].burst, Que2[i].waiting, Que2[i].turnAround, Que2[i].pr); 
				}
				printf("\n");
				
				atat = atat/n;
				awt = awt/n;
				
				printf("Average Waiting Time: %f\n", awt);
				printf("Average Turn Around Time: %f\n", atat);
				
				printf("Execution of remaining Processes in Queue 2 (Round Robin Time Quantum 8 Scheduling) Completed! \n");
				printf("\n");
				
				// code ends here
				
				printf("\n");
				break;
			}
			
		case 3:	// Priority Based, Round Robin Based Scheduling Quantum Time 8, and finally Round Robin Based Scheduling Quantum Time 10 queue
			{
				printf("\n");
				
				// code starts here
				int n, temp, i, j, position = 0;
				
				// Ask user to enter or take values from file
				printf("Press '1' to Read Processes from a file directly\n");
				printf("Press '2' to Enter Processes Manually\n");
				printf("Select your option: \n");
				scanf("%d", &choice);
				
				if(choice == 1)
				{
					FILE* myFile = fopen("input.txt", "r");

					if(myFile == NULL)
					{
						printf("No such File !\n");
						exit(1);
						
					}
					
					else
					{
						while(!feof(myFile))
						{
							fscanf(myFile, "%d %d %d %d\n", &Que1[position].pid, &Que1[position].arrival, &Que1[position].burst, &Que1[position].pr);
							
							position = position + 1;
						}
					}
					
					fclose(myFile); // content saved
					
					n = position;
				}
				
				else
				{
					printf("Enter number of processes: \n");
					scanf("%d", &n);
				
					// for loop to get arrival time, burst time, and priority 
					for(i=0; i<n; i++)
					{
						Que1[i].pid=i;
						printf("Enter Arrival Time, Burst Time, and Priority for Process no. %d\n", Que1[i].pid);
						scanf("%d %d %d", &Que1[i].arrival, &Que1[i].burst, &Que1[i].pr);
					}
				}
				
				printf("\n");
				printf("Queue 1 Priority Based Scheduling Started : \n");	
				printf("\n");
				
				// Bubble Sorting the processes by priority, then sorting their arrival and then sorting their burst
				for(i=0; i<n-1; i++)
				{
					for(j=0; j<n-i-1; j++)
					{
						if(Que1[j].pr < Que1[j+1].pr)
						{
							// sorted by priority
							temp = Que1[j].pr;
							Que1[j].pr=Que1[j+1].pr;
							Que1[j+1].pr = temp;
							
							// sorted by arrival
							temp = Que1[j].arrival;
							Que1[j].arrival=Que1[j+1].arrival;
							Que1[j+1].arrival = temp;
							
							// now sort by burst
							temp = Que1[j].burst;
							Que1[j].burst=Que1[j+1].burst;
							Que1[j+1].burst=temp;
						}
					}
				}
				
				// sepearting the max PR process from other processes
				Max[0] = Que1[0];
				
				int completion = 0; // exit time (completion time)
				int waiting=0;	// waiting time
				int turnAround=0;	// turn around time
				Max[0].waiting=0;	// first process waiting time will be 0
				
				float avg_turn = 0, avg_wait = 0;
				
				printf("Process ID | Arrival Time | \tBurst Time | \t Waiting Time | Turn Around Time | Priority\n");
				
				// Now calculating the completion time, waiting time, and Turn around time;
				for(i=0; i<sizeof Max / sizeof Max[0]; i++)
				{
					completion = completion + Max[0].burst;
					Max[0].completion = completion;
					
					turnAround = Max[0].completion - Max[0].arrival;
					Max[0].turnAround = turnAround;
					
					waiting = Max[0].turnAround - Max[0].burst;
					Max[0].waiting = waiting;
					
					avg_turn = avg_turn + turnAround;
					avg_wait = avg_wait + waiting;
				
					printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", Max[0].pid, Max[0].arrival, Max[0].burst, Max[0].waiting, Max[0].turnAround, Max[0].pr); 
				}
				
				avg_turn = avg_turn/(sizeof Max / sizeof Max[0]) ;
				avg_wait = avg_wait/(sizeof Max / sizeof Max[0]);
				
				printf("Average Waiting Time: %f\n", avg_wait);
				printf("Average Turn Around Time: %f\n", avg_turn);
				
				// now deleteing the Que1[0] from the original queue
				for(i=0; i<n; i++)
				{
					Que1[i] = Que1[i+1];				
				}
				n = n - 1; // decreasing the number of processes since process 1 has finished
				
				printf("Execution of First Process in Queue 1 (Priority Based Scheduling) Completed! \n");
				printf("\n");
			
				// Placing all the processes in Queue 1 to Queue 2 so that I can send it to Round Robin Process with Time Quantum 8
				for(i=0; i<n; i++)
				{
					Que2[i].pid = Que1[i].pid;
					Que2[i].arrival = Que1[i].arrival;
					Que2[i].burst = Que1[i].burst;
					Que2[i].pr = Que1[i].pr;
					Que2[i].rem_bt = Que1[i].burst;
						
				}			
				
				printf("-------------------------------------------------------------------------------------------------------\n");
				
				/* Round Robin Algorithm with time quantum 8*/
				
				printf("Queue 2 ROUND ROBIN Time Quantum of 8 Started : \n");
				printf("\n");
				
				int temp3 = 0, 
				k=0, // k for queue 3 
				p=0; // p for queue 2 
				int count =0; // no. of processes that finished
				int que2=n;	// no. processes in Queue 2 after transferring in Queue 3
				int que3=0;	// no. of processes in Queue 3
				int tQ=8;
				
				/* Testing Codes Start Here*/
				for(i=0; i<n; i++)
				{
					temp3=0;
					
					if(Que2[i].rem_bt > tQ)
					{
						temp3 = Que2[i].rem_bt - tQ;
						
						Que3[k] = Que2[i];
						
						Que3[k].rem_bt = temp3;
						
						k = k + 1;
						
						que2 = que2 -1;	// total processes	queue 2
						
						que3 = k;	// total processes in queue 3
					}
					
					else if(Que2[i].rem_bt <= tQ)
					{
						Copy[p] = Que2[i];
						
						p = p + 1;
					}
				}
				
				n = que2;
				
				// now storing the less than tQ = 8 back in Queue 2
				for(i=0; i<p; i++)
				{
					Que2[i] = Copy[i];
				}
				
				/* Testing Code Ends Here*/
				
				// Bubble Sorting the processes in Queue 2 by arrival, then sorting their burst with priority
				for(i=0; i<n-1; i++)
				{
					for(j=0; j<n-i-1; j++)
					{
						if(Que2[j].arrival > Que2[j+1].arrival)
						{	
							// sorted by arrival
							temp = Que2[j].arrival;
							Que2[j].arrival=Que2[j+1].arrival;
							Que2[j+1].arrival = temp;
							
							// now sort by burst
							temp = Que2[j].burst;
							Que2[j].burst=Que2[j+1].burst;
							Que2[j+1].burst=temp;
							
							// now sort the remaining burst
							temp = Que2[j].rem_bt;
							Que2[j].rem_bt=Que2[j+1].rem_bt;
							Que2[j+1].rem_bt=temp;
							
							// now sort the priority
							temp = Que2[j].pr;
							Que2[j].pr=Que2[j+1].pr;
							Que2[j+1].pr = temp;
						}
					}
				}
				
				Que2[0].waiting=Max[0].turnAround - Max[0].burst;
				
				float awt =0, atat=0;
				int temp2=0;
				int last_n=0;
				printf("Process ID | Arrival Time | \tBurst Time | \t Waiting Time | Turn Around Time | Priority\n");
				
					while(count!=n)	// until count reaches the total number of processes in the queue
					{
						for(i=0; i<n; i++) // count is incremented with each complete execetion of a process 
						{
							temp=tQ; // assigning time quantum variable to temp to use with temp 2 variable to calculate turnAround for each process
							
							if(Que2[i].rem_bt==0) // if remaining burst time of a process is 0
							{
								count++; // count incremeneted since process has completely executed by the CPU
								if(count == n)
								{
									break;
								}
								else
								continue; // next iteration started
							}
						
							else
							{
								if(Que2[i].rem_bt >= 0 )
								{
									temp = Que2[i].rem_bt;	// reamining burst since is less than 8 so RR will execute for less than 8 upto the remaining burst of the process 
									Que2[i].rem_bt = 0;	// ultimately the process will be finished executing and count will be incremented next time the iteration starts from the beginning up to this process 
								}
							}
								temp2 = temp2 + temp;	// two temporary variables to help calculate total turn around time
								Que2[i].turnAround = temp2; // turn around time is obtained from two temporary variables
						}
							last_n = i;
					}
				
				// Here I am calculating the sum of turn around and waiting time respectively to later on calculate the average of both and display
				for(i=0; i<n; i++)
				{
					Que2[i].waiting = Que2[i].turnAround - Que2[i].burst;
					awt=awt + Que2[i].waiting;
					atat=atat+Que2[i].turnAround;
					
					printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", Que2[i].pid, Que2[i].arrival, Que2[i].burst, Que2[i].waiting, Que2[i].turnAround, Que2[i].pr); 
				}
				printf("\n");
				
				atat = atat/n;
				awt = awt/n;
				
				printf("Average Waiting Time: %f\n", awt);
				printf("Average Turn Around Time: %f\n", atat);
				
				printf("Execution of remaining Processes in Queue 2 (Round Robin Time Quantum 8 Scheduling) Completed! \n");
				printf("\n");
				
				printf("-------------------------------------------------------------------------------------------------------\n");
				printf("\n");
				/* Round Robin Algorithm with time quantum 10*/
				
				printf("Queue 3 ROUND ROBIN Time Quantum of 10 Started : \n");
				printf("\n");
				
				n = que3;
				
				// Bubble Sorting the processes in Queue 3 by arrival, then sorting their burst with priority
				for(i=0; i<n-1; i++)
				{
					for(j=0; j<n-i-1; j++)
					{
						if(Que3[j].arrival > Que3[j+1].arrival)
						{	
							// sorted by arrival
							temp = Que3[j].arrival;
							Que3[j].arrival=Que3[j+1].arrival;
							Que3[j+1].arrival = temp;
							
							// now sort the burst
							temp = Que3[j].burst;
							Que3[j].burst=Que3[j+1].burst;
							Que3[j+1].burst=temp;
							
							// now sort the remaining burst
							temp = Que3[j].rem_bt;
							Que3[j].rem_bt=Que3[j+1].rem_bt;
							Que3[j+1].rem_bt=temp;
							
							// now sort the priority
							temp = Que3[j].pr;
							Que3[j].pr=Que3[j+1].pr;
							Que3[j+1].pr = temp;
						}
					}
				}

				printf("\n");
								
				Que3[0].waiting = temp2 - Que2[last_n].burst;
				
				int tQ2 = 10;
				float awt_2 =0, atat_2 = 0;
				int temp_2=0;
				int count_2 = 0;
				printf("Process ID | Arrival Time | \tBurst Time | \t Waiting Time | Turn Around Time | Priority\n");
				
					while(count_2!=n)	// until count reaches the total number of processes in the queue
					{
						for(i=0; i<n; i++) // count is incremented with each complete execetion of a process 
						{
							temp=tQ2; // assigning time quantum variable to temp to use with temp 2 variable to calculate turnAround for each process
							
							if(Que3[i].rem_bt==0) // if remaining burst time of a process is 0
							{
								count_2++; // count incremeneted since process has completely executed by the CPU
								if(count_2 == n)
								{
									break;
								}
								else
								continue; // next iteration started
							}
							
							if(Que3[i].rem_bt > tQ2) // process still needs to be processed since its reminaing burst time is higher than time quantum of 8
							{
								Que3[i].rem_bt = Que3[i].rem_bt - tQ2;	// decreasing the remaining burst by subtracting from time quantum
							}
							
							else
							{
								if(Que3[i].rem_bt >= 0 )
								{
									temp = Que3[i].rem_bt;	// reamining burst since is less than 8 so RR will execute for less than 8 upto the remaining burst of the process 
									Que3[i].rem_bt = 0;	// ultimately the process will be finished executing and count will be incremented next time the iteration starts from the beginning up to this process 
								}
							}
								temp_2 = temp_2 + temp;	// two temporary variables to help calculate total turn around time
								Que3[i].turnAround = temp_2; // turn around time is obtained from two temporary variables
						}

					}
				
				// Here I am calculating the sum of turn around and waiting time respectively to later on calculate the average of both and display
				for(i=0; i<n; i++)
				{
					Que3[i].waiting = Que3[i].turnAround - Que3[i].burst;
					awt_2=awt_2 + Que3[i].waiting;
					atat_2=atat_2+Que3[i].turnAround;
					
					printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", Que3[i].pid, Que3[i].arrival, Que3[i].burst, Que3[i].waiting, Que3[i].turnAround, Que3[i].pr); 
				}
				printf("\n");
				
				atat_2 = atat_2/n;
				awt_2 = awt_2/n;
				
				printf("Average Waiting Time: %f\n", awt_2);
				printf("Average Turn Around Time: %f\n", atat_2);
				
				printf("Execution of remaining Processes in Queue 3 (Round Robin Time Quantum 10 Scheduling) Completed! \n");
				printf("\n");
				
				// code ends here
				
				printf("\n");
				break;
			}
		
		case 4:	// Priority Based, Round Robin Based Scheduling Quantum Time 8, Round Robin Based Scheduling Quantum Time 10, and finally FCFS scheduling Queue
			{
				printf("\n");
				
				// code starts here
				int n, temp, i, j, position = 0;
				
				// Ask user to enter or take values from file
				printf("Press '1' to Read Processes from a file directly\n");
				printf("Press '2' to Enter Processes Manually\n");
				printf("Select your option: \n");
				scanf("%d", &choice);
				
				if(choice == 1)
				{
					FILE* myFile = fopen("input.txt", "r");

					if(myFile == NULL)
					{
						printf("No such File !\n");
						exit(1);
						
					}
					
					else
					{
						while(!feof(myFile))
						{
							fscanf(myFile, "%d %d %d %d\n", &Que1[position].pid, &Que1[position].arrival, &Que1[position].burst, &Que1[position].pr);
							
							position = position + 1;
						}
					}
					
					fclose(myFile); // content saved
					
					n = position;
				}
				
				else
				{
					printf("Enter number of processes: \n");
					scanf("%d", &n);
				
					// for loop to get arrival time, burst time, and priority 
					for(i=0; i<n; i++)
					{
						Que1[i].pid=i;
						printf("Enter Arrival Time, Burst Time, and Priority for Process no. %d\n", Que1[i].pid);
						scanf("%d %d %d", &Que1[i].arrival, &Que1[i].burst, &Que1[i].pr);
					}
				}
				
				printf("\n");
				printf("Queue 1 Priority Based Scheduling Started : \n");	
				printf("\n");
				
				// Bubble Sorting the processes by priority, then sorting their arrival and then sorting their burst
				for(i=0; i<n-1; i++)
				{
					for(j=0; j<n-i-1; j++)
					{
						if(Que1[j].pr < Que1[j+1].pr)
						{
							// sorted by priority
							temp = Que1[j].pr;
							Que1[j].pr=Que1[j+1].pr;
							Que1[j+1].pr = temp;
							
							// sorted by arrival
							temp = Que1[j].arrival;
							Que1[j].arrival=Que1[j+1].arrival;
							Que1[j+1].arrival = temp;
							
							// now sort by burst
							temp = Que1[j].burst;
							Que1[j].burst=Que1[j+1].burst;
							Que1[j+1].burst=temp;
						}
					}
				}
				
				// sepearting the max PR process from other processes
				Max[0] = Que1[0];
				
				int completion = 0; // exit time (completion time)
				int waiting=0;	// waiting time
				int turnAround=0;	// turn around time
				Max[0].waiting=0;	// first process waiting time will be 0
				
				float avg_turn = 0, avg_wait = 0;
				
				printf("Process ID | Arrival Time | \tBurst Time | \t Waiting Time | Turn Around Time | Priority\n");
				
				// Now calculating the completion time, waiting time, and Turn around time;
				for(i=0; i<sizeof Max / sizeof Max[0]; i++)
				{
					completion = completion + Max[0].burst;
					Max[0].completion = completion;
					
					turnAround = Max[0].completion - Max[0].arrival;
					Max[0].turnAround = turnAround;
					
					waiting = Max[0].turnAround - Max[0].burst;
					Max[0].waiting = waiting;
					
					avg_turn = avg_turn + turnAround;
					avg_wait = avg_wait + waiting;
				
					printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", Max[0].pid, Max[0].arrival, Max[0].burst, Max[0].waiting, Max[0].turnAround, Max[0].pr); 
				}
				
				avg_turn = avg_turn/(sizeof Max / sizeof Max[0]) ;
				avg_wait = avg_wait/(sizeof Max / sizeof Max[0]);
				
				printf("Average Waiting Time: %f\n", avg_wait);
				printf("Average Turn Around Time: %f\n", avg_turn);
				
				// now deleteing the Que1[0] means the highest priority process from the original queue
				for(i=0; i<n; i++)
				{
					Que1[i] = Que1[i+1];				
				}
				n = n - 1; // decreasing the number of processes since process 1 has finished
				
				printf("Execution of First Process in Queue 1 (Priority Based Scheduling) Completed! \n");
				printf("\n");
			
				// Placing all the processes in Queue 1 to Queue 2 so that I can send it to Round Robin Process with Time Quantum 8
				for(i=0; i<n; i++)
				{
					Que2[i].pid = Que1[i].pid;
					Que2[i].arrival = Que1[i].arrival;
					Que2[i].burst = Que1[i].burst;
					Que2[i].pr = Que1[i].pr;
					Que2[i].rem_bt = Que1[i].burst;
						
				}			
				
				printf("-------------------------------------------------------------------------------------------------------\n");
				
				/* Round Robin Algorithm with time quantum 8*/
				
				printf("Queue 2 ROUND ROBIN Time Quantum of 8 Started : \n");
				printf("\n");
				
				int temp3 = 0, // storing remaining burst time of processes higher than time quantum 8 into temp 3
				k=0, // k for queue 3 to start from the index 0 
				p=0; // p for queue 2  to start from the index 0
				int count =0; // no. of processes that finished
				int que2=n;	// no. processes in Queue 2 after transferring the remaining ones in Queue 3
				int que3=0;	// no. of processes in Queue 3
				int tQ=8;
				
				for(i=0; i<n; i++)
				{
					temp3=0;
					
					if(Que2[i].rem_bt > tQ)
					{
						temp3 = Que2[i].rem_bt - tQ;
						
						Que3[k] = Que2[i];
						
						Que3[k].rem_bt = temp3;
						
						k = k + 1;
						
						que2 = que2 -1;	// total processes	queue 2
						
						que3 = k;	// total processes in queue 3
					}
					
					else if(Que2[i].rem_bt <= tQ)
					{
						Copy[p] = Que2[i];
						
						p = p + 1;
					}
				}
				
				n = que2;
				
				// now storing the less than tQ = 8 back in Queue 2
				for(i=0; i<n; i++)
				{
					Que2[i] = Copy[i];
				}
				
				// Bubble Sorting the processes in Queue 2 by arrival, then sorting their burst with priority
				for(i=0; i<n-1; i++)
				{
					for(j=0; j<n-i-1; j++)
					{
						if(Que2[j].arrival > Que2[j+1].arrival)
						{	
							// sorted by arrival
							temp = Que2[j].arrival;
							Que2[j].arrival=Que2[j+1].arrival;
							Que2[j+1].arrival = temp;
							
							// now sort the burst
							temp = Que2[j].burst;
							Que2[j].burst=Que2[j+1].burst;
							Que2[j+1].burst=temp;
							
							// now sort the remaining burst
							temp = Que2[j].rem_bt;
							Que2[j].rem_bt=Que2[j+1].rem_bt;
							Que2[j+1].rem_bt=temp;
							
							// now sort the priority
							temp = Que2[j].pr;
							Que2[j].pr=Que2[j+1].pr;
							Que2[j+1].pr = temp;
						}
					}
				}
				
				Que2[0].waiting=Max[0].turnAround - Max[0].burst;
				
				float awt =0, atat=0;
				int temp2=0;
				int last_n=0; // to find the last process to exit round robin to be used for waiting for the first process in the queue 3
				
				printf("Process ID | Arrival Time | \tBurst Time | \t Waiting Time | Turn Around Time | Priority\n");
				
					while(count!=n)	// until count reaches the total number of processes in the queue
					{
						for(i=0; i<n; i++) // count is incremented with each complete execetion of a process 
						{
							temp=tQ; // assigning time quantum variable to temp to use with temp 2 variable to calculate turnAround for each process
							
							if(Que2[i].rem_bt==0) // if remaining burst time of a process is 0
							{
								count++; // count incremeneted since process has completely executed by the CPU
								if(count == n)
								{
									break;
								}
								else
								continue; // next iteration started
							}
						
							else
							{
								if(Que2[i].rem_bt >= 0 )
								{
									temp = Que2[i].rem_bt;	// reamining burst since is less than 8 so RR will execute for less than 8 upto the remaining burst of the process 
									Que2[i].rem_bt = 0;	// ultimately the process will be finished executing and count will be incremented next time the iteration starts from the beginning up to this process 
								}
							}
								temp2 = temp2 + temp;	// two temporary variables to help calculate total turn around time
								Que2[i].turnAround = temp2; // turn around time is obtained from two temporary variables
								last_n = i;
						}
							
					}
				
				// Here I am calculating the sum of turn around and waiting time respectively to later on calculate the average of both and display
				for(i=0; i<n; i++)
				{
					Que2[i].waiting = Que2[i].turnAround - Que2[i].burst;
					awt=awt + Que2[i].waiting;
					atat=atat+Que2[i].turnAround;
					
					printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", Que2[i].pid, Que2[i].arrival, Que2[i].burst, Que2[i].waiting, Que2[i].turnAround, Que2[i].pr); 
				}
				printf("\n");
				
				atat = atat/n;
				awt = awt/n;
				
				printf("Average Waiting Time: %f\n", awt);
				printf("Average Turn Around Time: %f\n", atat);
				
				printf("Execution of remaining Processes in Queue 2 (Round Robin Time Quantum 8 Scheduling) Completed! \n");
				printf("\n");
				
				printf("-------------------------------------------------------------------------------------------------------\n");
				printf("\n");
				/* Round Robin Algorithm with time quantum 10*/
				
				printf("Queue 3 ROUND ROBIN Time Quantum of 10 Started : \n");
				printf("\n");
				
				n = que3; // no. of processes for queue 3 updated with the variable que 3 that I used previously
				int tQ2 = 10;
				float awt_2 =0, atat_2 = 0;
				int temp_2=0;
				int count_2 = 0;
				
				int x=0;	// x for queue 4 to start from the index 0 
				int y=0;	// y for queue 3 to start from the index 0 
				
				int que4=0;	// no. of processes in Queue 4
				
				int last_n_2 = 0;	// to find the last process to exit round robin to be used for waiting time for the first process in the queue 4 (FCFS)
				
				/*Testing Starts Here */
				
				for(i=0; i<n; i++)
				{
					temp3=0;
					
					if(Que3[i].rem_bt > tQ2)
					{
						temp3 = Que3[i].rem_bt - tQ2;
						
						Que4[x] = Que3[i];
						
						Que4[x].rem_bt = temp3;
						
						x = x + 1;
						
						que3 = que3 -1;	// total processes	queue 3
						
						que4 = x;	// total processes in queue 4
					}
					
					else if(Que3[i].rem_bt <= tQ2)
					{
						Copy2[y] = Que3[i];
						
						y = y + 1;
					}
				}				
				
				n = que3;
				
				// now storing the less than tQ = 10 back in Queue 3
				for(i=0; i<n; i++)
				{
					Que3[i] = Copy2[i];
				}
				
				/* Testing Ends Here */
				
				// Bubble Sorting the processes in Queue 3 by arrival, then sorting their burst with priority
				for(i=0; i<n-1; i++)
				{
					for(j=0; j<n-i-1; j++)
					{
						if(Que3[j].arrival > Que3[j+1].arrival)
						{	
							// sorted by arrival
							temp = Que3[j].arrival;
							Que3[j].arrival=Que3[j+1].arrival;
							Que3[j+1].arrival = temp;
							
							// now sort the burst
							temp = Que3[j].burst;
							Que3[j].burst=Que3[j+1].burst;
							Que3[j+1].burst=temp;
							
							// now sort the remaining burst
							temp = Que3[j].rem_bt;
							Que3[j].rem_bt=Que3[j+1].rem_bt;
							Que3[j+1].rem_bt=temp;
							
							// now sort tje priority
							temp = Que3[j].pr;
							Que3[j].pr=Que3[j+1].pr;
							Que3[j+1].pr = temp;
						}
					}
				}

				printf("\n");
								
				Que3[0].waiting = Que2[last_n].turnAround - Que2[last_n].burst;
				
				printf("Process ID | Arrival Time | \tBurst Time | \t Waiting Time | Turn Around Time | Priority\n");
				
					while(count_2!=n)	// until count reaches the total number of processes in the queue
					{
						for(i=0; i<n; i++) // count is incremented with each complete execetion of a process 
						{
							temp=tQ2; // assigning time quantum variable to temp to use with temp 2 variable to calculate turnAround for each process
							
							if(Que3[i].rem_bt==0) // if remaining burst time of a process is 0
							{
								count_2++; // count incremeneted since process has completely executed by the CPU
								if(count_2 == n)
								{
									break;
								}
								else
								continue; // next iteration started
							}
							
							else
							{
								if(Que3[i].rem_bt >= 0 )
								{
									temp = Que3[i].rem_bt;	// reamining burst since is less than 8 so RR will execute for less than 8 upto the remaining burst of the process 
									Que3[i].rem_bt = 0;	// ultimately the process will be finished executing and count will be incremented next time the iteration starts from the beginning up to this process 
								}
							}
								temp_2 = temp_2 + temp;	// two temporary variables to help calculate total turn around time
								Que3[i].turnAround = temp_2; // turn around time is obtained from two temporary variables
								
								last_n_2 = i;
						}

					}
				
				// Here I am calculating the sum of turn around and waiting time respectively to later on calculate the average of both and display
				for(i=0; i<n; i++)
				{
					Que3[i].waiting = Que3[i].turnAround - Que3[i].burst;
					awt_2=awt_2 + Que3[i].waiting;
					atat_2=atat_2+Que3[i].turnAround;
					
					printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", Que3[i].pid, Que3[i].arrival, Que3[i].burst, Que3[i].waiting, Que3[i].turnAround, Que3[i].pr); 
				}
				printf("\n");
				
				atat_2 = atat_2/n;
				awt_2 = awt_2/n;
				
				printf("Average Waiting Time: %f\n", awt_2);
				printf("Average Turn Around Time: %f\n", atat_2);
				
				printf("Execution of remaining Processes in Queue 3 (Round Robin Time Quantum 10 Scheduling) Completed! \n");
				printf("\n");
				
				printf("-------------------------------------------------------------------------------------------------------\n");
				printf("\n");
				/* First Come First Server Schedule Algorithm Begins*/
				
				printf("Queue 4 First Come First Server Scheduler Started : \n");
				printf("\n");
				
				n=que4;	// updating the number of processes in Queue 4
				
				// Bubble Sorting the processes in Queue 4 by arrival, then sorting their burst with priority
				for(i=0; i<n-1; i++)
				{
					for(j=0; j<n-i-1; j++)
					{
						if(Que4[j].arrival > Que4[j+1].arrival)
						{	
							// sorted by arrival
							temp = Que4[j].arrival;
							Que4[j].arrival=Que4[j+1].arrival;
							Que4[j+1].arrival = temp;
							
							// now sort the burst
							temp = Que4[j].burst;
							Que4[j].burst=Que4[j+1].burst;
							Que4[j+1].burst=temp;
							
							// now sort the remain burst
							temp = Que4[j].rem_bt;
							Que4[j].rem_bt=Que4[j+1].rem_bt;
							Que4[j+1].rem_bt=temp;
							
							// now sorted the priority
							temp = Que4[j].pr;
							Que4[j].pr=Que4[j+1].pr;
							Que4[j+1].pr = temp;
						}
					}
				}
				
				// calculating the waiting and turn around time here
				float atat_3 = 0;
				float awt_3 = 0;
				
				Que4[0].waiting = Que3[last_n_2].turnAround - Que3[last_n_2].burst;	// first process wait time
				
				turnAround = Que3[last_n_2].turnAround;
			
				printf("Process ID | Arrival Time | \tBurst Time | \t Waiting Time | Turn Around Time | Priority\n");
				
				for(i=0; i<n; i++)
				{
					completion = completion + Que4[i].rem_bt;
					turnAround = completion - Que4[i].arrival;
					Que4[i].turnAround = turnAround;
					Que4[i].waiting = Que4[i].turnAround - Que4[i].rem_bt;
					
					atat_3 = atat_3 + Que4[i].turnAround;
					awt_3 = awt_3 + Que4[i].waiting;
					
					printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", Que4[i].pid, Que4[i].arrival, Que4[i].burst, Que4[i].waiting, Que4[i].turnAround, Que4[i].pr); 
				}
				
				atat_3 = atat_3/n;
				awt_3 = awt_3/n;
				
				printf("Average Waiting Time: %f\n", awt_3);
				printf("Average Turn Around Time: %f\n", atat_3);
				
				printf("Execution of remaining Processes in Queue 4 (First Come First Server Scheduling) Completed! \n");
				printf("\n");
				
				// code ends here
				
				printf("\n");
				break;
			}
			
		default:
			{
				printf("\n");
				
				printf("Wrong input!\n");
				
				printf("\n");
				break;
			}
	}
	
	printf("Exited!\n");
}
