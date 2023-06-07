//===========================================================================
// Name        : PracticalNo05.cpp
// Author      : Ayush Bulbule
// Version     :
// Copyright   : Your copyright notice
// Description : The Dictionary ADT implementation using open hashing
//				 technique
//============================================================================

#include <iostream>
using namespace std;
#define size 10

class Node
{
    string word;
    string meaning;
    Node *next;

public:
    Node()
    {
        word = "";
        meaning = "";
        next = NULL;
    }

    Node(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;
        next = NULL;
    }
    friend class HashMap;
};

class HashMap
{

    Node *dict[size];

public:
    HashMap()
    {

        for (int i = 0; i < size; i++)
        {
            dict[i] = NULL;
        }
    }

    // Functions
    int getHash(string word)
    {
        int hash = 0;
        for (char ch : word)
        {
            hash += (int)ch;
        }
        return hash % size;
    }

    // Insert to HashTable
    void insert(string word, string meaning)
    {
        Node *new_node = new Node(word, meaning);

        int hash = getHash(word);
        // check if word exists there
        cout << hash << endl;
        if (dict[hash] == NULL)
        {
            dict[hash] = new_node;
            cout << dict[hash]->word << endl;
        }
        else
        {
            Node *temp = dict[hash];
            while (temp->next)
            {
                temp = temp->next;
                cout << temp->word << endl;
                cout << "Hii" << endl;
            }
            cout << "out" << endl;
            temp->next = new_node;
        }
    }

    // printing the hash table:
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            Node *temp = dict[i];
            cout << i << " -> ";
            while (temp)
            {
                cout << temp->word << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Search Word
    void search(string word)
    {

        int hash = getHash(word);

        for (int i = 0; i < size; i++)
        {
            Node *temp = dict[hash];
            if (temp->word == word)
            {
                cout << "Data found: " << endl;
                cout << temp->word << " - " << temp->meaning << endl;
                return;
            }
            else
            {
                while (temp)
                {
                    if (temp->word == word)
                    {
                        cout << temp->word << " - " << temp->meaning << endl;
                        return;
                    }
                    temp = temp->next;
                }
            }

            hash = hash + 1 % size;
        }
    }

    // Update Word:

    void update(string word)
    {
        int hash = getHash(word);
        string new_meaning;
        Node *temp = dict[hash];

        if (dict[hash]->word == word)
        {
            cout << "Enter new meaning: ";
            cin >> new_meaning;
            dict[hash]->meaning = new_meaning;
        }
        else
        {
            while (temp)
            {
                if (temp->word == word)
                {
                    cout << "Enter new meaning: ";
                    cin >> new_meaning;
                    dict[hash]->meaning = new_meaning;
                }
                temp = temp->next;
            }
        }
        hash = hash + 1 % size;
    }
};

int main()
{
    cout << "Seperate Hashing" << endl; // prints Hashing
    bool flag = true;

    string word, meaning = "";

    HashMap *hmp = new HashMap();

    while (flag)
    {
        int ch;
        cout
            << "\n1. Add Word\n2.Print Dictionary\n3.Search Word\n4.Update Word\n5.Delete Word"
            << endl;
        cout << "\nEnter Your Choice: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter Word: ";
            cin >> word;
            cout << "Enter Meaning: ";
            cin >> meaning;

            hmp->insert(word, meaning);
            break;
        case 2:
            cout << "Dictionary " << endl;
            hmp->print();
            break;
        case 3:
            cout << "Search " << endl;
            cout << "Enter a word to search: ";
            cin >> word;
            hmp->search(word);
            break;
        case 4:
            cout << "Update" << endl;
            cout << "Enter a word to update: ";
            cin >> word;
            hmp->update(word);
            break;
        case 5:
            cout << "Delete" << endl;
            // yet to impliment
            break;
        case 6:
            cout << "Exit..." << endl;
            flag = false;
            break;
        }
    }

    return 0;
}
