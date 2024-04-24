#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <time.h>

using namespace std;

class Loan {
public:
  Loan();
  Loan(int LoanID, int BookID, int PatronID, time_t dueDate,
       char currentStatus);

  void SetLoanID(int loanID);
  void SetBookID(int BookID);
  void SetPatronID(int PatronID);
  void SetDueDate(time_t dueDate);
  void SetLoanStatus(char currentStatus);

  int GetLoanID() const;
  int GetBookID() const;
  int GetPatronID() const;
  time_t GetDueDate() const;
  char GetLoanStatus() const;
  void PrintLoan(Loan loan);

private:
  int LoanID;
  int BookID;
  int PatronID;
  time_t dueDate;
  char currentStatus;
};

#endif