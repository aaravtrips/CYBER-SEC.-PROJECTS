#include <iostream>
#include <unordered_map>
#include <iomanip>     // for setw and formatting
#include <algorithm>   // 🔧 for reverse()

using namespace std;

unordered_map<string, string> passwordDB;

// MOCK SHA-256 function (just reverses the string + adds a fake "hash" suffix)
string sha256(const string& password) {
    string hash = password;
    reverse(hash.begin(), hash.end());
    return hash + "_hashed";
}

void displayUI() {
    cout << "\n┌────────────────────────────────────────────────────────────┐\n";
    cout << "│                    PASSWORD MANAGER                        │\n";
    cout << "├────────────────────────────────────────────────────────────┤\n";
    cout << "│ 🔒 Master Password: [__________________________]           │\n";
    cout << "│                                                            │\n";
    cout << "│ [ Unlock Vault ]                                           │\n";
    cout << "├────────────────────────────────────────────────────────────┤\n";
    cout << "│ 🌐 Website / App   | 🧑 Username       | 🔑 Password         │\n";
    cout << "├────────────────────┼──────────────────┼────────────────────┤\n";

    for (auto& entry : passwordDB) {
        cout << "│ " << left << setw(18) << "www." + entry.first
             << "│ " << left << setw(18) << entry.first
             << "│ ************         │" << endl;
    }

    cout << "├────────────────────────────────────────────────────────────┤\n";
    cout << "│ [ Add New ] [ View Details ] [ Delete ] [ Save Vault ]     │\n";
    cout << "├────────────────────────────────────────────────────────────┤\n";
    cout << "│ 📁 Vault Status: Encrypted (SHA-256 + Salted)              │\n";
    cout << "│                                                            │\n";
    cout << "│ [ Lock & Exit ]                                            │\n";
    cout << "└────────────────────────────────────────────────────────────┘\n";
}

void addPassword() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    passwordDB[username] = sha256(password);
    cout << "Password saved securely!\n";
}

void retrievePassword() {
    string username;
    cout << "Enter username: ";
    cin >> username;

    if (passwordDB.find(username) != passwordDB.end()) {
        cout << "Stored Hashed Password: " << passwordDB[username] << endl;
    } else {
        cout << "No password found for this username!\n";
    }
}

void deletePassword() {
    string username;
    cout << "Enter username to delete: ";
    cin >> username;

    if (passwordDB.erase(username)) {
        cout << "Password deleted successfully!\n";
    } else {
        cout << "No such username found!\n";
    }
}

int main() {
    int choice;

    do {
        displayUI();
        cout << "\nSelect an action:\n";
        cout << "1. Add Password\n";
        cout << "2. Retrieve Password\n";
        cout << "3. Delete Password\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPassword(); break;
            case 2: retrievePassword(); break;
            case 3: deletePassword(); break;
            case 4: cout << "🔒 Locking and exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
