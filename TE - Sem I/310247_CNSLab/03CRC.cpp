#include <iostream>
using namespace std;

int main()
{
    int i, j, k, l;

    // Get Frame
    int fs;
    cout << "\n Enter Frame size: ";
    cin >> fs;

    int f[20];

    cout << "\n Enter Frame:";
    for (i = 0; i < fs; i++)
    {
        cin >> f[i];
    }

    // Get Generator
    int gs;
    cout << "\n Enter Generator size: ";
    cin >> gs;

    int g[20];

    cout << "\n Enter Generator:";
    for (i = 0; i < gs; i++)
    {
        cin >> g[i];
    }

    cout << "\n Sender Side:";
    cout << "\n Frame: ";
    for (i = 0; i < fs; i++)
    {
        cout << f[i];
    }
    cout << "\n Generator :";
    for (i = 0; i < gs; i++)
    {
        cout << g[i];
    }

    // Append 0's
    int rs = gs - 1;
    cout << "\n Number of 0's to be appended: " << rs;
    for (i = fs; i < fs + rs; i++)
    {
        f[i] = 0;
    }

    int temp[20];
    for (i = 0; i < 20; i++)
    {
        temp[i] = f[i];
    }

    cout << "\n Message after appending 0's :";
    for (i = 0; i < fs + rs; i++)
    {
        cout << temp[i];
    }

    // Division
    for (i = 0; i < fs; i++)
    {
        j = 0;
        k = i;
        // check whether it is divisible or not
        if (temp[k] >= g[j])
        {
            for (j = 0, k = i; j < gs; j++, k++)
            {
                if ((temp[k] == 1 && g[j] == 1) || (temp[k] == 0 && g[j] == 0))
                {
                    temp[k] = 0;
                }
                else
                {
                    temp[k] = 1;
                }
            }
        }
    }
