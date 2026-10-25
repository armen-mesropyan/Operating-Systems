Armen Mesropyan

This is CPU scheduling simulator that simulates FCFS (first come first served) and SJF (shortest job first)

It calculates waiting time, turnaround time, response time, and prints Gantt chart for the scheduling order.

To use the code gcc or any c compiler is needed, the code can be compiledusing this command: gcc main.c -o main 

And after the compilation the executable needs to be run using this command: ./main

The program asks for an input:

Enter the number of processes: Y
Enter arrival time and burst time for process 1: X1 X2
Enter arrival time and burst time for process 2: X1 X2
Enter arrival time and burst time for process 3: X1 X2

Y in this case is the number of processes we want to simulate, X1 is the arrival time of the current process and X2 is the burst time, X1 and X2 should be separated strictly by space and no other characters are permitted for this input.

After getting the input the program will simulate the scheduling process and output the result like this: 

Enter the number of processes: 4
Enter arrival time and burst time for process 1: 0 8
Enter arrival time and burst time for process 2: 1 4
Enter arrival time and burst time for process 3: 2 9
Enter arrival time and burst time for process 4: 3 5

=====FCFS Scheduling=====
Gantt Chart: | P1 | P2 | P3 | P4 |
PID	Arrival	Burst	Waiting	Turnaround	Response
1	0	8	0	8		0        8          0
2	1	4	7	11		7        11         7
3	2	9	10	19		10       19         10
4	3	5	18	23		18       23         18

Average Waiting Time: 8.75
Average Turnaround Time: 15.25
Average Response Time: 8.75

=====SJF (Non-preemptive) Scheduling=====
Gantt Chart: | P1 | P2 | P4 | P3 |
PID	Arrival	Burst	Waiting	Turnaround	Response
1	0	8	0	8		0        8          0
2	1	4	7	11		7        11         7
3	2	9	15	24		15       24         15
4	3	5	9	14		9        14         9

Average Waiting Time: 7.75
Average Turnaround Time: 14.25
Average Response Time: 7.75