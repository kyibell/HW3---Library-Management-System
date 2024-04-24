#ifndef LOANS_H
#define LOANS_H

#include "Loan.h"
#include "Patron.h"
#include "Patrons.h"
#include "LibraryItem.h"
#include "ItemCollection.h"
#include <string>
#include <vector>

class Loans {
public:
  void CheckOutBook(int LoanID, Patrons &allpatrons, ItemCollection &allItems);
  void CheckDueDates(Patrons allPatrons);
  void CheckInBook(int LoanID, Patrons &allpatrons, ItemCollection &allItems);
  void ListOverdueBooks();
  void ListBooksForPatron(int PatronID);
  void UpdateLoanStatus(int LoanID);
  void RecheckBook(int LoanID, Patrons &allPatrons, ItemCollection &allItems);
  void ReportLost(int LoanID, Patrons &allPatrons, ItemCollection &allItems);

private:
  vector<Loan> LoansList;

};

#endif