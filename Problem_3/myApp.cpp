// File Name: myApp.cpp

//#include"Record.h"
#include"PhoneBook.h"
#include<iostream>
using namespace std;

int main() {
  PhoneBook phoneBook("My Contacts");
  int choice;
    while (true) {
    // Display menu
    cout << "\nPhone Book Menu:\n";
    cout << "1. Insert a name and number.\n";
    cout << "2. Get a number for a person.\n";
    cout << "3. Display phone book.\n";
    cout << "4. Remove a person from the phone book.\n";
    cout << "5. Quit.\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    if (choice == 1) {
      string name;
      int number;
      cout << "Enter name: ";
      cin >> name;
      cout << "Enter number: ";
      cin >> number;
      phoneBook.insert(name, number);
      cout <<"Record inserted.\n";
    } 
    else if (choice == 2) {
      string name;
      cout << "Enter name to look up: ";
      cin >> name;
      int number = phoneBook.getPhoneNumber(name);
      if (number !=-1) {
        cout << "Number for " << name << ":" << number << endl;
      } 
      else {
        cout << "Name not found. /n";
      }
    }
    else if (choice == 3) {
      phoneBook.displayPhoneBook();
    }

    else if (choice == 4) {
      string name;
      cout << "Enter name to remove: ";
      cin >> name;
      phoneBook.removeName(name);
      cout << "Record Removed\n" << endl;
    }
    else if (choice == 5) {
      cout << "Exiting the program.\n";
      break;
    }

    else {
     cout << "Invalid command\n" << endl;
    }
  }
}


    
