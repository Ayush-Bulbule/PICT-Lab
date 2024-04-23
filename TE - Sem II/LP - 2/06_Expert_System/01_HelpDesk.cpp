#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Ticket {
public:
    string issue;
    string status;
    string solution;

    Ticket(string iss, string sol = "") : issue(iss), status("Open"), solution(sol) {}
};

vector<Ticket> tickets;
map<string, string> knowledgeBase = {
    {"internet down", "Check if the router is plugged in and restart it."},
    {"cannot print", "Ensure the printer is connected and has enough paper."},
    {"slow computer", "Restart your computer and close unnecessary applications."}
};

vector<string> faqs = {
    "How to reset my password?",
    "How do I set up my email?",
    "What to do if I can't access the company portal?"
};

void createTicket() {
    string issue;
    cout << "Enter the issue: ";
    cin.ignore();
    getline(cin, issue);

    if (knowledgeBase.find(issue) != knowledgeBase.end()) {
        cout << "Solution based on common issues: " << knowledgeBase[issue] << endl;
        tickets.push_back(Ticket(issue, knowledgeBase[issue]));
        cout << "Ticket created with a suggested solution.\n";
    } else {
        tickets.push_back(Ticket(issue));
        cout << "Ticket created. Our team will get back to you with a solution.\n";
    }
}

void viewTickets() {
    if (tickets.empty()) {
        cout << "No tickets found.\n";
        return;
    }
    for (int i = 0; i < tickets.size(); i++) {
        cout << "Ticket " << i + 1 << ": Issue - " << tickets[i].issue << ", Status - " << tickets[i].status;
        if (!tickets[i].solution.empty()) {
            cout << ", Suggested Solution - " << tickets[i].solution;
        }
        cout << endl;
    }
}

void displayFAQs() {
    cout << "Frequently Asked Questions:\n";
    for (const string& faq : faqs) {
        cout << "- " << faq << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "1. Create Ticket\n";
        cout << "2. View Tickets\n";
        cout << "3. View FAQs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createTicket();
                break;
            case 2:
                viewTickets();
                break;
            case 3:
                displayFAQs();
                break;
            case 4:
                cout << "Exiting the system.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
