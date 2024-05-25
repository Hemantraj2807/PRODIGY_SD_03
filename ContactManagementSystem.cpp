#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to represent a contact
struct Contact {
    string name;
    string phoneNumber;
    string email;
};

// Function prototypes
void addContact(vector<Contact>& contacts);
void viewContacts(const vector<Contact>& contacts);
void editContact(vector<Contact>& contacts);
void deleteContact(vector<Contact>& contacts);

int main() {
    vector<Contact> contacts; // Vector to store contacts

    char choice;
    do {
        // Display menu
        cout << "Contact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addContact(contacts);
                break;
            case '2':
                viewContacts(contacts);
                break;
            case '3':
                editContact(contacts);
                break;
            case '4':
                deleteContact(contacts);
                break;
            case '5':
                cout << "Exiting program. Goodbye !!!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}

// Function to add a new contact
void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter name: ";
    cin >> newContact.name;
    cout << "Enter phone number: ";
    cin >> newContact.phoneNumber;
    cout << "Enter email address: ";
    cin >> newContact.email;

    contacts.push_back(newContact);
    cout << "Contact added successfully." << endl;
}

// Function to view all contacts
void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to display." << endl;
    } else {
        cout << "Contact List:" << endl;
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << ", Phone: " << contact.phoneNumber << ", Email: " << contact.email << endl;
        }
    }
}

// Function to edit an existing contact
void editContact(vector<Contact>& contacts) {
    string nameToEdit;
    cout << "Enter the name of the contact you want to edit: ";
    cin >> nameToEdit;

    auto it = find_if(contacts.begin(), contacts.end(), [nameToEdit](const Contact& c) {
        return c.name == nameToEdit;
    });

    if (it != contacts.end()) {
        cout << "Enter new phone number: ";
        cin >> it->phoneNumber;
        cout << "Enter new email address: ";
        cin >> it->email;
        cout << "Contact updated successfully." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

// Function to delete a contact
void deleteContact(vector<Contact>& contacts) {
    string nameToDelete;
    cout << "Enter the name of the contact you want to delete: ";
    cin >> nameToDelete;

    auto it = remove_if(contacts.begin(), contacts.end(), [nameToDelete](const Contact& c) {
        return c.name == nameToDelete;
    });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted successfully." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}
