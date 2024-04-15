#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

class LibraryItem {
private:
  int itemID;
  double cost;
  char status;
  int loanPeriod;

public:
//Constructors
  LibraryItem();
  LibraryItem(int itemID, double cost, char status, int loanPeriod);

//Library Item Setters
  void SetItemID(int itemID);
  void SetCost(double cost);
  void SetStatus(char status);
  void SetLoanPeriod(int loanPeriod);
  
//Library Item Getters
  int GetItemID() const;
  double GetCost() const;
  char GetStatus() const;
  int GetLoanPeriod() const;

//Print Info function
virtual void PrintInfo() const = 0;


};


#endif