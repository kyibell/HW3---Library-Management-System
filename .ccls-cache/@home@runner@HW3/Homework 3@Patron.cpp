#include <iostream>
#include <string>
using namespace std;

#include "Patron.h"

// Default Constructor
Patron::Patron() {
  this->name = "Unknown";
  this->IDnumber = 0;
  this->fines = 0.0;
  this->outbooks = 0;
}
// Initialized Constructor
Patron::Patron(string name, int IDnumber, double fines, int outbooks) {
  this->name = name;
  this->IDnumber = IDnumber;
  this->fines = fines;
  this->outbooks = outbooks;
}
// Setters
void Patron::SetName(string name) { this->name = name; }

void Patron::SetIDNum(int IDnumber) { this->IDnumber = IDnumber; }
void Patron::SetFineBalance(double fines) { this->fines = fines; }
void Patron::SetCheckedOutBooks(int outbooks) { this->outbooks = outbooks; }

// Getters

string Patron::GetName() const { return name; }
int Patron::GetIDNum() const { return IDnumber; }
double Patron::GetFineBalance() const { return fines; }
int Patron::GetOutBooks() const { return outbooks; }

//Print Patron

void Patron::PrintPatron(Patron patron) {
  cout << "Name:" << patron.GetName() << endl;
  cout << "ID Number:" << patron.GetIDNum() << endl;
  cout << "Fine Balance:" << patron.GetFineBalance() << endl;
  cout << "Number of Out Books:" << patron.GetOutBooks() << endl;
}
