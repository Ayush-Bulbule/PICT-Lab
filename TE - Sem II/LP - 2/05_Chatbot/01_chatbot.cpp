#include <iostream>
#include <string>
#include <map>

using namespace std;

// Function to get response from the chatbot
string getResponse(const string& userQuery) {
    // Define responses specific to web development services
    map<string, string> responses = {
        {"hi", "Hello! How can I assist you with your web development needs today?"},
        {"how are you", "I'm a chatbot here to assist you with your web development questions. How can I help you?"},
        {"bye", "Goodbye! Feel free to reach out for more web development assistance."},
        {"website", "We offer custom website development services starting at $500."},
        {"ecommerce", "Our e-commerce solutions start at $1000, ideal for growing your online business."},
        {"maintenance", "We provide website maintenance services to keep your site updated and secure."},
        {"duration", "A typical website project takes about 4-6 weeks, depending on your specific requirements."},
        {"support", "We offer ongoing support packages to help you with any issues after your website goes live."},
        {"technologies", "We specialize in HTML, CSS, JavaScript, and WordPress. Let us know what you need!"}
    };

    // Simple case-insensitive matching for responses
    string query = userQuery;
    // Transform userQuery to lowercase for matching
    transform(query.begin(), query.end(), query.begin(), ::tolower);

    // Check if user query exists in responses
    auto it = responses.find(query);
    if (it != responses.end()) {
        return it->second;
    } else {
        // Generic response for unmatched queries
        return "I'm not sure how to answer that. Can you please specify your query regarding web development?";
    }
}

int main() {
    cout << "Welcome to Our Web Development Services Chatbot" << endl;
    cout << "Please type your questions about our services. Type 'bye' to exit." << endl;

    string userQuery;
    while (true) {
        cout << "User: ";
        getline(cin, userQuery);

        if (userQuery == "bye") {
            cout << "Chatbot: Goodbye! We hope to assist you again soon." << endl;
            break;
        }

        string response = getResponse(userQuery);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}
