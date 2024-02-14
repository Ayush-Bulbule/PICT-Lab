/**
 * Assignment No 05: Write a program to demonstrate subletting and find the subnet masks.
 */

#include <iostream>
#include <vector>

using namespace std;

// Function to calculate subnet masks based on the number of subnets
vector<string> calculateSubnetMasks(int numSubnets)
{
    vector<string> subnetMasks;

    for (int i = 0; i < numSubnets; ++i)
    {
        int subnetMask = 32 - i;
        string mask = "";

        // Create the subnet mask
        for (int j = 0; j < subnetMask; ++j)
        {
            if (j % 8 == 0 && j != 0)
            {
                mask += '.';
            }
            mask += '1';
        }
        // Fill in remaining bits with 0
        while (mask.size() < 32)
        {
            mask += '0';
        }

        subnetMasks.push_back(mask);
    }

    return subnetMasks;
}

int main()
{
    int numSubnets;

    cout << "Enter the number of subnets: ";
    cin >> numSubnets;

    if (numSubnets <= 0 || numSubnets > 32)
    {
        cout << "Invalid number of subnets. Please enter a number between 1 and 32.\n";
        return 1;
    }

    vector<string> subnetMasks = calculateSubnetMasks(numSubnets);

    cout << "Subnet Masks for " << numSubnets << " subnets:\n";
    for (int i = 0; i < numSubnets; ++i)
    {
        cout << "Subnet " << i + 1 << ": " << subnetMasks[i] << endl;
    }

    return 0;
}
