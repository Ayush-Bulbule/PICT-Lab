
#include <iostream>
using namespace std;

class Jobs
{
    string name;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int pri;

public:
    Jobs()
    {
        name = "";
        at = 0;
        bt = 0;
        ct = 0;
        tat = 0;
        wt = 0;
        pri = 0;
    }
    void createJob()
    {
        cout << "Enter the name of the process: ";
        cin >> name;

        cout << "Enter the arrival time: ";
        cin >> at;
        cout << "Enter the burst time: ";
        cin >> bt;
    }

    friend class Schedular;
};
class Schedular
{
    Jobs *jobs;
    int np;

public:
    Schedular()
    {
        int n;
        cout << "Enter the no of processes: ";
        cin >> n;
        np = n;
        jobs = new Jobs[np];

        for (int i = 0; i < np; i++)
        {
            jobs[i].createJob();
            cout << endl;
        }
    }

    // Function to show all the jobs
    void showJobs(Jobs jobs[], int np)
    {
        cout << "Name\tAT\tBT\tCT\tTAT\tWT" << endl;
        for (int i = 0; i < np; i++)
        {
            cout << jobs[i].name << "\t" << jobs[i].at << "\t"
                 << jobs[i].bt << "\t" << jobs[i].ct << "\t"
                 << jobs[i].tat << "\t" << jobs[i].wt << endl;
        }
    }

    // function to show average
    void show_average(float avg_tat, float avg_wt)
    {
        cout << "\n Average Turn Around Time: " << avg_tat << endl;
        cout << "\n Average Waiting Time: " << avg_wt << endl;
    }

    void calcAvg(Jobs *gantt)
    {
        float avg_wt = 0, avg_tat = 0;

        for (int i = 0; i < np; i++)
        {
            avg_tat = gantt[i].tat;
            avg_wt = gantt[i].wt;
        }
        cout << "Average TAT: " << (avg_tat / np) << endl;
        cout << "Avegrage CT: " << (avg_wt / np) << endl;
    }

    // FCFS
    void fcfs()
    {
        Jobs v[np]; // copy
        for (int i = 0; i < np; i++)
        {
            v[i] = jobs[i];
        }
        // Sort array acc to arrival time
        for (int i = 0; i < np; i++)
        {
            int m = i;
            for (int j = i + 1; j < np; j++)
            {
                if (v[m].at > v[j].at)
                {
                    m = j; // find index
                }
            }
            // swap
            if (i != m)
            {
                swap(v[m], v[i]);
            }
        }
        // Simply calculate the gantt
        Jobs gantt[np];
        int ct = 0;
        for (int i = 0; i < np; i++)
        {
            gantt[i] = v[i];
            ct += gantt[i].bt;
            gantt[i].ct = ct;
            gantt[i].tat = gantt[i].ct - gantt[i].at;
            gantt[i].wt = gantt[i].tat - gantt[i].bt;
        }
        showJobs(gantt, np);
        // Calculate the avegrage
        calcAvg(gantt);
    }
}