/**
 * Problem Statement: Develop an elementary chat bot for any suitable customer interaction application.
 *
 * Application: Chatbot for a restaurant (with context)
 */

#include <bits/stdc++.h>

using namespace std;

class Chatbot
{
public:
    void start()
    {
        cout << "Welcome to the restaurant chatbot!" << endl;
        cout << "How may I help you today?" << endl;
        cout << "Type 'exit' to end the conversation." << endl;
        cout << "--------------------------------------" << endl;

        while (true)
        {
            string user_input;
            cout << "User: ";
            getline(cin, user_input);

            if (user_input == "exit")
            {
                cout << "Chatbot: Thank you for visiting us! Have a great day!" << endl;
                break;
            }

            string response = generate_response(user_input);
            cout << "Chatbot: " << response << endl;
        }
    }

private:
    string generate_response(string user_input)
    {
        if (user_input.find("menu") != string::npos)
        {
            return "We have a variety of dishes available. What would you like to order?";
        }
        else if (user_input.find("order") != string::npos)
        {
            return "Sure! What would you like to order?";
        }
        else if (user_input.find("special") != string::npos)
        {
            return "Our special dish today is the 'Chef's Special Pasta'. Would you like to try it?";
        }
        else if (user_input.find("reservation") != string::npos)
        {
            return "Sure! How many people will be joining you?";
        }
        else if (user_input.find("thank you") != string::npos)
        {
            return "You're welcome! Have a great day!";
        }
        else
        {
            return "I'm sorry, I didn't understand that. Could you please rephrase?";
        }
    }
};

int main()
{
    Chatbot chatbot;
    chatbot.start();

    return 0;
}