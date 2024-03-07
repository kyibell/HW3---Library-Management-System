#ifndef LOANS_H
#define LOANS_H

#include "Loan.h"
#include "Patron.h"
#include "Patrons.h"
#include "Book.h"
#include "Books.h"
#include <string>
#include <vector>

class Loans {
public:
  void CheckOutBook(Patron patron, Book book);
  void CalculateFines(int patronID, time_t currentDate);
  void CheckInBook(int LoanID, Book book, Patron patron);
  void ListOverdueBooks();
  void ListBooksForPatron(int PatronID);
  void UpdateLoanStatus(Loan loan);
  void RecheckBook(Loan loan);
  void EditLoan(Loan loan);
  void ReportLost(Loan loan);

private:
  vector<Loan> LoansList;

};

#endif