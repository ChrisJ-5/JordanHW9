// File Name: PhoneBook.h

#include"Record.h"
#include<string>
using namespace std;
#define MAXSIZE 100

class PhoneBook {
  private:
    Record list[MAXSIZE];
    string bookName;
    int num_records;
    int findName(string s);
  public:
    PhoneBook();
    PhoneBook(string s);
    string getPhoneBookName();
    int getNumberofRecords();
    void insert(string name, int number);
    void displayPhoneBook();
    void removeName(string s);
    int getPhoneNumber(string s);
};
