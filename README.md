Project: Secure Password Manager
Objective
The Secure Password Manager is a C++-based application that allows users to store, retrieve, and manage passwords securely. It uses SHA-256 hashing for password protection and implements file-based storage to maintain persistence. This project introduces basic cybersecurity concepts such as data encryption, secure storage, and user authentication.

Features
Secure Storage: Uses SHA-256 hashing to store passwords in an encrypted format.
User Authentication: Allows users to store passwords linked to their usernames securely.
File-Based Data Management: Stores hashed passwords in a file to maintain persistence across sessions.
Basic User Interface: Provides a simple console-based menu for managing passwords.
CRUD Operations: Supports adding, retrieving, and deleting stored passwords.
Technology Stack
Programming Language: C++
Libraries Used: OpenSSL (for SHA-256 hashing), File Handling in C++
Tools Required: g++ compiler, OpenSSL library
Implementation Overview
User Inputs: The user provides a username and password.
Password Hashing: The application converts the password into a SHA-256 hash before storing it.
Data Storage: The username and hashed password are stored in a text file.
Password Retrieval: The user can retrieve their hashed password based on the username.
Deletion Mechanism: Users can remove stored credentials from the file.
Security Aspects
Uses SHA-256 hashing, ensuring passwords are never stored in plain text.
File-based storage prevents passwords from being stored directly in RAM.
No decryption method is provided, making it resilient to brute-force attacks.
Future Enhancements
Implementing AES encryption for enhanced security.
Adding a graphical user interface for better usability.
Introducing multi-factor authentication (MFA) for improved access control.
This project serves as an introductory cybersecurity tool, demonstrating secure password handling using C++ and OpenSSL.
