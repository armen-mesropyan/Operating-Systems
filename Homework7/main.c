#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    int completed;
};

int compareByArrival(const void *a, const void *b)
{
    struct Process *p1 = (struct Process *) a;
    struct Process *p2 = (struct Process *) b;
    return p1->arrival_time - p2->arrival_time;
}

int compareByBurst(const void *a, const void *b)
{
    struct Process *p1 = (struct Process *) a;
    struct Process *p2 = (struct Process *) b;
    if (p1->burst_time == p2->burst_time)
        return p1->arrival_time - p2->arrival_time;
    return p1->burst_time - p2->burst_time;
}

void FCFS(struct Process p[], int n)
{
    qsort(p, n, sizeof(struct Process), compareByArrival);
    int current_time = 0;
    float total_waiting = 0, total_turnaround = 0, total_response = 0;

    printf("\n=====FCFS Scheduling=====\n");
    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time)
        {
            current_time = p[i].arrival_time;
        }
        printf("| P%d ", p[i].pid);
        p[i].waiting_time = current_time - p[i].arrival_time;
        p[i].response_time = p[i].waiting_time;
        current_time += p[i].burst_time;
        p[i].turnaround_time = current_time - p[i].arrival_time;
        total_waiting += p[i].waiting_time;
        total_turnaround += p[i].turnaround_time;
        total_response += p[i].response_time;
    }
    printf("|");

    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n",p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].response_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround / n);
    printf("Average Response Time: %.2f\n", total_response / n);
}

void SJF(struct Process p[], int n)
{
    int completed = 0, current_time = 0;
    float total_waiting = 0, total_turnaround = 0, total_response = 0;
    for (int i = 0; i < n; i++)
        p[i].completed = 0;
    printf("\n=====SJF (Non-preemptive) Scheduling=====\n");
    printf("Gantt Chart: ");
    while (completed < n)
    {
        int next_index = -1, min_burst = 9999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && p[i].completed == 0)
            {
                if (p[i].burst_time < min_burst || (p[i].burst_time == min_burst && p[i].arrival_time < p[next_index].arrival_time))
                {
                    min_burst = p[i].burst_time;
                    next_index = i;
                }
            }
        }
        if (next_index == -1)
        {
            current_time++;
            continue;
        }
        printf("| P%d ", p[next_index].pid);

        p[next_index].waiting_time = current_time - p[next_index].arrival_time;

        if (p[next_index].waiting_time < 0)
        {
            p[next_index].waiting_time = 0;
        }
        p[next_index].response_time = p[next_index].waiting_time;

        current_time += p[next_index].burst_time;

        p[next_index].turnaround_time = current_time - p[next_index].arrival_time;

        p[next_index].completed = 1;

        completed++;
        total_waiting += p[next_index].waiting_time;
        total_turnaround += p[next_index].turnaround_time;
        total_response += p[next_index].response_time;
    }

    printf("|");
    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].response_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround / n);
    printf("Average Response Time: %.2f\n", total_response / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", p[i].pid);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    FCFS(p, n);
    SJF(p, n);
    return 0;
}
