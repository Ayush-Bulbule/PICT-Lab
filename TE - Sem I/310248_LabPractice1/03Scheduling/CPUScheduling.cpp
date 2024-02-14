//============================================================================
// Name        : lpassignment1.cpp
// Author      : durvesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
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
        cout << "Enter the burst time for the process: ";
        cin >> bt;
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
        cout << "Enter the number of process: ";
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
            cout << jobs[i].name << "\t" << jobs[i].at << "\t" << jobs[i].bt << "\t"
                 << jobs[i].ct << "\t" << jobs[i].tat << "\t" << jobs[i].wt << endl;
        }
    }

    void show_average(float avg_tat, float avg_wt)
    {
        cout << "\nAverage Turn around Time : " << avg_tat
             << "\nAverage Waiting Time : " << avg_wt << endl;
    }

    void fcfs()
    {
        Jobs v[np];

        for (int i = 0; i < np; i++)
        {
            v[i] = jobs[i];
        }

        // sort the array acc to the arrival time

        for (int i = 0; i < np - 1; i++)
        {
            int m = i;
            for (int j = i + 1; j < np; j++)
            {
                if (v[m].at > v[j].at)
                {
                    m = j;
                }
            }
            if (i != m)
                swap(v[m], v[i]);
        }

        // prepare a gannt chart
        Jobs gannt[np];
        int ct = 0;
        for (int i = 0; i < np; i++)
        {
            gannt[i] = v[i];
            ct += gannt[i].bt;
            gannt[i].ct = ct;
            gannt[i].tat = gannt[i].ct - gannt[i].at;
            gannt[i].wt = gannt[i].tat - gannt[i].bt;
        }

        float avg_wt = 0, avg_tat = 0;

        for (int i = 0; i < np; i++)
        {
            avg_tat += gannt[i].tat;
            avg_wt += gannt[i].wt;
        }

        avg_wt = avg_wt / np;
        avg_tat = avg_tat / np;

        showjobs(gannt, np);
        show_average(avg_tat, avg_wt);
    }

    void RoundRobin()
    {
        // Inut the time quantum
        int interval;
        cout << "Enter the time quantum: ";
        cin >> interval;

        // Create a new Copy and also calculate total time
        Jobs *v = new Jobs[np];
        int totalTime = 0;
        for (int i = 0; i < np; i++)
        {
            v[i] = jobs[i];
            totalTime += v[i].bt;
        }

        // sort according to the arrival time
        sort(v, v + np,
             [](const Jobs &lhs, const Jobs &rhs)
             { return lhs.at <= rhs.at; });

        // Create Ready Q and added_job variable
        int aj = 0, timeStamp = 0, added_bt = 0;
        vector<string> gantt;
        queue<Jobs> ReadyQ;
        Jobs added_job;
        added_job.bt = 0;

        while (timeStamp < totalTime)
        {

            // add all process to the ready queue
            while (aj < np && v[aj].at <= timeStamp)
            {
                ReadyQ.push(v[aj]);
                aj++;
            }

            // if the previously added process is not completed yet then add it to the
            // queue
            if (added_job.bt > 0)
            {
                ReadyQ.push(added_job);
            }

            if (ReadyQ.size() > 0)
            {
                added_job = ReadyQ.front();
                ReadyQ.pop();
                gantt.push_back(added_job.name);

                if (added_job.bt > interval)
                {
                    added_job.bt = added_job.bt - interval;
                    added_bt = interval;
                }
                else
                {
                    added_bt = added_job.bt;
                    added_job.bt = 0;
                }

                if (added_job.bt == 0)
                {
                    for (int i = 0; i < np; i++)
                    {
                        if (jobs[i].name == added_job.name)
                        {
                            jobs[i].ct = timeStamp + added_bt;
                            jobs[i].tat = jobs[i].ct - jobs[i].at;
                            jobs[i].wt = jobs[i].tat - jobs[i].bt;
                        }
                    }
                }
            }

            timeStamp += added_bt;
        }

        float avg_wt = 0, avg_tat = 0;

        for (int i = 0; i < np; i++)
        {
            avg_tat += jobs[i].tat;
            avg_wt += jobs[i].wt;
        }

        avg_wt = avg_wt / np;
        avg_tat = avg_tat / np;

        showjobs(jobs, np);
        show_average(avg_tat, avg_wt);
    }

    void priority()
    {
        Jobs *v = new Jobs[np];
        int totalTime = 0;

        for (int i = 0; i < np; i++)
        {
            v[i] = jobs[i];
            cout << "Enter the priority of the process" << v[i].name << ": ";
            totalTime += v[i].bt;
            cin >> v[i].pri;
        }

        // sort the process acc to arrival time
        sort(v, v + np,
             [](const Jobs &lhs, const Jobs &rhs)
             { return lhs.at <= rhs.at; });

        // make a ready queue
        vector<Jobs> ReadyQ;
        int timestamp = 0;
        int aj = 0; // for current job
        int ja = 0; // for the gannt chart

        Jobs *gannt = new Jobs[np];

        while (timestamp < totalTime)
        {

            // get all process into ready queue
            while (aj < np && v[aj].at <= timestamp)
            {
                ReadyQ.push_back(v[aj]);
                aj++;
            }

            // sort the process according to the priority
            sort(ReadyQ.begin(), ReadyQ.end(),
                 [](const Jobs &lhs, const Jobs &rhs)
                 { return lhs.pri < rhs.pri; });

            // gannt chart
            if (ReadyQ.size() > 0)
            {
                gannt[ja] = ReadyQ[0];
                timestamp += gannt[ja].bt;
                gannt[ja].ct = timestamp;
                gannt[ja].tat = gannt[ja].ct - gannt[ja].at;
                gannt[ja].wt = gannt[ja].tat - gannt[ja].bt;
                ja++;
                ReadyQ.erase(ReadyQ.begin());
            }
        }

        float avg_wt = 0, avg_tat = 0;

        for (int i = 0; i < np; i++)
        {
            avg_tat += gannt[i].tat;
            avg_wt += gannt[i].wt;
        }

        avg_wt = avg_wt / np;
        avg_tat = avg_tat / np;

        showjobs(gannt, np);
        show_average(avg_tat, avg_wt);
    }

    void SJF()
    {
        Jobs *v = new Jobs[np];
        int totalTime = 0;
        for (int i = 0; i < np; i++)
        {
            v[i] = jobs[i];
            totalTime += v[i].bt;
        }

        // sort acc to arrival time
        sort(v, v + np,
             [](const Jobs &lhs, const Jobs &rhs)
             { return lhs.at < rhs.at; });

        vector<string> gantt;
        int aj = 0;
        int timeStamp = 0;
        vector<Jobs> ReadyQ;

        while (timeStamp < totalTime)
        {
            // get all the processes into the ready q
            while (aj < np && v[aj].at <= timeStamp)
            {
                ReadyQ.push_back(v[aj]);
                aj++;
            }

            sort(ReadyQ.begin(), ReadyQ.end(),
                 [](const Jobs &lhs, const Jobs &rhs)
                 { return lhs.bt < rhs.bt; });

            if (ReadyQ.size() > 0)
            {
                gantt.push_back(ReadyQ[0].name);
                ReadyQ[0].bt--;

                if (ReadyQ[0].bt == 0)
                {
                    for (int i = 0; i < np; i++)
                    {
                        if (jobs[i].name == ReadyQ[0].name)
                        {
                            jobs[i].ct = timeStamp + 1;
                            jobs[i].tat = jobs[i].ct - jobs[i].at;
                            jobs[i].wt = jobs[i].tat - jobs[i].bt;
                        }
                    }
                    ReadyQ.erase(ReadyQ.begin());
                }
            }

            timeStamp++;
        }

        float avg_wt = 0, avg_tat = 0;

        for (int i = 0; i < np; i++)
        {
            avg_tat += jobs[i].tat;
            avg_wt += jobs[i].wt;
        }

        avg_wt = avg_wt / np;
        avg_tat = avg_tat / np;

        showjobs(jobs, np);
        show_average(avg_tat, avg_wt);
    }
};

int main()
{
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    Scheduler s;
    // s.fcfs();
    //  s.priority();
    s.RoundRobin();
    // s.SJF();
    return 0;
}