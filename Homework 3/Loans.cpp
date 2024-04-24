#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#include "Loan.h"
#include "Loans.h"

void Loans::CheckOutBook(int LoanID, Patrons &allpatrons, ItemCollection &allItems) {
  int PatronID, itemID;
  cout << "Please enter the Patron's ID:" << endl;
  cin >> PatronID;
  cout << "Please enter the Item's ID:" << endl;
  cin >> itemID;

  Patron *foundpatron = allpatrons.FindPatron(PatronID);
  LibraryItem *founditem = allItems.FindItem(itemID);

  LibraryItem &item = *founditem;
  Patron &patron = *foundpatron;

  if (patron.GetOutBooks() >= 6) {
    cout << "Patron has reached the maximum number of items allowed." << endl;
  } else {
    time_t dueDate =
        time(0) + 10 * 24 * 60 * 60; // 10 days after the book is checked out
    patron.SetCheckedOutBooks(patron.GetOutBooks() +
                              1); // Increment the number of out books
    item.SetStatus('O');          // Set Status to "Out"
    Loan newLoan = Loan(LoanID, patron.GetIDNum(), item.GetItemID(), dueDate,
                        'N');     // Create a new loan object
    LoansList.push_back(newLoan); // Add loan to LoansList
    cout << "Book checked out successfully." << endl;
  }
}

void Loans::CheckInBook(int LoanID, Patrons &allPatrons, ItemCollection &allItems) {
  int PatronID, itemID;
  cout << "Please enter the Patron's ID:" << endl;
  cin >> PatronID;
  cout << "Please enter the Item's ID:" << endl;
  cin >> itemID;

  Patron *foundpatron = allPatrons.FindPatron(PatronID);
  LibraryItem *founditem = allItems.FindItem(itemID);

  LibraryItem &item = *founditem; // Dereferenced Pointers
  Patron &patron = *foundpatron;

  for (int i = 0; i < LoansList.size(); i++) {
    if (LoansList.at(i).GetLoanID() == LoanID) {
      LoansList.erase(LoansList.begin() + i);
      patron.SetCheckedOutBooks(patron.GetOutBooks() -
                                1); // Decrment the number of out books
      item.SetStatus('I');          // Set Status to "In"
      cout << "Book checked in successfully." << endl;
      break;
    } else {
      cout << "Loan not found. Please try again." << endl;
    }
  }
}

void Loans::CheckDueDates(Patrons allPatrons) {
  time_t currentTime = time(0);
  const double FINE_AMOUNT = 0.25; // Fine amount per day
  for (int i = 0; i < LoansList.size(); i++) {
    time_t dueDate = LoansList.at(i).GetDueDate();
    double secondsSinceDue = difftime(currentTime, dueDate);
    double daysSinceDue = secondsSinceDue / (60 * 60 * 24);

    if (daysSinceDue > 10) {
      double fineAmount =
          FINE_AMOUNT * (daysSinceDue - 10); // Charges 0.25 per day overdue

      // Update Patron Fines
      Patron patron;
      allPatrons.FindPatron(LoansList.at(i).GetPatronID());
      if (patron.GetIDNum() != 0) {
        patron.SetFineBalance(patron.GetFineBalance() + fineAmount);
      }
    }
  }
}

void Loans::ListOverdueBooks() {
  time_t currentTime = time(0);
  for (int i = 0; i < LoansList.size(); i++) {
    time_t dueDate = LoansList.at(i).GetDueDate();
    double secondsSinceDue = difftime(currentTime, dueDate);
    double daysSinceDue =
        secondsSinceDue / (60 * 60 * 24); // converts seconds to days
    if (daysSinceDue > 0) {
      LoansList.at(i).PrintLoan(LoansList.at(i));
    }
  }
}

void Loans::ListBooksForPatron(int PatronID) {
  for (int i = 0; i < LoansList.size(); i++) {
    if (LoansList.at(i).GetPatronID() == PatronID) {
      LoansList.at(i).PrintLoan(LoansList.at(i));
      break;
    } else {
      cout << "Patron not found. Please try again." << endl;
    }
  }
}

void Loans::UpdateLoanStatus(int LoanID) {
  for (int i = 0; i < LoansList.size(); i++) {
    if (LoansList.at(i).GetLoanID() == LoanID) {
      LoansList.at(i).SetLoanStatus('N'); // Set status to "Normal"
      break;
    } else {
      cout << "Loan not found. Please try again." << endl;
    }
  }
}
void Loans::RecheckBook(int LoanID, Patrons &allPatrons, ItemCollection &allItems) {
  int PatronID, itemID;
  cout << "Please enter the Patron's ID:" << endl;
  cin >> PatronID;
  cout << "Please enter the Item's ID:" << endl;
  cin >> itemID;
  Patron *foundpatron = allPatrons.FindPatron(PatronID);
  LibraryItem *founditem = allItems.FindItem(itemID);

  LibraryItem &item = *founditem;
  Patron &patron = *foundpatron;

  for (int i = 0; i < LoansList.size(); i++) {
    if (LoansList.at(i).GetLoanID() == LoanID) {
      if (LoansList.at(i).GetDueDate() ==
          time(0) +
              10 * 24 * 60 * 60) { // Checks if date has already been increased
        cout << "This book has already been rechecked once and cannot be "
                "rechecked again."
             << endl;
      } else { // else rechecks the book
        LoansList.at(i).SetDueDate(time(0) + 10 * 24 * 60 * 60);
        cout << "Book rechecked successfully." << endl;
      }
      break;
    }
  }
}

void Loans::ReportLost(int LoanID, Patrons &allPatrons, ItemCollection &allItems) {
  int PatronID, itemID;
  cout << "Please enter the Patron's ID:" << endl;
  cin >> PatronID;
  cout << "Please enter the Item's ID:" << endl;
  cin >> itemID;

  Patron *foundpatron = allPatrons.FindPatron(PatronID);
  LibraryItem *founditem = allItems.FindItem(itemID);

  LibraryItem &item = *founditem;
  Patron &patron = *foundpatron;

  for (int i = 0; i < LoansList.size(); i++) {
    if (LoansList.at(i).GetLoanID() == LoanID) {
      LoansList.erase(LoansList.begin() + i);
      item.SetStatus('L'); // Set status to "Lost"
      patron.SetFineBalance(
          patron.GetFineBalance() +
          item.GetCost()); // Adds book cost to patron's fine balance
      break;
    }
  }
}