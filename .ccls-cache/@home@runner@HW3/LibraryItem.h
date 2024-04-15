#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

class LibraryItem {
private:
  int itemID;
  double cost;
  char status;
  int loanPeriod;

public:
  void SetItemID(int itemID);
  void SetCost(double cost);
  void SetStatus(char status);
  void SetLoanPeriod(int loanPeriod);
  void PrintInfo() const = 0;

  int GetItemID();
  double GetCost();
  char GetStatus();
  int GetLoanPeriod();



};


#endif