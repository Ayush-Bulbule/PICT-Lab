/**
 * Practical No 1:Implement CPU scheduling algorithm
 * Write a program to simulate CPU Scheduling Algorithms: FCFS, SJF (Preemptive), Priority
 * (Non-Preemptive) and Round Robin (Preemptive).
 * */
#include <bits/stdc++.h>
using namespace std;

class Jobs
{
    string name;
    int arrival_t;
    int burst_t;
    int completion_t;
    int turnaround_t;
    int waiting_t;
    int priority_t;

public:
    Jobs()
    {
        string name = "";
        int arrival_t = 0;
        int burst_t = 0;
        int completion_t = 0;
        int turnaround_t = 0;
        int waiting_t = 0;
        int priority_t = 0;
    }

    void createJob()
    {
        cout << "Enter name of process : ";
        cin >> name;
        cout << "Arrival Time : ";
        cin >> arrival_t;
        cout << "Burst Time : ";
        cin >> burst_t;
    }

    friend class Scheduler;
};

class Scheduler
{
    Jobs *jobs;
    int np;

public:
    Scheduler()
    {
        cout << "Enter number of Processes : ";
        cin >> np;
        jobs = new Jobs[np];

        for (int i = 0; i < np; i++)
        {
            jobs[i].createJob();
            cout << endl;
        }
    }

    void showjobs(Jobs jobs[], int np)
    {
        cout << "Name\tAT\tBT\tCT\tTAT\tWT" << endl;
        for (int i = 0; i < np; i++)
        {
            cout << jobs[i].name << "\t" << jobs[i].arrival_t << "\t" << jobs[i].burst_t << "\t" << jobs[i].completion_t << "\t" << jobs[i].turnaround_t << "\t" << jobs[i].waiting_t << endl;
        }
    }

    void show_average(float avg_tat, float avg_wt)
    {
        cout << "\nAverage Turnarount Time : " << avg_tat << "\nAverage Waiting Time : " << avg_wt << endl;
    }

    // Function to implement First Come First Serve (FCFS) scheduling algorithm
    void FCFS()
    {
        // Copy the jobs array to a temporary array 'v'
        Jobs v[np];
        for (int i = 0; i < np; i++)
            v[i] = jobs[i];

        // Sort the 'v' array based on arrival time using selection sort
        for (int i = 0; i < np - 1; i++)
        {
            int min_i = i;
            for (int j = i + 1; j < np; j++)
            {
                // Find the job with the minimum arrival time
                if (v[j].arrival_t < v[min_i].arrival_t)
                {
                    min_i = j;
                }
            }

            // Swap the jobs if needed to maintain the order
            if (min_i != i)
                swap(v[i], v[min_i]);
        }

        // Initialize variables for completion time, Gantt chart, and calculate turnaround and waiting times
        int ct = 0;
        Jobs gantt[np];
        for (int i = 0; i < np; i++)
        {
            // Update Gantt chart and completion time
            gantt[i] = v[i];
            ct += gantt[i].burst_t;

            // Calculate turnaround and waiting times
            gantt[i].completion_t = ct;
            gantt[i].turnaround_t = gantt[i].completion_t - gantt[i].arrival_t;
            gantt[i].waiting_t = gantt[i].turnaround_t - gantt[i].burst_t;
        }

        // Calculate average turnaround and waiting times
        float avg_tat = 0, avg_wt = 0;
        for (int i = 0; i < np; i++)
        {
            avg_tat += gantt[i].turnaround_t;
            avg_wt += gantt[i].waiting_t;
        }
        avg_tat = avg_tat / np;
        avg_wt = avg_wt / np;

        // Display the Gantt chart and average turnaround/waiting times
        showjobs(gantt, np);
        show_average(avg_tat, avg_wt);
    }

    void Priority()
    {
        Jobs *v = new Jobs[np];
        int totalTime = 0;

        // Get priority and calculate total burst time
        for (int i = 0; i < np; i++)
        {
            v[i] = jobs[i];
            cout << "Enter Priority of " << v[i].name << " : ";
            totalTime += v[i].burst_t;
            cin >> v[i].priority_t;
        }

        // Sort by Arrival Time
        sort(v, v + np, [](const Jobs &lhs, const Jobs &rhs)
             { return lhs.arrival_t <= rhs.arrival_t; });

        int aj = 0; // current job
        int timeStamp = 0;
        vector<Jobs> ReadyQ;
        Jobs *gantt = new Jobs[np];
        int ja = 0; // gantt

        while (timeStamp < totalTime)
        {
            // Get all the process in the ready Queue
            while (aj < np && v[aj].arrival_t <= timeStamp)
            {
                ReadyQ.push_back(v[aj]);
                aj++;
            }

            // Sort by Priority
            sort(ReadyQ.begin(), ReadyQ.end(), [](const Jobs &lhs, const Jobs &rhs)
                 { return lhs.priority_t < rhs.priority_t; });

            for (int i = 0; i < ReadyQ.size(); i++)
            {
                cout << ReadyQ[i].name << "|" << ReadyQ[i].priority_t << " ";
            }
            cout << endl;

            // Take the first process in the Ready Queue
            if (ReadyQ.size() > 0)
            {
                gantt[ja] = ReadyQ[0];
                timeStamp += gantt[ja].burst_t;
                gantt[ja].completion_t = timeStamp;
                gantt[ja].turnaround_t = gantt[ja].completion_t - gantt[ja].arrival_t;
                gantt[ja].waiting_t = gantt[ja].turnaround_t - gantt[ja].burst_t;
                ja++;
                ReadyQ.erase(ReadyQ.begin());
            }
        }
        cout << endl;

        float avg_tat = 0, avg_wt = 0;

        for (int i = 0; i < np; i++)
        {
            avg_tat += gantt[i].turnaround_t;
            avg_wt += gantt[i].waiting_t;
        }

        avg_tat = avg_tat / np;
        avg_wt = avg_wt / np;
        showjobs(gantt, np);
        show_average(avg_tat, avg_wt);
    }

