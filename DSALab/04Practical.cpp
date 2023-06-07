//============================================================================
// Name        : PracticalNo04.cpp
// Author      : Ayush Bulbule
// Version     :
// Copyright   : Your copyright notice
// Description : Consider telephone book database of N clients. Make use of a hash
//				 table implementation to quickly look up client’s telephone number.
//				 Make use of two collision handling techniques and compare them using
//				 number of comparisons required to find a set of telephone numbers
//				(Note: Use linear probing with replacement and without replacement)

//============================================================================

#include <iostream>
using namespace std;
#define size 10

// Create an contact
class Contact
{
    string name;
    string number;

public:
    Contact()
    {
        name = "";
        number = "";
    }
    Contact(string name, string number)
    {
        this->name = name;
        this->number = number;
    }
    friend class HashMap;
};

class HashMap
{
    Contact *clients;

public:
    HashMap()
    {
        clients = new Contact[size];
        for (int i = 0; i < size; i++)
        {
            clients[i] = Contact();
        }
    }

    //	function to hash the key
    int getHash(string key)
    {
        int hash = 0;

        for (char ch : key)
        {
            hash += (int)ch;
        }

        cout << key << " : " << hash;
        return hash % size;
    }

    // function to insert the data in array;
    void insert_without_replacement(string name, string number)
    {
        // get hash
        int hash = getHash(name);

        // set the data for that slot
        while (clients[hash].name != "" && clients[hash].name != name)
        {
            // do linear probing
            hash = (hash + 1) % size;
        }
        // Now plce the data
        clients[hash].name = name;
        clients[hash].number = number;
        cout << "Inserted!" << endl;
    }

    // With replacements
    void insert_replacement(string name, string number)
    {
        // calculate the hash
        int hash = getHash(name);
        cout << "N : " << name << endl;

        while (clients[hash].name != "" && clients[hash].name != name)
        {
            int prev = getHash(clients[hash].name);

            cout << "hash: " << hash;
            if (prev != hash)
            {
                // swap the values
                string pname = clients[hash].name;
                string pnumber = clients[hash].number;

                // rplace
                clients[hash].name = name;
                clients[hash].number = number;

                name = pname;
                number = pnumber;
            }
            // linearly probe
            hash = (hash + 1) % size;
        }

        clients[hash].name = name;
        clients[hash].number = number;
    }

    // search key
    void search(string name)
    {
        int count = 0;

        int hash = getHash(name);

        for (int i = 0; i < size; i++)
        {
            count++;
            if (clients[hash].name == name)
            {
                cout << "Contact Found! Required Comparisions - " << count << endl;
                cout << "Name: " << clients[hash].name << endl;
                cout << "Number: " << clients[hash].number << endl;
                return;
            }
            hash = (hash + 1) % size;
        }
        cout << "Data Not Found!!" << endl;
    }

    // remove
    void remove(string name)
    {
        int hash = getHash(name);
        for (int i = 0; i < size; i++)
        {
            if (clients[hash].name == name)
            {
                clients[hash].name = "";
                clients[hash].number = "";
                return;
            }
            hash = (hash + 1) % size;
        }
        cout << "Data Not Found!!" << endl;
    }

    // print
    void print()
    {
        cout << "Index \t Value" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << " : " << clients[i].name << " - " << clients[i].number << endl;
        }
    }
};

int main()
{
    cout << "Hashing (Table Size: " << size << ")" << endl; // prints Hashing

    HashMap *hmp = new HashMap();

    bool flag = true;

    while (flag)
    {

        cout << "1. Insert Data without replacement" << endl;
        cout << "2. Insert With Replacement" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Display all contacts" << endl;
        cout << "5. Remove all contacts" << endl;
        cout << "6. Exit..." << endl;

        string name, number = "";

        int ch;
        cout << "Enter Yor choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "\nInsert without Replacement " << endl;
            cout << "\nEnter name: ";
            cin >> name;
            cout << "\nEnter number: ";
            cin >> number;
            hmp->insert_without_replacement(name, number);
            break;
        }
        case 2:
        {
            cout << "\nInsert with Replacement " << endl;
            cout << "\nEnter name: ";
            cin >> name;
            cout << "\nEnter number: ";
            cin >> number;
            hmp->insert_replacement(name, number);
            break;
        }
        case 3:
        {
            cout << "\nSearch for a contact " << endl;
            cout << "\nEnter name to search: ";
            cin >> name;
            hmp->search(name);
            break;
        }
        case 4:
        {
            cout << "\n Delete for a contact " << endl;
            cout << "\nEnter name to delete: ";
            cin >> name;
            hmp->remove(name);
            break;
        }
        case 5:
        {
            cout << "\t\t## Contacts ##" << endl;
            hmp->print();
            break;
        }
        case 6:
        {
            cout << "Exiting...." << endl;
            flag = false;
            break;
        }
        default:
        {
            cout << "Wrong Input!!!" << endl;
            break;
        }
        }
    }

    return 0;
}
