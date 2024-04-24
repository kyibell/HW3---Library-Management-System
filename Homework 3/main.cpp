#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Book.h"
#include "Loan.h"
#include "Loans.h"
#include "Patron.h"
#include "Patrons.h"
#include "LibraryItem.h"
#include "ItemCollection.h"

// Global Variables
Patrons allPatrons;
ItemCollection allItems;
Loans allLoans;

void PrintItemMenu() { //Item Menu
  char choice;
  do {
    cout << "---------ITEM MANAGEMENT---------" << endl;
    cout << "What would you like to do?:" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Delete Item" << endl;
    cout << "3. Edit Item" << endl;
    cout << "4. Print All Items" << endl;
    cout << "5. Print Specific Item" << endl;
    cout << "6. Return to Main Menu" << endl;

    cin >> choice;

    switch (choice) {
    case '1':
      allItems.AddItem();
      break;
    case '2':
      int itemID;
      cout << "Please enter the Item ID:" << endl;
      cin >> itemID;
      allItems.DeleteItem(itemID);
      break;
    case '3':
      cout << "Please enter the Item ID:" << endl;
      cin >> itemID;
      allItems.EditItem(itemID);
      break;
    case '4':
      allItems.PrintAllItems();
      break;
    case '5':
      cout << "Enter the Item ID:" << endl;
      cin >> itemID;
      allItems.PrintSpecificItem(itemID);
      break;
    }

  } while (choice != '6');
}

void PrintPatronMenu() { //Patron Menu
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

void PrintLoanMenu() { //Loans Menu
  char choice;
  do {
    cout << "---------LOAN MANAGEMENT---------" << endl;
    cout << "What would you like to do?:" << endl;
    cout << "1. Check Out Item" << endl;
    cout << "2. Check In Item" << endl;
    cout << "3. Check Due Dates" << endl;
    cout << "4. List Overdue Items" << endl;
    cout << "5. List Items for Patron" << endl;
    cout << "6. Update Loan Status" << endl;
    cout << "7. Recheck Item" << endl;
    cout << "8. Report Lost Item" << endl;
    cout << "9. Return to Main Menu" << endl;

    cin >> choice;
    cin.ignore();

    switch (choice) {
    case '1':
      int LoanID;
      cout << "Check Out Item" << endl;
      cout << "Please enter LoanID:" << endl;
      cin >> LoanID;
      allLoans.CheckOutBook(LoanID, allPatrons, allItems);
      break;
    case '2':
      cout << "Check In Item" << endl;
      cout << "Please enter LoanID:" << endl;
      cin >> LoanID;
      allLoans.CheckInBook(LoanID, allPatrons, allItems);

      break;
    case '3':
      cout << "Check Due Dates" << endl;
      allLoans.CheckDueDates(allPatrons);
      cout << "Due Dates Updated and Fines updated Sucessfully." << endl;
      break;
    case '4':
      cout << "List Overdue Items" << endl;
      allLoans.ListOverdueBooks();
      break;
    case '5':
      cout << "List Items for Patron" << endl;
      int PatronID;
      cout << "Please enter Patron ID:" << endl;
      cin >> PatronID;
      allLoans.ListBooksForPatron(PatronID);
      break;
    case '6':
      cout << "Update Loan Status" << endl;
      cout << "Please enter LoanID:" << endl;
      cin >> LoanID;
      allLoans.UpdateLoanStatus(LoanID);
      break;
    case '7':
      cout << "Recheck Item" << endl;
      cout << "Please enter LoanID:" << endl;
      cin >> LoanID;
      allLoans.RecheckBook(LoanID, allPatrons, allItems);
      break;
    case '8':
      cout << "Report Lost Book" << endl;
      cout << "Please enter LoanID:" << endl;
      cin >> LoanID;
      allLoans.ReportLost(LoanID, allPatrons, allItems);
      break;
    case '9':
      break;
    default:
      cout << "Invalid opinon. Please try again." << endl;
    }
  } while (choice != '9');
}

void PrintMainMenu() { //Main Menu
  char choice;
  do {
    cout << "---------LIBRARY MANAGEMENT SYSTEM---------" << endl;
    cout << "What would you like to do?:" << endl;
    cout << "1. Item Management" << endl;
    cout << "2. Patron Management" << endl;
    cout << "3. Loan Management" << endl;
    cout << "4. Quit:" << endl;
    cin >> choice;
    switch (choice) {
    case '1':
      PrintItemMenu();
      break;
    case '2':
      PrintPatronMenu();
      break;
    case '3':
      PrintLoanMenu();
      break;
    case '4':
      cout << "Exiting Library Management System. Goodbye!" << endl;
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

    if (choice == '4') {
      break;
    }
    else {
      PrintMainMenu();
      cin >> choice;
    }
  } while (choice != '4');



  return 0;
}
