#include <iostream>

using namespace std;
#define INT_MAX 9999;

class ProcessScheduling
{
private:
    struct Process
    {
        int process_id;
        int arrival_time;
        int burst_time;
        int remaining_burst_time;
        int priority;
    };

    int num_processes;
    Process *processes;
    int time_quantum;

    void fcfs(int *ct, int *tat, int *wt)
    {
        int current_time = 0;
        for (int i = 0; i < num_processes; i++)
        {
            current_time = max(current_time, processes[i].arrival_time);
            ct[i] = current_time + processes[i].burst_time;
            current_time = ct[i];
        }

        for (int i = 0; i < num_processes; i++)
        {
            tat[i] = ct[i] - processes[i].arrival_time;
            wt[i] = tat[i] - processes[i].burst_time;
        }
    }

    void sjf(int *ct, int *tat, int *wt)
    {
        int current_time = 0;
        int completed_processes = 0;
        while (completed_processes < num_processes)
        {
            int shortest_burst_time = INT_MAX;
            int shortest_process_index = -1;

            for (int i = 0; i < num_processes; i++)
            {
                if (processes[i].arrival_time <= current_time && processes[i].remaining_burst_time > 0)
                {
                    if (processes[i].remaining_burst_time < shortest_burst_time)
                    {
                        shortest_burst_time = processes[i].remaining_burst_time;
                        shortest_process_index = i;
                    }
                }
            }

            if (shortest_process_index == -1)
            {
                current_time++;
            }
            else
            {
                processes[shortest_process_index].remaining_burst_time--;
                current_time++;
                if (processes[shortest_process_index].remaining_burst_time == 0)
                {
                    ct[shortest_process_index] = current_time;
                    completed_processes++;
                }
            }
        }

        for (int i = 0; i < num_processes; i++)
        {
            tat[i] = ct[i] - processes[i].arrival_time;
            wt[i] = tat[i] - processes[i].burst_time;
        }
    }

    void roundRobin(int *ct, int *tat, int *wt)
    {
        int current_time = 0;
        int completed_processes = 0;
        int *remaining_time = new int[num_processes];
        for (int i = 0; i < num_processes; i++)
        {
            remaining_time[i] = processes[i].burst_time;
        }

        while (completed_processes < num_processes)
        {
            bool all_processes_done = true;
            for (int i = 0; i < num_processes; i++)
            {
                if (processes[i].arrival_time <= current_time && remaining_time[i] > 0)
                {
                    all_processes_done = false;
                    if (remaining_time[i] > time_quantum)
                    {
                        current_time += time_quantum;
                        remaining_time[i] -= time_quantum;
                    }
                    else
                    {
                        current_time += remaining_time[i];
                        ct[i] = current_time;
                        remaining_time[i] = 0;
                        completed_processes++;
                    }
                }
            }
            if (all_processes_done)
            {
                current_time++;
            }
        }

        for (int i = 0; i < num_processes; i++)
        {
            tat[i] = ct[i] - processes[i].arrival_time;
            wt[i] = tat[i] - processes[i].burst_time;
        }

        delete[] remaining_time;
    }

    void priorityNonPreemptive(int *ct, int *tat, int *wt)
    {
        int current_time = 0;
        int completed_processes = 0;
        while (completed_processes < num_processes)
        {
            int highest_priority = INT_MAX;
            int highest_priority_process_index = -1;

            for (int i = 0; i < num_processes; i++)
            {
                if (processes[i].arrival_time <= current_time && processes[i].remaining_burst_time > 0)
                {
                    if (processes[i].priority < highest_priority)
                    {
                        highest_priority = processes[i].priority;
                        highest_priority_process_index = i;
                    }
                }
            }

            if (highest_priority_process_index == -1)
            {
                current_time++;
            }
            else
            {
                current_time += processes[highest_priority_process_index].burst_time;
                ct[highest_priority_process_index] = current_time;
                processes[highest_priority_process_index].remaining_burst_time = 0;
                completed_processes++;
            }
        }

        for (int i = 0; i < num_processes; i++)
        {
            tat[i] = ct[i] - processes[i].arrival_time;
            wt[i] = tat[i] - processes[i].burst_time;
        }
    }

public:
    ProcessScheduling(int n) : num_processes(n)
    {
        processes = new Process[n];
    }

