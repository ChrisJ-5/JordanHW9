// File Name: PhoneBook.cpp

#include"PhoneBook.h"
#include<string>
#include<iostream>
using namespace std;

PhoneBook::PhoneBook() : num_records(0) {}

PhoneBook::PhoneBook(string s) : bookName(s), num_records(0) {}

string PhoneBook::getPhoneBookName() {
  return bookName;
}

int PhoneBook::getNumberofRecords() {
  return num_records;
}

void PhoneBook::insert(std::string name, int number) {
  if (num_records < MAXSIZE) {
    list[num_records] = Record(name, number);
    num_records++;
  } else {
    cout  << "PhoneBook is full. Cannot insert  more records." << endl;
    }
}

int PhoneBook::findName(string s) {
  for (int i = 0; i < num_records; i++) {
    if (list[i].getName() == s) {
      return i;
    }  
  }
  cout << "Name not found." << endl;
  return 99;
}

void PhoneBook::displayPhoneBook() {
  cout << "PhoneBook: " << bookName << endl;
  for (int i = 0; i < num_records; i++) {
    cout << list[i].getName() << ": " << list[i].getNumber() << endl;
  }
}

void PhoneBook::removeName(string s) {
  int index = findName(s);
  // Shift elements to remove the record
  for (int i = index; i < num_records - 1; i++) {
    list[i] = list[i + 1];
  }
  num_records--; // Decrease the count of records
  cout << "deleted record" << endl;
}

int PhoneBook::getPhoneNumber(string s) {
  int index = findName(s);
  return list[index].getNumber(); // Return the number if found
}
