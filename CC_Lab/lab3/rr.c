#include<stdio.h>  
#include<conio.h>  
  
void main()  
{    
    int i, n, quant, wt=0, tat=0, at[10], bt[10], temp[10];
    // float avg_wt, avg_tat;
    printf("Total number of process in the system: ");
    scanf("%d", &n);
    y = n;
    for(i=0; i<n; i++)
    {
        printf("\nEnter the Arrival and Burst time of the Process[%d]\n", i+1);
        printf("Arrival time is: ");
        scanf("%d", &at[i]);
        printf("\nBurst time is: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    printf("Enter the Time Quantum for the process: ");
    scanf("%d", &quant);
    printf("\nProcess No \t\t Burst Time \t\t TAT \t\t Waiting Time");

}