    ~ProcessScheduling()
    {
        delete[] processes;
    }

    void inputProcesses()
    {
        cout << "Enter Arrival Time, Burst Time, and Priority for each process:\n";
        for (int i = 0; i < num_processes; i++)
        {
            processes[i].process_id = i + 1;
            cout << "Process " << i + 1 << " Arrival Time: ";
            cin >> processes[i].arrival_time;
            cout << "Process " << i + 1 << " Burst Time: ";
            cin >> processes[i].burst_time;
            cout << "Process " << i + 1 << " Priority: ";
            cin >> processes[i].priority;
            processes[i].remaining_burst_time = processes[i].burst_time;
        }
    }

    void setQuantum(int tq)
    {
        time_quantum = tq;
    }

    void fcfsDisplayTable()
    {
        int *completion_time = new int[num_processes];
        int *turnaround_time = new int[num_processes];
        int *waiting_time = new int[num_processes];

        fcfs(completion_time, turnaround_time, waiting_time);

        cout << "\nFCFS Scheduling:\n";
        cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
        for (int i = 0; i < num_processes; i++)
        {
            cout << processes[i].process_id << "\t\t" << processes[i].arrival_time << "\t\t"
                 << processes[i].burst_time << "\t\t" << completion_time[i] << "\t\t\t"
                 << turnaround_time[i] << "\t\t\t" << waiting_time[i] << "\n";
        }

        delete[] completion_time;
        delete[] turnaround_time;
        delete[] waiting_time;
    }

    void sjfDisplayTable()
    {
        int *completion_time = new int[num_processes];
        int *turnaround_time = new int[num_processes];
        int *waiting_time = new int[num_processes];

        sjf(completion_time, turnaround_time, waiting_time);

        cout << "\nPreemptive SJF Scheduling:\n";
        cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
        for (int i = 0; i < num_processes; i++)
        {
            cout << processes[i].process_id << "\t\t" << processes[i].arrival_time << "\t\t"
                 << processes[i].burst_time << "\t\t" << completion_time[i] << "\t\t\t"
                 << turnaround_time[i] << "\t\t\t" << waiting_time[i] << "\n";
        }

        delete[] completion_time;
        delete[] turnaround_time;
        delete[] waiting_time;
    }

    void roundRobinDisplayTable()
    {
        int *completion_time = new int[num_processes];
        int *turnaround_time = new int[num_processes];
        int *waiting_time = new int[num_processes];

        roundRobin(completion_time, turnaround_time, waiting_time);

        cout << "\nPreemptive Round Robin Scheduling:\n";
        cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
        for (int i = 0; i < num_processes; i++)
        {
            cout << processes[i].process_id << "\t\t" << processes[i].arrival_time << "\t\t"
                 << processes[i].burst_time << "\t\t" << completion_time[i] << "\t\t\t"
                 << turnaround_time[i] << "\t\t\t" << waiting_time[i] << "\n";
        }

        delete[] completion_time;
        delete[] turnaround_time;
        delete[] waiting_time;
    }
    void priorityNonPreemptiveDisplayTable()
    {
        int *completion_time = new int[num_processes];
        int *turnaround_time = new int[num_processes];
        int *waiting_time = new int[num_processes];

        priorityNonPreemptive(completion_time, turnaround_time, waiting_time);

        cout << "\nNon-Preemptive Priority Scheduling:\n";
        cout << "Process ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n";
        for (int i = 0; i < num_processes; i++)
        {
            cout << processes[i].process_id << "\t\t" << processes[i].arrival_time << "\t\t"
                 << processes[i].burst_time << "\t\t" << processes[i].priority << "\t\t"
                 << completion_time[i] << "\t\t\t" << turnaround_time[i] << "\t\t\t" << waiting_time[i] << "\n";
        }

        delete[] completion_time;
        delete[] turnaround_time;
        delete[] waiting_time;
    }
};

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    ProcessScheduling ps(n);
    ps.inputProcesses();

    cout << "Enter the time quantum for Round Robin: ";
    int tq;
    cin >> tq;
    ps.setQuantum(tq);

    ps.priorityNonPreemptiveDisplayTable();
    ps.fcfsDisplayTable();
    ps.sjfDisplayTable();
    ps.roundRobinDisplayTable();
    // cout << "\n Piority:" << endl;

    return 0;
}
