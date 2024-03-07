#ifndef PATRON_H
#define PATRON_H

#include <string>
using namespace std;

class Patron {
public:
  Patron();
  Patron(string name, int IDnumber, double fines, int outBooks);

  void SetName(string name);
  void SetIDNum(int IDnumber);
  void SetFineBalance(double fines);
  void SetCheckedOutBooks(int outbooks);
  void PrintPatron(Patron patron);

  string GetName() const;
  int GetIDNum() const;
  double GetFineBalance() const;
  int GetOutBooks() const;

private:
  string name;
  int IDnumber;
  double fines;
  int outbooks;
};

#endif