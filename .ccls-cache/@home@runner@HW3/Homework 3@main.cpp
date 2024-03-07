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
  char choice;
  int PatronID;
  do {
    cout << "---------PATRON MANAGEMENT---------" << endl;
    cout << "What would you like to do?:" << endl;
    cout << "1. Add Patron" << endl;
    cout << "2. Delete Patron" << endl;
    cout << "3. Edit Patron" << endl;
    cout << "4. Print All Patrons" << endl;
    cout << "5. Print Specific Patron" << endl;
    cout << "6. Pay Fines" << endl;
    cout << "7. Return to Main Menu" << endl;

    cin >> choice;
    switch (choice) {
    case '1':
      allPatrons.AddPatron();
      break;
    case '2':
      cout << "Please enter the Patron ID that you want to delete:" << endl;
      cin >> PatronID;
      allPatrons.DeletePatron(PatronID);
      break;
    case '3':
      cout << "Please enter the Patron ID that you want to edit:" << endl;
      cin >> PatronID;
      allPatrons.EditPatron(PatronID);
      break;
    case '4':
      allPatrons.PrintPatrons();
      break;
    case '5':
      cout << "Please enter the Patron ID that you want to print:" << endl;
      cin >> PatronID;
      allPatrons.PrintSpecificPatron(PatronID);
      break;
    case '6':
      cout << "Please enter the Patron ID that you want to pay fines:" << endl;
      cin >> PatronID;
      allPatrons.PayFines(PatronID);
    case '7':
      break;
    default:
      cout << "Invalid opinon. Please try again." << endl;
    }
  } while (choice != '7');
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
    case '4':
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
