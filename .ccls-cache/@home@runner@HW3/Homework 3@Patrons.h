#ifndef PATRONS_H
#define PATRONS_H

#include "Patron.h"
#include <string>
#include <vector>

class Patrons {
public:
  void AddPatron();
  void DeletePatron(int PatronID);
  void EditPatron(int PatronID);
  void EditPatronDetails(Patron& patron);
  Patron* FindPatron(int PatronID);
  void PrintPatrons();
  void PrintSpecificPatron(int PatronID);
  void PayFines(int PatronID);

private:
  vector<Patron> patronsList;
};

#endif