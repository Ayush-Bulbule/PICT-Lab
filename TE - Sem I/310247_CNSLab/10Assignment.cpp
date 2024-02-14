#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>

using namespace std;

// Function to perform DNS lookup for IP address to URL
void ipToUrlLookup(const char *ipAddress)
{
    struct hostent *hostInfo;
    struct in_addr ipv4Addr;

    // Convert IP address from string to binary form
    inet_pton(AF_INET, ipAddress, &ipv4Addr);

    // Perform DNS lookup
    hostInfo = gethostbyaddr(&ipv4Addr, sizeof(ipv4Addr), AF_INET);

    if (hostInfo == nullptr)
    {
        cerr << "DNS lookup failed\n";
    }
    else
    {
        cout << "IP Address: " << ipAddress << "\n";
        cout << "Hostname: " << hostInfo->h_name << "\n";
    }
}

// Function to perform DNS lookup for URL to IP address
void urlToIpLookup(const char *url)
{
    struct hostent *hostInfo;

    // Perform DNS lookup
    hostInfo = gethostbyname(url);

    if (hostInfo == nullptr)
    {
        cerr << "DNS lookup failed\n";
    }
    else
    {
        cout << "URL: " << url << "\n";
        cout << "IP Address: " << inet_ntoa(*(struct in_addr *)hostInfo->h_addr_list[0]) << "\n";
    }
}

int main()
{
    int choice;
    char input[256];

    cout << "DNS Lookup Program\n";
    cout << "1. IP to URL Lookup\n";
    cout << "2. URL to IP Lookup\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter the IP address: ";
        cin >> input;
        ipToUrlLookup(input);
        break;
    case 2:
        cout << "Enter the URL: ";
        cin >> input;
        urlToIpLookup(input);
        break;
    default:
        cerr << "Invalid choice\n";
        break;
    }

    return 0;
}
