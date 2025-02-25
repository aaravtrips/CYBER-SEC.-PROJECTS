#include <iostream>
#include <fstream>
#include <unordered_map>
#include <openssl/sha.h>  // Requires OpenSSL for SHA-256 hashing

using namespace std;

unordered_map<string, string> passwordDB;  // Stores username-password pairs

// Function to hash passwords using SHA-256
string sha256(const string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)password.c_str(), password.length(), hash);
    
    string hashedPassword;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        char buffer[3];
        sprintf(buffer, "%02x", hash[i]);
        hashedPassword += buffer;
    }
    return hashedPassword;
}

// Function to save passwords to a file
void savePasswords() {
    ofstream file("passwords.txt");
    for (auto& entry : passwordDB) {
        file << entry.first << " " << entry.second << endl;
    }
    file.close();
}

// Function to load passwords from a file
void loadPasswords() {
    ifstream file("passwords.txt");
    string username, password;
    while (file >> username >> password) {
        passwordDB[username] = password;
    }
    file.close();
}

// Function to add a new password
void addPassword() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    passwordDB[username] = sha256(password);  // Store hashed password
    savePasswords();
    cout << "Password saved securely!\n";
}

// Function to retrieve a password
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

// Function to delete a password
void deletePassword() {
    string username;
    cout << "Enter username to delete: ";
    cin >> username;

    if (passwordDB.erase(username)) {
        savePasswords();
        cout << "Password deleted successfully!\n";
    } else {
        cout << "No such username found!\n";
    }
}

int main() {
    loadPasswords();
    int choice;
    
    do {
        cout << "\n Secure Password Manager \n";
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
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