    void SJF()
    {
        Jobs *v = new Jobs[np];
        int totalTime = 0;
        for (int i = 0; i < np; i++)
        {
            v[i] = jobs[i];
            totalTime += v[i].burst_t;
        }

        // Sort (Arrival Time)
        sort(v, v + np, [](const Jobs &lhs, const Jobs &rhs)
             { return lhs.arrival_t < rhs.arrival_t; });

        vector<string> gantt;
        int aj = 0;
        int timeStamp = 0;
        vector<Jobs> readyQ;

        while (timeStamp < totalTime)
        {
            while (aj < np && v[aj].arrival_t <= timeStamp)
            {
                readyQ.push_back(v[aj]);
                aj++;
            }

            sort(readyQ.begin(), readyQ.end(), [](const Jobs &lhs, const Jobs &rhs)
                 { return lhs.burst_t < rhs.burst_t; });

            if (readyQ.size() > 0)
            {
                gantt.push_back(readyQ[0].name);
                readyQ[0].burst_t--;

                if (readyQ[0].burst_t == 0)
                {
                    for (int i = 0; i < np; i++)
                    {
                        if (jobs[i].name == readyQ[0].name)
                        {
                            jobs[i].completion_t = timeStamp + 1;
                            jobs[i].turnaround_t = jobs[i].completion_t - jobs[i].arrival_t;
                            jobs[i].waiting_t = jobs[i].turnaround_t - jobs[i].burst_t;
                        }
                    }

                    readyQ.erase(readyQ.begin());
                }
            }

            timeStamp++;
        }

        float avg_tat = 0, avg_wt = 0;

        for (int i = 0; i < np; i++)
        {
            avg_tat += jobs[i].turnaround_t;
            avg_wt += jobs[i].waiting_t;
        }

        avg_tat = avg_tat / np;
        avg_wt = avg_wt / np;
        showjobs(jobs, np);
        show_average(avg_tat, avg_wt);
    }

    void RoundRobin()
    {
        int interval;
        cout << "Enter the Time Quantum : ";
        cin >> interval;

        Jobs *v = new Jobs[np];
        int totalTime = 0;

        // Get the jobs in v
        for (int i = 0; i < np; i++)
        {
            v[i] = jobs[i];
            totalTime += v[i].burst_t;
        }

        // Sort (Arrival Time)
        sort(v, v + np, [](const Jobs &lhs, const Jobs &rhs)
             { return lhs.arrival_t < rhs.arrival_t; });

        vector<string> gantt;
        int aj = 0;
        int timeStamp = 0;
        queue<Jobs> readyQ;
        Jobs added_job;
        added_job.burst_t = 0;
        int added_burst = 0;

        while (timeStamp < totalTime)
        {
            // Put the processes in the Ready Queue
            while (aj < np && v[aj].arrival_t <= timeStamp)
            {
                readyQ.push(v[aj]);
                aj++;
            }

            // If the previously added process has not yet completed then add it at the end of the queue
            if (added_job.burst_t > 0)
            {
                readyQ.push(added_job);
            }

            if (readyQ.size() > 0)
            {
                added_job = readyQ.front();
                readyQ.pop();
                gantt.push_back(added_job.name);

                if (added_job.burst_t > interval)
                {
                    added_job.burst_t = added_job.burst_t - interval;
                    added_burst = interval;
                }
                else
                {
                    added_burst = added_job.burst_t;
                    added_job.burst_t = 0;
                }

                if (added_job.burst_t == 0)
                {
                    for (int i = 0; i < np; i++)
                    {
                        if (jobs[i].name == added_job.name)
                        {
                            jobs[i].completion_t = timeStamp + added_burst;
                            jobs[i].turnaround_t = jobs[i].completion_t - jobs[i].arrival_t;
                            jobs[i].waiting_t = jobs[i].turnaround_t - jobs[i].burst_t;
                        }
                    }
                }
            }

            timeStamp += added_burst;
        }

        float avg_tat = 0, avg_wt = 0;

        for (int i = 0; i < np; i++)
        {
            avg_tat += jobs[i].turnaround_t;
            avg_wt += jobs[i].waiting_t;
        }

        avg_tat = avg_tat / np;
        avg_wt = avg_wt / np;

        showjobs(jobs, np);
        show_average(avg_tat, avg_wt);
    }
};

int main()
{
    Scheduler schedule;

    schedule.FCFS();
    // schedule.Priority();
    // schedule.SJF();
    schedule.RoundRobin();
}