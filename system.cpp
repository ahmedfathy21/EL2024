#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phoneNumber;
    string email;

    Contact(string name, string phoneNumber, string email) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->email = email;
    }

    void updateContact(string phoneNumber, string email) {
        this->phoneNumber = phoneNumber;
        this->email = email;
    }
};

class AddressBook {
private:
    vector<Contact> contacts;

public:
    void addContact(string name, string phoneNumber, string email) {
        Contact newContact(name, phoneNumber, email);
        contacts.push_back(newContact);
        std::cout <<"Contact added successfully.\n";
    }

    void updateContact(string name, string newPhoneNumber, string newEmail) {
        for (auto& contact : contacts) {
            if (contact.name == name) {
                contact.updateContact(newPhoneNumber, newEmail);
                cout << "Contact updated successfully.\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void searchContact(string name) {
        for (auto& contact : contacts) {
            if (contact.name == name) {
                cout << "Contact details:\n";
                cout << "Name: " << contact.name << "\n";
                cout << "Phone Number: " << contact.phoneNumber << "\n";
                cout << "Email: " << contact.email << "\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }
};

int main() {
    AddressBook myAddressBook;
    int choice;
    string name, phoneNumber, email;

    while (true) {
        cout << "\nAddress Book Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Update Contact\n";
        cout << "3. Search for Contact\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phoneNumber;
                cout << "Enter email address: ";
                cin >> email;
                myAddressBook.addContact(name, phoneNumber, email);
                break;
            case 2:
                cout << "Enter the name of the contact to update: ";
                cin >> name;
               std::cout << "Enter new phone number: ";
                cin >> phoneNumber;
                cout << " new email address: ";
                cin >> email;
                myAddressBook.updateContact(name, phoneNumber, email);
                break;
            case 3:
                cout << "Enter the name of the contact to search: ";
                cin >> name;
                myAddressBook.searchContact(name);
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice, please choose again.\n";
        }
    }

    return 0;
}