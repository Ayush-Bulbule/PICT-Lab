/**
 * Name: Ayush Shashikant Bulbule
 * Practical No : 4
 * Title : Write a program to simulate the following page replacement algorithms
 *         a) FIFO
 *         b) Optimal
 *         c) LRU
 * Test cases:
 * 1. Enter length of page reference sequence: 13
 *   Enter the page reference sequence: 7 0 1 2 0 3 0 4 2 3 0 3 2
 *  Enter no of frames: 4
 * **/

#include <iostream>
#include <vector>

using namespace std;

class PageReplacementAlgorithm
{
private:
    int n;          // Length of page reference sequence
    int nf;         // Number of frames
    vector<int> in; // Input reference sequence
    vector<int> p;  // frames
    int pgfaultcnt = 0;

    void initilize()
    {
        pgfaultcnt = 0;
        p.assign(nf, 9999);
    }
    // Method to find if hit(if data is there in page frames)
    bool isHit(int data)
    {
        for (int j = 0; j < nf; j++)
        {
            if (p[j] == data)
                return true;
        }
        return false;
    }
    // Method to display the page frames
    void dispPages()
    {
        for (int k = 0; k < nf; k++)
        {
            if (p[k] != 9999)
                cout << " " << p[k];
        }
    }

    void displayPgFaultCnt()
    {
        cout << "Total no of faults: " << pgfaultcnt << endl;
    }

public:
    void getData()
    {
        cout << "Enter length of page reference sequence: ";
        cin >> n;
        cout << "Enter the page reference sequence: ";
        in.resize(n); // resize the vector to n

        for (int i = 0; i < n; i++)
        {
            cin >> in[i];
        }

        cout << "Enter no of frames: ";
        cin >> nf;
        p.resize(nf);

        cout << endl;
    }
    // Impliment FIFO page replacement algorithm
    void fifo()
    {
        initilize();
        for (int i = 0; i < n; i++)
        {
            cout << "For " << in[i] << " : ";
            if (!isHit(in[i]))
            { // As it is a fault
                for (int k = 0; k < nf - 1; k++)
                    p[k] = p[k + 1];

                p[nf - 1] = in[i];
                pgfaultcnt++;
                dispPages();
            }
            else
                cout << "H I T";
            cout << endl;
        }
        displayPgFaultCnt();
        cout << endl;
    }

    // Optimal Page Replacement Algorithm
    void optimal()
    {
        initilize();
        vector<int> near(nf, 0); // To store the index of occurance of the page in future
        // Traverse all the page reference sequence
        for (int i = 0; i < n; i++)
        {
            cout << "For " << in[i] << " : ";
            if (!isHit(in[i]))
            {
                for (int j = 0; j < nf; j++)
                {
                    int pg = p[j];
                    bool found = false;
                    // Traverse the reference sequence to find the occurance of the page
                    for (int k = i; k < n; k++)
                    {
                        if (pg == in[k])
                        {
                            near[j] = k;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        near[j] = 9999;
                }
                // Find the page with maximum index of occurance
                int max = -9999;
                int repIndex; // replacement index in frame

                for (int j = 0; j < nf; j++)
                {
                    if (near[j] > max)
                    {
                        max = near[j];
                        repIndex = j;
                    }
                }
                p[repIndex] = in[i];
                pgfaultcnt++;
                dispPages();
            }
            else
                cout << "H I T";

            cout << endl;
        }
        displayPgFaultCnt();
    }

    // Least Recently Used Page Replacement Algorithm
    void lru()
    {
        initilize();
        vector<int> least(nf, 0);
        // Traverse all the page reference sequence
        for (int i = 0; i < n; i++)
        {
            cout << "For " << in[i] << " : ";
            if (!isHit(in[i]))
            {
                for (int j = 0; j < nf; j++)
                {
                    int pg = p[j];
                    bool found = false;

                    for (int k = i - 1; k >= 0; k--)
                    {
                        if (pg == in[k])
                        {
                            least[j] = k;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        least[j] = -9999;
                }
                int min = 9999;
                int repIndex; // Index which needs to replaced

                for (int j = 0; j < nf; j++)
                {
                    if (least[j] < min)
                    {
                        min = least[j];
                        repIndex = j;
                    }
                }
                p[repIndex] = in[i];
                pgfaultcnt++;
                dispPages();
            }
            else
                cout << "H I T";
            cout << endl;
        }

        displayPgFaultCnt();
        cout << endl;
    }
};

int main()
{
    PageReplacementAlgorithm prAlgo;
    bool loop = true;
    int choice;

    while (loop)
    {
        cout << "###### PAGE REPLACEMET ALGORITHM ######" << endl;
        cout << "1. Enter Data" << endl;
        cout << "2. FIFO" << endl;
        cout << "3. Optimal" << endl;
        cout << "4. LRU" << endl;
        cout << "5. Exit" << endl;

        cout << "\n Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            prAlgo.getData();
            break;
        case 2:
            prAlgo.fifo();
            break;
        case 3:
            prAlgo.optimal();
            break;
        case 4:
            prAlgo.lru();
            break;
        case 5:
            cout << "Exiting..." << endl;
            cout << "Thank you!!" << endl;
            loop = false;
        default:
            return 0;
            break;
        }
    }
}