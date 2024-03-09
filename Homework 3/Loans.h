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
  void CheckOutBook(int LoanID, Patrons &allpatrons, Books &allBooks);
  void CheckDueDates(Patrons allPatrons);
  void CheckInBook(int LoanID, Patrons &allpatrons, Books &allBooks);
  void ListOverdueBooks();
  void ListBooksForPatron(int PatronID);
  void UpdateLoanStatus(int LoanID);
  void RecheckBook(int LoanID, Patrons &allPatrons, Books &allBooks);
  void ReportLost(int LoanID, Patrons &allPatrons, Books &allBooks);

private:
  vector<Loan> LoansList;

};

#endif