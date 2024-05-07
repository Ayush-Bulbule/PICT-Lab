/**
 * SUbject: Artificial Intelligence
 * Problem Statement: Implement any one of the following Expert System which will give expert opinion:
 * - Information management
 * - Hospitals and medical facilities
 * - Help desk management
 * - Employee performance evaluation
 * - Stock market trading
 * - Airline scheduling and cargo schedules
 *
 * Selected Problem Statement: Employee performance evaluation
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Employee
{
public:
    string name;
    int performance;
    string feedback;

    Employee(string n, int p = 0, string f = "") : name(n), performance(p), feedback(f) {}
};

vector<Employee> employees;
map<string, string> knowledgeBase = {
    {"poor", "Provide training and mentorship."},
    {"average", "Set clear goals and expectations."},
    {"good", "Recognize and reward achievements."},
    {"excellent", "Promote and provide growth opportunities."}};

void evaluatePerformance()
{
    string name;
    cout << "Enter the employee's name: ";
    cin.ignore();
    getline(cin, name);

    int performance;
    cout << "Enter the employee's performance (1 - Poor, 2 - Average, 3 - Good, 4 - Excellent): ";
    cin >> performance;

    if (performance < 1 || performance > 4)
    {
        cout << "Invalid performance level.\n";
        return;
    }

    string feedback;
    cout << "Enter any additional feedback: ";
    cin.ignore();
    getline(cin, feedback);

    employees.push_back(Employee(name, performance, feedback));
    cout << "Performance evaluation completed.\n";
}

void displayFeedback()
{
    if (employees.empty())
    {
        cout << "No performance evaluations available.\n";
        return;
    }

    cout << "Employee Performance Feedback:\n";
    for (Employee e : employees)
    {
        cout << "Name: " << e.name << "\n";
        cout << "Performance: ";
        switch (e.performance)
        {
        case 1:
            cout << "Poor\n";
            break;
        case 2:
            cout << "Average\n";
            break;
        case 3:
            cout << "Good\n";
            break;
        case 4:
            cout << "Excellent\n";
            break;
        }
        cout << "Feedback: " << e.feedback << "\n";
        cout << "Suggested Action: " << knowledgeBase[(e.performance == 1) ? "poor" : (e.performance == 2) ? "average"
                                                                                  : (e.performance == 3)   ? "good"
                                                                                                           : "excellent"]
             << "\n\n";
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "Employee Performance Evaluation System\n";
        cout << "1. Evaluate Performance\n";
        cout << "2. Display Feedback\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            evaluatePerformance();
            break;
        case 2:
            displayFeedback();
            break;
        case 3:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
