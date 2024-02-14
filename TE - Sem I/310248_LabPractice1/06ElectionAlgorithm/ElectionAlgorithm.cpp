#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

class Candidate
{
public:
    int id;
    bool act;
    Candidate()
    {
        id = 0;
        act = true;
    }
    void addCandidate()
    {
        cout << "Enter the ID of new Candidate: " << endl;
        cin >> id;
    }
};
class Election
{
public:
    vector<Candidate> v;
    int currindex;

    void getCandidate()
    {
        Candidate c;
        c.addCandidate();
        v.push_back(c);
    }
    void addFaliure()
    {
        int max = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].id > max && v[i].act)
            {
                max = v[i].id;
                currindex = i;
            }
        }
        cout << "Current Cordirnator is " << v[currindex].id << endl;
        sleep(3);
        cout << "Current Coordinator Failed" << endl;
        cout << "Detected by: " << v[(currindex - 1)].id << endl;
        v[currindex].act = false;
        sleep(3);
        cout << "Election Initilized" << endl;
    }

    // Ring Algorithm
    void RingElection()
    {
        int old = currindex;
        int new1 = (old - 1);
        int cnt = 0;

        while (new1 != old)
        {
            // calculate the next node
            int next = (new1 + 1) % v.size();
            // case1: if the next node is the coordinator
            if (new1 == old - 1 && cnt == 0)
            {
                next = (new1 + 2) % v.size();
                sleep(2);
                cout << "Message passed from " << v[new1].id << " to " << v[next].id << endl;
                new1 = next;
                cnt++;
                continue;
            }
            // case 2: if the next node is the failed node
            if (v[next].act)
            {
                sleep(2);
                cout << "Message passed from " << v[new1].id << " to " << v[next].id << endl;
            }
            new1 = next;
        }

        // make new coordinator find active max
        int max = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].id > max && v[i].act)
            {
                max = v[i].id;
                currindex = i;
            }
        }
        cout << "New Coordinator is " << v[currindex].id << endl;
    }

    // Bully Algorithm
    void bullyFail()
    {
        int max = 0;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].id > max && v[i].act)
            {
                max = v[i].id;
                currindex = i;
            }
        }
        cout << "Current Coordinator is " << v[currindex].id << endl;
        sleep(1);
        cout << "Current Cordinaor Failed" << endl;
    }

    // Bully Election
    void bullyElection()
    {
        int old = currindex;

        int a = rand() % (v.size() - 1); // find random nexxt

        int new1 = currindex - a;
        cout << "Detetcted by " << v[new1].id << endl;
        v[currindex].act = false;

        sleep(2);

        cout << "Election Initilized" << endl;

        while (true)
        {
            // Send msg to all the nodes
            for (int i = new1; i < v.size() - 1; i++)
            {
                if (v[i].act)
                {
                    cout << "Message passed from " << v[new1].id << " to " << v[i + 1].id << endl;
                }
                sleep(1);
            }
            // check if the node is active
            for (int i = v.size() - 1; i > new1; i--)
            {
                if (v[i].act)
                {
                    cout << "OK message from " << v[i].id << " to " << v[new1].id << endl;
                }
                sleep(1);
            }

            if (new1 < v.size() - 1 && v[new1].act)
            {
                new1 = new1 + 1;
            }
            else
            {
                break;
            }
        }
        cout << "Next Election Coordinator is : " << v[new1 - 1].id << endl;
    }
};

int main()
{
    bool loop = true;
    while (loop)
    {
        Election e;

        int n;
        cout << "Enter the number of nodes: " << endl;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            e.getCandidate();
        }

        // Prompt
        cout << "ALGORITHM FOR ELECTION ALGORITHM" << endl;
        cout << "1. Ring Algorithm\n2. Bully Algorithm\n3. Exit" << endl;
        int ch;
        cin >> ch;

        switch (ch)
        {
        case 1:
            e.addFaliure();
            e.RingElection();
            break;
        case 2:
            e.bullyFail();
            e.bullyElection();
            break;
        case 3:
            loop = false;
            break;
        default:
            cout << "Error" << endl;
            break;
        }
    }
    return 0;
}