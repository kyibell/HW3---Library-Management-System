#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#include "Loan.h"
#include "Loans.h"

void Loans::CheckOutBook(Patron patron, Book book) {
  int LoanID;
  time_t dueDate;
  if (patron.GetOutBooks() >= 6) {
    cout << "Patron has reached the maximum number of books allowed." << endl;
  } else {
    patron.SetCheckedOutBooks(patron.GetOutBooks() + 1); // Increment the number of out books
    book.SetStatus('O'); // Set Status to "Out"
    Loan newLoan = Loan(LoanID,patron.GetIDNum(), book.GetLibraryID(), dueDate, book.GetStatus());

    LoansList.push_back(newLoan);
  }
}

void Loans::CheckInBook(int LoanID, Book book, Patron patron) {
  for (int i = 0; i < LoansList.size(); i++) {
    if (LoansList.at(i).GetLoanID() == LoanID) {
      LoansList.erase(LoansList.begin() + i); {
        patron.SetCheckedOutBooks(patron.GetOutBooks() - 1); //Decrment the number of out books
        book.SetStatus('I'); //Set Status to "In"
        
      }
    }
  }
}
