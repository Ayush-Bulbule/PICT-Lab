/**
 * Practical No 1:Implement CPU scheduling algorithm
 * Write a program to simulate CPU Scheduling Algorithms: FCFS, SJF (Preemptive), Priority
 * (Non-Preemptive) and Round Robin (Preemptive).
 * */

#include <iostream>
#define N 10
using namespace std;

class Process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;

public:
    Process()
    {
        process_id = 0;
        arrival_time = 0;
        burst_time = 0;
        remaining_burst_time = 0;
    }
    friend class ProcessScheduling;
};

class ProcessScheduling
{
    int num_process;
    Process *process;

    // FCFS
    void fcfs(int *ct, int *tat, int *wt)
    {
        int current_time = 0;

        for (int i = 0; i < num_process; i++)
        {
            current_time = max(current_time, process[i].arrival_time);
            ct[i] = current_time + process[i].burst_time;
            current_time = ct[i];
        }

        for (int i = 0; i < num_process; i++)
        {
            tat[i] = ct[i] - process[i].arrival_time;
            wt[i] = tat[i] - process[i].burst_time;
        }
    }

    // SJF
    void sjf(int *ct, int *tat, int *wt)
    {
        int current_time = 0;
        int completed_processes = 0;

        while (completed_processes < num_process)
        {
            int shortest_burst_time = 99999;
            int short_process_index = -1;

            for (int i = 0; i < num_process; i++)
            {
                if (process[i].arrival_time <= current_time && process[i].remaining_burst_time > 0)
                {
                    shortest_burst_time = process[i].remaining_burst_time;
                    short_process_index = i;
                }
            }

            if (short_process_index == -1)
            {
                current_time++;
            }
            else
            {
                process[short_process_index].remaining_burst_time--;
                current_time++;

                if (process[short_process_index].remaining_burst_time == 0)
                {
                    ct[short_process_index] = current_time;
                    completed_processes++;
                }
            }
        }

        for (int i = 0; i < num_process; i++)
        {
            tat[i] = ct[i] - process[i].arrival_time;
            wt[i] = tat[i] - process[i].burst_time;
        }
    }

public:
    ProcessScheduling(int n)
    {
        num_process = n;
        process = new Process[n];
    }

    // Read Data
    void readProcesses()
    {
        cout << "Enter the details of " << num_process << " process:" << endl;

        for (int i = 0; i < num_process; i++)
        {
            process[i].process_id = i + 1;
            cout << "Enter Process " << i + 1 << " Arrival time : ";
            cin >> process[i].arrival_time;
            cout << "Enter Process " << i + 2 << " Burst Time: ";
            cin >> process[i].burst_time;

            process[i].remaining_burst_time = process[1].burst_time;
        }
    }

    // FCFS
    void displayFCFS()
    {

        int *ct = new int[num_process];
        int *tat = new int[num_process];
        int *wt = new int[num_process];
        int total_tat = 0, total_wt = 0;

        fcfs(ct, tat, wt);

        cout << "\nFCFS Scheduling" << endl;
        cout << "PId\tAT\tBT\tCT\tTAT\tWT" << endl;
        for (int i = 0; i < num_process; i++)
        {
            cout << process[i].process_id << "\t" << process[i].arrival_time << "\t" << process[i].burst_time << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
            total_tat += tat[i];
            total_wt += wt[i];
        }
        cout << "\nAvg. Turnaround Time: " << total_tat / num_process;
        cout << "\nAvg. Waiting Time: " << total_wt / num_process;

        delete[] ct;
        delete[] tat;
        delete[] wt;
    }

    void displaySJF()
    {
        // yet to impliment
        int *ct = new int[num_process];
        int *tat = new int[num_process];
        int *wt = new int[num_process];
        int total_tat = 0, total_wt = 0;
        sjf(ct, tat, wt);

        cout << "\nSJF Scheduling" << endl;
        cout << "PId\tAT\tBT\tCT\tTAT\tWT" << endl;
        for (int i = 0; i < num_process; i++)
        {
            cout << process[i].process_id << "\t" << process[i].arrival_time << "\t" << process[i].burst_time << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
            total_tat += tat[i];
            total_wt += wt[i];
        }
        cout << "\nAvg. Turnaround Time: " << total_tat / num_process;
        cout << "\nAvg. Waiting Time: " << total_wt / num_process;

        delete[] ct;
        delete[] tat;
        delete[] wt;
    }
};

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    ProcessScheduling ps(n);
    ps.readProcesses();
    ps.displayFCFS();
    ps.displaySJF();

    return 0;
}