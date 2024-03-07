#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Book.h"
#include "Books.h"
#include "Loan.h"
#include "Loans.h"
#include "Patron.h"
#include "Patrons.h"

// Global Variables
Patrons allPatrons;
Books allBooks;
Loans allLoans;

void PrintBookMenu() {
  char choice;
  do {
    cout << "---------BOOK MANAGEMENT---------" << endl;
    cout << "What would you like to do?:" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Delete Book" << endl;
    cout << "3. Edit Book" << endl;
    cout << "4. Print All Books" << endl;
    cout << "5. Print Specific Book" << endl;
    cout << "6. Return to Main Menu" << endl;

    cin >> choice;

    switch (choice) {
    case '1':
      allBooks.AddBook();
      break;
    case '2':
      int bookID;
      cout << "Please enter the Book ID:" << endl;
      cin >> bookID;
      allBooks.DeleteBook(bookID);
      break;
    case '3':
      cout << "Please enter the Book ID:" << endl;
      cin >> bookID;
      allBooks.EditBook(bookID);
      break;
    case '4':
      allBooks.PrintAllBooks();
      break;
    case '5':
      cout << "Enter the Book ID:" << endl;
      cin >> bookID;
      allBooks.PrintSpecificBook(bookID);
      break;
    }

  } while (choice != '6');
}

void PrintPatronMenu() {
  cout << "---------PATRON MANAGEMENT---------" << endl;
  cout << "What would you like to do?:" << endl;
  cout << "1. Add Patron" << endl;
  cout << "2. Delete Patron" << endl;
  cout << "3. Edit Patron" << endl;
  cout << "4. Print All Patrons" << endl;
  cout << "5. Print Specific Patron" << endl;
  cout << "6. Return to Main Menu" << endl;
}

void PrintLoanMenu() {
  cout << "---------LOAN MANAGEMENT---------" << endl;
  cout << "What would you like to do?:" << endl;
  cout << "1. Check Out Book" << endl;
  cout << "2. Check In Book" << endl;
  cout << "3. Calculate Fines" << endl;
  cout << "4. Return to Main Menu" << endl;
}

void PrintMainMenu() {
  char choice;
  do {
    cout << "---------LIBRARY MANAGEMENT SYSTEM---------" << endl;
    cout << "What would you like to do?:" << endl;
    cout << "1. Book Management" << endl;
    cout << "2. Patron Management" << endl;
    cout << "3. Loan Management" << endl;
    cout << "4. Quit:" << endl;
    cin >> choice;
    switch (choice) {
    case '1':
      PrintBookMenu();
      break;
    case '2':
      PrintPatronMenu();
      break;
    case '3':
      PrintLoanMenu();
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
  } while (choice != '4');
}

int main() {
  char choice;
  do {
    PrintMainMenu();
    cin >> choice;
  } while (choice != '4');

  return 0;
}
