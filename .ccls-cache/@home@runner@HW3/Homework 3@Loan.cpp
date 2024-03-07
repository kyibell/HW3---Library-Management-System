#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#include "Loan.h"

// Default Constructor
Loan::Loan() {
  this->LoanID = 0;
  this->BookID = 0;
  this->PatronID = 0;
  this->currentStatus = 'U';
  this->dueDate = 'U';
}
// Initialized Constructor
Loan::Loan(int LoanID, int BookID, int PatronID, time_t dueDate,
           char currentStatus) {
  this->LoanID = LoanID;
  this->BookID = BookID;
  this->PatronID = PatronID;
  this->dueDate = dueDate;
  this->currentStatus = currentStatus;
}
// Setters
void Loan::SetLoanID(int LoanID) { this->LoanID = LoanID; }
void Loan::SetBookID(int BookID) { this->BookID = BookID; }
void Loan::SetPatronID(int PatronID) { this->PatronID = PatronID; }
void Loan::SetDueDate(time_t dueDate) { this->dueDate = dueDate; }
void Loan::SetLoanStatus(char LoanStatus) { this->currentStatus = LoanStatus; }

// Getters
int Loan::GetLoanID() const { return LoanID; }

int Loan::GetBookID() const { return BookID; }
int Loan::GetPatronID() const { return PatronID; }
time_t Loan::GetDueDate() const { return dueDate; }
char Loan::GetLoanStatus() const { return currentStatus; }