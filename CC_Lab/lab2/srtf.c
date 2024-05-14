#include <stdio.h>

int main()
{
    int n, i, j;
    int pid[20], at[20], bt[20];
    int remaining_time[20], wt[20], ct[20];
    int tat[20], rt[20];
    int total_wt = 0, total_turnaround_time = 0, total_response_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        remaining_time[i] = bt[i];
    }

    int current_time = 0, completed_processes = 0;

    while (completed_processes < n)
    {
        int shortest_process = -1;
        int min_remaining_time = 999999;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= current_time && remaining_time[i] > 0 && remaining_time[i] < min_remaining_time)
            {
                shortest_process = i;
                min_remaining_time = remaining_time[i];
            }
        }

        if (shortest_process == -1)
        {
            current_time++;
            continue;
        }

        if (current_time == 0)
        {
            rt[shortest_process] = 0;
        }
        else
        {
            rt[shortest_process] = current_time - at[shortest_process];
        }

        remaining_time[shortest_process]--;

        if (remaining_time[shortest_process] == 0)
        {
            completed_processes++;
            ct[shortest_process] = current_time + 1;
            tat[shortest_process] = ct[shortest_process] - at[shortest_process];
            wt[shortest_process] = tat[shortest_process] - bt[shortest_process];

            total_wt += wt[shortest_process];
            total_turnaround_time += tat[shortest_process];
            total_response_time += rt[shortest_process];
        }

        current_time++;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        // printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], ct[i], tat[i], rt[i]);
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    double average_wt = (double)total_wt / n;
    double average_turnaround_time = (double)total_turnaround_time / n;
    double average_response_time = (double)total_response_time / n;

    printf("\nAverage Waiting Time: %.2lf\n", average_wt);
    printf("Average Turnaround Time: %.2lf\n", average_turnaround_time);
    // printf("Average Response Time: %.2lf\n", average_response_time);

    return 0;
}